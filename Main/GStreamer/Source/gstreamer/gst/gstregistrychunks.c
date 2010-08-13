/* GStreamer
 * Copyright (C) 2006 Josep Torra <josep@fluendo.com>
 *               2006 Mathieu Garcia <matthieu@fluendo.com>
 *               2006,2007 Stefan Kost <ensonic@users.sf.net>
 *               2008 Sebastian Dröge <slomo@circular-chaos.org>
 *               2008 Jan Schmidt <jan.schmidt@sun.com>
 *
 * gstregistrychunks.c: GstRegistryChunk helper for serialising/deserialising
 * plugin entries and features.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <gst/gst_private.h>
#include <gst/gstconfig.h>
#include <gst/gstelement.h>
#include <gst/gsttypefind.h>
#include <gst/gsttypefindfactory.h>
#include <gst/gsturi.h>
#include <gst/gstinfo.h>
#include <gst/gstenumtypes.h>
#include <gst/gstpadtemplate.h>

#include <gst/gstregistrychunks.h>

#define GST_CAT_DEFAULT GST_CAT_REGISTRY

/* count string length, but return -1 if we hit the eof */
static gint
_strnlen (const gchar * str, gint maxlen)
{
  gint len = 0;

  while (G_LIKELY (len < maxlen)) {
    if (G_UNLIKELY (str[len] == '\0'))
      return len;
    len++;
  }
  return -1;
}

/* Macros */
#define unpack_element(inptr, outptr, element, endptr, error_label) G_STMT_START{ \
  if (inptr + sizeof(element) > endptr) { \
    GST_ERROR ("Failed reading element " G_STRINGIFY (element)  \
        ". Have %d bytes need %" G_GSSIZE_FORMAT, \
        (int) (endptr - inptr), sizeof(element)); \
    goto error_label; \
  } \
  outptr = (element *) inptr; \
  inptr += sizeof (element); \
}G_STMT_END

#define unpack_const_string(inptr, outptr, endptr, error_label) G_STMT_START{\
  gint _len = _strnlen (inptr, (endptr-inptr)); \
  if (_len == -1) \
    goto error_label; \
  outptr = g_intern_string ((const gchar *)inptr); \
  inptr += _len + 1; \
}G_STMT_END

#define unpack_string(inptr, outptr, endptr, error_label)  G_STMT_START{\
  gint _len = _strnlen (inptr, (endptr-inptr)); \
  if (_len == -1) \
    goto error_label; \
  outptr = g_memdup ((gconstpointer)inptr, _len + 1); \
  inptr += _len + 1; \
}G_STMT_END

#define unpack_string_nocopy(inptr, outptr, endptr, error_label)  G_STMT_START{\
  gint _len = _strnlen (inptr, (endptr-inptr)); \
  if (_len == -1) \
    goto error_label; \
  outptr = (const gchar *)inptr; \
  inptr += _len + 1; \
}G_STMT_END

#define ALIGNMENT            (sizeof (void *))
#define alignment(_address)  (gsize)_address%ALIGNMENT
#define align(_ptr)          _ptr += (( alignment(_ptr) == 0) ? 0 : ALIGNMENT-alignment(_ptr))

void
_priv_gst_registry_chunk_free (GstRegistryChunk * chunk)
{
  if (!(chunk->flags & GST_REGISTRY_CHUNK_FLAG_CONST)) {
    if ((chunk->flags & GST_REGISTRY_CHUNK_FLAG_MALLOC))
      g_free (chunk->data);
    else
      g_slice_free1 (chunk->size, chunk->data);
  }
  g_slice_free (GstRegistryChunk, chunk);
}

/*
 * gst_registry_chunks_save_const_string:
 *
 * Store a const string in a binary chunk.
 *
 * Returns: %TRUE for success
 */
inline static gboolean
gst_registry_chunks_save_const_string (GList ** list, const gchar * str)
{
  GstRegistryChunk *chunk;

  if (G_UNLIKELY (str == NULL)) {
    GST_ERROR ("unexpected NULL string in plugin or plugin feature data");
    str = "";
  }

  chunk = g_slice_new (GstRegistryChunk);
  chunk->data = (gpointer) str;
  chunk->size = strlen ((gchar *) chunk->data) + 1;
  chunk->flags = GST_REGISTRY_CHUNK_FLAG_CONST;
  chunk->align = FALSE;
  *list = g_list_prepend (*list, chunk);
  return TRUE;
}

/*
 * gst_registry_chunks_save_string:
 *
 * Store a string in a binary chunk.
 *
 * Returns: %TRUE for success
 */
inline static gboolean
gst_registry_chunks_save_string (GList ** list, gchar * str)
{
  GstRegistryChunk *chunk;

  chunk = g_slice_new (GstRegistryChunk);
  chunk->data = str;
  chunk->size = strlen ((gchar *) chunk->data) + 1;
  chunk->flags = GST_REGISTRY_CHUNK_FLAG_MALLOC;
  chunk->align = FALSE;
  *list = g_list_prepend (*list, chunk);
  return TRUE;
}

/*
 * gst_registry_chunks_save_data:
 *
 * Store some data in a binary chunk.
 *
 * Returns: the initialized chunk
 */
inline static GstRegistryChunk *
gst_registry_chunks_make_data (gpointer data, gulong size)
{
  GstRegistryChunk *chunk;

  chunk = g_slice_new (GstRegistryChunk);
  chunk->data = data;
  chunk->size = size;
  chunk->flags = GST_REGISTRY_CHUNK_FLAG_NONE;
  chunk->align = TRUE;
  return chunk;
}


/*
 * gst_registry_chunks_save_pad_template:
 *
 * Store pad_templates in binary chunks.
 *
 * Returns: %TRUE for success
 */
static gboolean
gst_registry_chunks_save_pad_template (GList ** list,
    GstStaticPadTemplate * template)
{
  GstRegistryChunkPadTemplate *pt;
  GstRegistryChunk *chk;

  pt = g_slice_new (GstRegistryChunkPadTemplate);
  chk =
      gst_registry_chunks_make_data (pt, sizeof (GstRegistryChunkPadTemplate));

  pt->presence = template->presence;
  pt->direction = template->direction;

  /* pack pad template strings */
  gst_registry_chunks_save_const_string (list,
      (gchar *) (template->static_caps.string));
  gst_registry_chunks_save_const_string (list, template->name_template);

  *list = g_list_prepend (*list, chk);

  return TRUE;
}

/*
 * gst_registry_chunks_save_feature:
 *
 * Store features in binary chunks.
 *
 * Returns: %TRUE for success
 */
static gboolean
gst_registry_chunks_save_feature (GList ** list, GstPluginFeature * feature)
{
  const gchar *type_name = g_type_name (G_OBJECT_TYPE (feature));
  GstRegistryChunkPluginFeature *pf = NULL;
  GstRegistryChunk *chk = NULL;
  GList *walk;

  if (!type_name) {
    GST_ERROR ("NULL feature type_name, aborting.");
    return FALSE;
  }

  if (GST_IS_ELEMENT_FACTORY (feature)) {
    GstRegistryChunkElementFactory *ef;
    GstElementFactory *factory = GST_ELEMENT_FACTORY (feature);

    /* Initialize with zeroes because of struct padding and
     * valgrind complaining about copying unitialized memory
     */
    ef = g_slice_new0 (GstRegistryChunkElementFactory);
    chk =
        gst_registry_chunks_make_data (ef,
        sizeof (GstRegistryChunkElementFactory));
    ef->npadtemplates = ef->ninterfaces = ef->nuriprotocols = 0;
    pf = (GstRegistryChunkPluginFeature *) ef;

    /* save interfaces */
    for (walk = factory->interfaces; walk;
        walk = g_list_next (walk), ef->ninterfaces++) {
      gst_registry_chunks_save_const_string (list, (gchar *) walk->data);
    }
    GST_DEBUG ("Feature %s: saved %d interfaces %d pad templates",
        feature->name, ef->ninterfaces, ef->npadtemplates);

    /* save uritypes */
    if (GST_URI_TYPE_IS_VALID (factory->uri_type)) {
      if (factory->uri_protocols && *factory->uri_protocols) {
        GstRegistryChunk *subchk;
        gchar **protocol;

        subchk =
            gst_registry_chunks_make_data (&factory->uri_type,
            sizeof (factory->uri_type));
        subchk->flags = GST_REGISTRY_CHUNK_FLAG_CONST;

        protocol = factory->uri_protocols;
        while (*protocol) {
          gst_registry_chunks_save_const_string (list, *protocol++);
          ef->nuriprotocols++;
        }
        *list = g_list_prepend (*list, subchk);
        GST_DEBUG ("Saved %d UriTypes", ef->nuriprotocols);
      } else {
        g_warning ("GStreamer feature '%s' is URI handler but does not provide"
            " any protocols it can handle", feature->name);
      }
    }

    /* save pad-templates */
    for (walk = factory->staticpadtemplates; walk;
        walk = g_list_next (walk), ef->npadtemplates++) {
      GstStaticPadTemplate *template = walk->data;

      if (!gst_registry_chunks_save_pad_template (list, template)) {
        GST_ERROR ("Can't fill pad template, aborting.");
        goto fail;
      }
    }

    /* pack element factory strings */
    gst_registry_chunks_save_const_string (list, factory->details.author);
    gst_registry_chunks_save_const_string (list, factory->details.description);
    gst_registry_chunks_save_const_string (list, factory->details.klass);
    gst_registry_chunks_save_const_string (list, factory->details.longname);
  } else if (GST_IS_TYPE_FIND_FACTORY (feature)) {
    GstRegistryChunkTypeFindFactory *tff;
    GstTypeFindFactory *factory = GST_TYPE_FIND_FACTORY (feature);
    gchar *str;

    /* Initialize with zeroes because of struct padding and
     * valgrind complaining about copying unitialized memory
     */
    tff = g_slice_new0 (GstRegistryChunkTypeFindFactory);
    chk =
        gst_registry_chunks_make_data (tff,
        sizeof (GstRegistryChunkTypeFindFactory));
    tff->nextensions = 0;
    pf = (GstRegistryChunkPluginFeature *) tff;

    /* save extensions */
    if (factory->extensions) {
      while (factory->extensions[tff->nextensions]) {
        gst_registry_chunks_save_const_string (list,
            factory->extensions[tff->nextensions++]);
      }
    }
    /* save caps */
    if (factory->caps) {
      /* we copy the caps here so we can simplify them before saving. This
       * is a lot faster when loading them later on */
      GstCaps *copy = gst_caps_copy (factory->caps);

      gst_caps_do_simplify (copy);
      str = gst_caps_to_string (copy);
      gst_caps_unref (copy);
      gst_registry_chunks_save_string (list, str);
    } else {
      gst_registry_chunks_save_const_string (list, "");
    }
  } else if (GST_IS_INDEX_FACTORY (feature)) {
    GstIndexFactory *factory = GST_INDEX_FACTORY (feature);

    pf = g_slice_new (GstRegistryChunkPluginFeature);
    chk =
        gst_registry_chunks_make_data (pf,
        sizeof (GstRegistryChunkPluginFeature));

    /* pack element factory strings */
    gst_registry_chunks_save_const_string (list, factory->longdesc);
  } else {
    GST_WARNING ("unhandled feature type '%s'", type_name);
  }

  if (pf) {
    pf->rank = feature->rank;
    *list = g_list_prepend (*list, chk);

    /* pack plugin feature strings */
    gst_registry_chunks_save_const_string (list, feature->name);
    gst_registry_chunks_save_const_string (list, (gchar *) type_name);

    return TRUE;
  }

  /* Errors */
fail:
  g_free (chk);
  g_free (pf);
  return FALSE;
}

static gboolean
gst_registry_chunks_save_plugin_dep (GList ** list, GstPluginDep * dep)
{
  GstRegistryChunkDep *ed;
  GstRegistryChunk *chk;
  gchar **s;

  ed = g_slice_new (GstRegistryChunkDep);
  chk = gst_registry_chunks_make_data (ed, sizeof (GstRegistryChunkDep));

  ed->flags = dep->flags;
  ed->n_env_vars = 0;
  ed->n_paths = 0;
  ed->n_names = 0;

  ed->env_hash = dep->env_hash;
  ed->stat_hash = dep->stat_hash;

  for (s = dep->env_vars; s != NULL && *s != NULL; ++s, ++ed->n_env_vars)
    gst_registry_chunks_save_string (list, g_strdup (*s));

  for (s = dep->paths; s != NULL && *s != NULL; ++s, ++ed->n_paths)
    gst_registry_chunks_save_string (list, g_strdup (*s));

  for (s = dep->names; s != NULL && *s != NULL; ++s, ++ed->n_names)
    gst_registry_chunks_save_string (list, g_strdup (*s));

  *list = g_list_prepend (*list, chk);

  GST_LOG ("Saved external plugin dependency");
  return TRUE;
}

/*
 * _priv_gst_registry_chunks_save_plugin:
 *
 * Adapt a GstPlugin to our GstRegistryChunkPluginElement structure, and
 * prepend it as a GstRegistryChunk in the provided list.
 *
 */
gboolean
_priv_gst_registry_chunks_save_plugin (GList ** list, GstRegistry * registry,
    GstPlugin * plugin)
{
  GstRegistryChunkPluginElement *pe;
  GstRegistryChunk *chk;
  GList *plugin_features = NULL;
  GList *walk;

  pe = g_slice_new (GstRegistryChunkPluginElement);
  chk =
      gst_registry_chunks_make_data (pe,
      sizeof (GstRegistryChunkPluginElement));

  pe->file_size = plugin->file_size;
  pe->file_mtime = plugin->file_mtime;
  pe->nfeatures = 0;
  pe->n_deps = 0;

  /* pack external deps */
  for (walk = plugin->priv->deps; walk != NULL; walk = walk->next) {
    if (!gst_registry_chunks_save_plugin_dep (list, walk->data)) {
      GST_ERROR ("Could not save external plugin dependency, aborting.");
      goto fail;
    }
    ++pe->n_deps;
  }

  /* pack plugin features */
  plugin_features =
      gst_registry_get_feature_list_by_plugin (registry, plugin->desc.name);
  for (walk = plugin_features; walk; walk = g_list_next (walk), pe->nfeatures++) {
    GstPluginFeature *feature = GST_PLUGIN_FEATURE (walk->data);

    if (!gst_registry_chunks_save_feature (list, feature)) {
      GST_ERROR ("Can't fill plugin feature, aborting.");
      goto fail;
    }
  }

  gst_plugin_feature_list_free (plugin_features);

  /* pack cache data */
  if (plugin->priv->cache_data) {
    gchar *cache_str = gst_structure_to_string (plugin->priv->cache_data);
    gst_registry_chunks_save_string (list, cache_str);
  } else {
    gst_registry_chunks_save_const_string (list, "");
  }

  /* pack plugin element strings */
  gst_registry_chunks_save_const_string (list,
      (plugin->desc.release_datetime) ? plugin->desc.release_datetime : "");
  gst_registry_chunks_save_const_string (list, plugin->desc.origin);
  gst_registry_chunks_save_const_string (list, plugin->desc.package);
  gst_registry_chunks_save_const_string (list, plugin->desc.source);
  gst_registry_chunks_save_const_string (list, plugin->desc.license);
  gst_registry_chunks_save_const_string (list, plugin->desc.version);
  gst_registry_chunks_save_const_string (list, plugin->filename);
  gst_registry_chunks_save_const_string (list, plugin->desc.description);
  gst_registry_chunks_save_const_string (list, plugin->desc.name);

  *list = g_list_prepend (*list, chk);

  GST_DEBUG ("Found %d features in plugin \"%s\"", pe->nfeatures,
      plugin->desc.name);
  return TRUE;

  /* Errors */
fail:
  gst_plugin_feature_list_free (plugin_features);
  g_free (chk);
  g_free (pe);
  return FALSE;
}

/*
 * gst_registry_chunks_load_pad_template:
 *
 * Make a new GstStaticPadTemplate from current GstRegistryChunkPadTemplate
 * structure.
 *
 * Returns: new GstStaticPadTemplate
 */
static gboolean
gst_registry_chunks_load_pad_template (GstElementFactory * factory, gchar ** in,
    gchar * end)
{
  GstRegistryChunkPadTemplate *pt;
  GstStaticPadTemplate *template = NULL;

  align (*in);
  GST_DEBUG ("Reading/casting for GstRegistryChunkPadTemplate at address %p",
      *in);
  unpack_element (*in, pt, GstRegistryChunkPadTemplate, end, fail);

  template = g_slice_new (GstStaticPadTemplate);
  template->presence = pt->presence;
  template->direction = pt->direction;
  template->static_caps.caps.refcount = 0;

  /* unpack pad template strings */
  unpack_const_string (*in, template->name_template, end, fail);
  unpack_string (*in, template->static_caps.string, end, fail);

  __gst_element_factory_add_static_pad_template (factory, template);
  GST_DEBUG ("Added pad_template %s", template->name_template);

  return TRUE;
fail:
  GST_INFO ("Reading pad template failed");
  if (template)
    g_slice_free (GstStaticPadTemplate, template);
  return FALSE;
}

/*
 * gst_registry_chunks_load_feature:
 *
 * Make a new GstPluginFeature from current binary plugin feature structure
 *
 * Returns: new GstPluginFeature
 */
static gboolean
gst_registry_chunks_load_feature (GstRegistry * registry, gchar ** in,
    gchar * end, const gchar * plugin_name)
{
  GstRegistryChunkPluginFeature *pf = NULL;
  GstPluginFeature *feature = NULL;
  const gchar *const_str, *type_name;
  gchar *str, *feature_name;
  GType type;
  guint i;

  /* unpack plugin feature strings */
  unpack_string_nocopy (*in, type_name, end, fail);

  if (G_UNLIKELY (!type_name)) {
    GST_ERROR ("No feature type name");
    return FALSE;
  }

  /* unpack more plugin feature strings */
  unpack_string (*in, feature_name, end, fail);

  GST_DEBUG ("Plugin '%s' feature '%s' typename : '%s'", plugin_name,
      feature_name, type_name);

  if (G_UNLIKELY (!(type = g_type_from_name (type_name)))) {
    GST_ERROR ("Unknown type from typename '%s' for plugin '%s'", type_name,
        plugin_name);
    g_free (feature_name);
    return FALSE;
  }
  if (G_UNLIKELY ((feature = g_object_newv (type, 0, NULL)) == NULL)) {
    GST_ERROR ("Can't create feature from type");
    g_free (feature_name);
    return FALSE;
  }

  feature->name = feature_name;

  if (G_UNLIKELY (!GST_IS_PLUGIN_FEATURE (feature))) {
    GST_ERROR ("typename : '%s' is not a plugin feature", type_name);
    goto fail;
  }

  if (GST_IS_ELEMENT_FACTORY (feature)) {
    GstRegistryChunkElementFactory *ef;
    guint n;
    GstElementFactory *factory = GST_ELEMENT_FACTORY_CAST (feature);

    align (*in);
    GST_LOG ("Reading/casting for GstRegistryChunkElementFactory at address %p",
        *in);
    unpack_element (*in, ef, GstRegistryChunkElementFactory, end, fail);
    pf = (GstRegistryChunkPluginFeature *) ef;

    /* unpack element factory strings */
    unpack_string (*in, factory->details.longname, end, fail);
    unpack_string (*in, factory->details.klass, end, fail);
    unpack_string (*in, factory->details.description, end, fail);
    unpack_string (*in, factory->details.author, end, fail);
    n = ef->npadtemplates;
    GST_DEBUG ("Element factory : '%s' with npadtemplates=%d",
        factory->details.longname, n);

    /* load pad templates */
    for (i = 0; i < n; i++) {
      if (G_UNLIKELY (!gst_registry_chunks_load_pad_template (factory, in,
                  end))) {
        GST_ERROR ("Error while loading binary pad template");
        goto fail;
      }
    }

    /* load uritypes */
    if (G_UNLIKELY ((n = ef->nuriprotocols))) {
      GST_DEBUG ("Reading %d UriTypes at address %p", n, *in);

      align (*in);
      factory->uri_type = *((guint *) * in);
      *in += sizeof (factory->uri_type);
      /*unpack_element(*in, &factory->uri_type, factory->uri_type, end, fail); */

      factory->uri_protocols = g_new0 (gchar *, n + 1);
      for (i = 0; i < n; i++) {
        unpack_string (*in, str, end, fail);
        factory->uri_protocols[i] = str;
      }
    }
    /* load interfaces */
    if (G_UNLIKELY ((n = ef->ninterfaces))) {
      GST_DEBUG ("Reading %d Interfaces at address %p", n, *in);
      for (i = 0; i < n; i++) {
        unpack_string_nocopy (*in, const_str, end, fail);
        __gst_element_factory_add_interface (factory, const_str);
      }
    }
  } else if (GST_IS_TYPE_FIND_FACTORY (feature)) {
    GstRegistryChunkTypeFindFactory *tff;
    GstTypeFindFactory *factory = GST_TYPE_FIND_FACTORY (feature);

    align (*in);
    GST_DEBUG
        ("Reading/casting for GstRegistryChunkPluginFeature at address %p",
        *in);
    unpack_element (*in, tff, GstRegistryChunkTypeFindFactory, end, fail);
    pf = (GstRegistryChunkPluginFeature *) tff;

    /* load typefinder caps */
    unpack_string_nocopy (*in, const_str, end, fail);
    if (const_str != NULL && *const_str != '\0')
      factory->caps = gst_caps_from_string (const_str);
    else
      factory->caps = NULL;

    /* load extensions */
    if (tff->nextensions) {
      GST_DEBUG ("Reading %d Typefind extensions at address %p",
          tff->nextensions, *in);
      factory->extensions = g_new0 (gchar *, tff->nextensions + 1);
      for (i = 0; i < tff->nextensions; i++) {
        unpack_string (*in, str, end, fail);
        factory->extensions[i] = str;
      }
    }
  } else if (GST_IS_INDEX_FACTORY (feature)) {
    GstIndexFactory *factory = GST_INDEX_FACTORY (feature);

    align (*in);
    GST_DEBUG
        ("Reading/casting for GstRegistryChunkPluginFeature at address %p",
        *in);
    unpack_element (*in, pf, GstRegistryChunkPluginFeature, end, fail);

    /* unpack index factory strings */
    unpack_string (*in, factory->longdesc, end, fail);
  } else {
    GST_WARNING ("unhandled factory type : %s", G_OBJECT_TYPE_NAME (feature));
    goto fail;
  }

  feature->rank = pf->rank;

  feature->plugin_name = plugin_name;

  gst_registry_add_feature (registry, feature);
  GST_DEBUG ("Added feature %s", feature->name);

  return TRUE;

  /* Errors */
fail:
  GST_INFO ("Reading plugin feature failed");
  if (feature) {
    if (GST_IS_OBJECT (feature))
      gst_object_unref (feature);
    else
      g_object_unref (feature);
  }
  return FALSE;
}

static gchar **
gst_registry_chunks_load_plugin_dep_strv (gchar ** in, gchar * end, guint n)
{
  gchar **arr;

  if (n == 0)
    return NULL;

  arr = g_new0 (gchar *, n + 1);
  while (n > 0) {
    unpack_string (*in, arr[n - 1], end, fail);
    --n;
  }
  return arr;
fail:
  GST_INFO ("Reading plugin dependency strings failed");
  return NULL;
}

static gboolean
gst_registry_chunks_load_plugin_dep (GstPlugin * plugin, gchar ** in,
    gchar * end)
{
  GstPluginDep *dep;
  GstRegistryChunkDep *d;
  gchar **s;

  align (*in);
  GST_LOG_OBJECT (plugin, "Unpacking GstRegistryChunkDep from %p", *in);
  unpack_element (*in, d, GstRegistryChunkDep, end, fail);

  dep = g_slice_new (GstPluginDep);

  dep->env_hash = d->env_hash;
  dep->stat_hash = d->stat_hash;

  dep->flags = d->flags;

  dep->names = gst_registry_chunks_load_plugin_dep_strv (in, end, d->n_names);
  dep->paths = gst_registry_chunks_load_plugin_dep_strv (in, end, d->n_paths);
  dep->env_vars =
      gst_registry_chunks_load_plugin_dep_strv (in, end, d->n_env_vars);

  plugin->priv->deps = g_list_append (plugin->priv->deps, dep);

  GST_DEBUG_OBJECT (plugin, "Loaded external plugin dependency from registry: "
      "env_hash: %08x, stat_hash: %08x", dep->env_hash, dep->stat_hash);
  for (s = dep->env_vars; s != NULL && *s != NULL; ++s)
    GST_LOG_OBJECT (plugin, " evar: %s", *s);
  for (s = dep->paths; s != NULL && *s != NULL; ++s)
    GST_LOG_OBJECT (plugin, " path: %s", *s);
  for (s = dep->names; s != NULL && *s != NULL; ++s)
    GST_LOG_OBJECT (plugin, " name: %s", *s);

  return TRUE;
fail:
  GST_INFO ("Reading plugin dependency failed");
  return FALSE;
}


/*
 * _priv_gst_registry_chunks_load_plugin:
 *
 * Make a new GstPlugin from current GstRegistryChunkPluginElement structure
 * and add it to the GstRegistry. Return an offset to the next
 * GstRegistryChunkPluginElement structure.
 */
gboolean
_priv_gst_registry_chunks_load_plugin (GstRegistry * registry, gchar ** in,
    gchar * end, GstPlugin ** out_plugin)
{
#ifndef GST_DISABLE_GST_DEBUG
  gchar *start = *in;
#endif
  GstRegistryChunkPluginElement *pe;
  const gchar *cache_str = NULL;
  GstPlugin *plugin = NULL;
  guint i, n;

  align (*in);
  GST_LOG ("Reading/casting for GstRegistryChunkPluginElement at address %p",
      *in);
  unpack_element (*in, pe, GstRegistryChunkPluginElement, end, fail);

  plugin = g_object_newv (GST_TYPE_PLUGIN, 0, NULL);

  /* TODO: also set GST_PLUGIN_FLAG_CONST */
  plugin->flags |= GST_PLUGIN_FLAG_CACHED;
  plugin->file_mtime = pe->file_mtime;
  plugin->file_size = pe->file_size;

  /* unpack plugin element strings */
  unpack_const_string (*in, plugin->desc.name, end, fail);
  unpack_string (*in, plugin->desc.description, end, fail);
  unpack_string (*in, plugin->filename, end, fail);
  unpack_const_string (*in, plugin->desc.version, end, fail);
  unpack_const_string (*in, plugin->desc.license, end, fail);
  unpack_const_string (*in, plugin->desc.source, end, fail);
  unpack_const_string (*in, plugin->desc.package, end, fail);
  unpack_const_string (*in, plugin->desc.origin, end, fail);
  unpack_const_string (*in, plugin->desc.release_datetime, end, fail);

  GST_LOG ("read strings for name='%s'", plugin->desc.name);
  GST_LOG ("  desc.description='%s'", plugin->desc.description);
  GST_LOG ("  filename='%s'", plugin->filename);
  GST_LOG ("  desc.version='%s'", plugin->desc.version);
  GST_LOG ("  desc.license='%s'", plugin->desc.license);
  GST_LOG ("  desc.source='%s'", plugin->desc.source);
  GST_LOG ("  desc.package='%s'", plugin->desc.package);
  GST_LOG ("  desc.origin='%s'", plugin->desc.origin);
  GST_LOG ("  desc.datetime=%s", plugin->desc.release_datetime);

  if (plugin->desc.release_datetime[0] == '\0')
    plugin->desc.release_datetime = NULL;

  /* unpack cache data */
  unpack_string_nocopy (*in, cache_str, end, fail);
  if (cache_str != NULL && *cache_str != '\0')
    plugin->priv->cache_data = gst_structure_from_string (cache_str, NULL);

  /* If the license string is 'BLACKLIST', mark this as a blacklisted
   * plugin */
  if (strcmp (plugin->desc.license, "BLACKLIST") == 0)
    plugin->flags |= GST_PLUGIN_FLAG_BLACKLISTED;

  plugin->basename = g_path_get_basename (plugin->filename);

  /* Takes ownership of plugin */
  gst_registry_add_plugin (registry, plugin);
  n = pe->nfeatures;
  GST_DEBUG ("Added plugin '%s' plugin with %d features from binary registry",
      plugin->desc.name, n);

  /* Load plugin features */
  for (i = 0; i < n; i++) {
    if (G_UNLIKELY (!gst_registry_chunks_load_feature (registry, in, end,
                plugin->desc.name))) {
      GST_ERROR ("Error while loading binary feature for plugin '%s'",
          GST_STR_NULL (plugin->desc.name));
      gst_registry_remove_plugin (registry, plugin);
      goto fail;
    }
  }

  /* Load external plugin dependencies */
  for (i = 0; i < pe->n_deps; ++i) {
    if (G_UNLIKELY (!gst_registry_chunks_load_plugin_dep (plugin, in, end))) {
      GST_ERROR_OBJECT (plugin, "Could not read external plugin dependency "
          "for plugin '%s'", GST_STR_NULL (plugin->desc.name));
      gst_registry_remove_plugin (registry, plugin);
      goto fail;
    }
  }

  if (out_plugin)
    *out_plugin = plugin;

  return TRUE;

  /* Errors */
fail:
  GST_INFO ("Reading plugin failed after %u bytes", (guint) (end - start));
  return FALSE;
}

void
_priv_gst_registry_chunks_save_global_header (GList ** list,
    GstRegistry * registry, guint32 filter_env_hash)
{
  GstRegistryChunkGlobalHeader *hdr;
  GstRegistryChunk *chk;

  hdr = g_slice_new (GstRegistryChunkGlobalHeader);
  chk = gst_registry_chunks_make_data (hdr,
      sizeof (GstRegistryChunkGlobalHeader));

  hdr->filter_env_hash = filter_env_hash;

  *list = g_list_prepend (*list, chk);

  GST_LOG ("Saved global header (filter_env_hash=0x%08x)", filter_env_hash);
}

gboolean
_priv_gst_registry_chunks_load_global_header (GstRegistry * registry,
    gchar ** in, gchar * end, guint32 * filter_env_hash)
{
  GstRegistryChunkGlobalHeader *hdr;

  align (*in);
  GST_LOG ("Reading/casting for GstRegistryChunkGlobalHeader at %p", *in);
  unpack_element (*in, hdr, GstRegistryChunkGlobalHeader, end, fail);
  *filter_env_hash = hdr->filter_env_hash;
  return TRUE;

  /* Errors */
fail:
  GST_WARNING ("Reading global header failed");
  return FALSE;
}
