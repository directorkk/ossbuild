% ClassName
GstBaseSink
% TYPE_CLASS_NAME
GST_TYPE_BASE_SINK
% pkg-config
gstreamer-base-0.10
% includes
#include <gst/base/gstbasesink.h>
% prototypes
static GstCaps *gst_replace_get_caps (GstBaseSink * sink);
static gboolean gst_replace_set_caps (GstBaseSink * sink, GstCaps * caps);
static GstFlowReturn
gst_replace_buffer_alloc (GstBaseSink * sink, guint64 offset, guint size,
    GstCaps * caps, GstBuffer ** buf);
static void
gst_replace_get_times (GstBaseSink * sink, GstBuffer * buffer,
    GstClockTime * start, GstClockTime * end);
static gboolean gst_replace_start (GstBaseSink * sink);
static gboolean gst_replace_stop (GstBaseSink * sink);
static gboolean gst_replace_unlock (GstBaseSink * sink);
static gboolean gst_replace_event (GstBaseSink * sink, GstEvent * event);
static GstFlowReturn
gst_replace_preroll (GstBaseSink * sink, GstBuffer * buffer);
static GstFlowReturn
gst_replace_render (GstBaseSink * sink, GstBuffer * buffer);
static GstStateChangeReturn gst_replace_async_play (GstBaseSink * sink);
static gboolean gst_replace_activate_pull (GstBaseSink * sink, gboolean active);
static void gst_replace_fixate (GstBaseSink * sink, GstCaps * caps);
static gboolean gst_replace_unlock_stop (GstBaseSink * sink);
static GstFlowReturn
gst_replace_render_list (GstBaseSink * sink, GstBufferList * buffer_list);
% declare-class
  GstBaseSinkClass *base_sink_class = GST_BASE_SINK_CLASS (klass);
% set-methods
  base_sink_class->get_caps = GST_DEBUG_FUNCPTR (gst_replace_get_caps);
  base_sink_class->set_caps = GST_DEBUG_FUNCPTR (gst_replace_set_caps);
  base_sink_class->buffer_alloc = GST_DEBUG_FUNCPTR (gst_replace_buffer_alloc);
  base_sink_class->get_times = GST_DEBUG_FUNCPTR (gst_replace_get_times);
  base_sink_class->start = GST_DEBUG_FUNCPTR (gst_replace_start);
  base_sink_class->stop = GST_DEBUG_FUNCPTR (gst_replace_stop);
  base_sink_class->unlock = GST_DEBUG_FUNCPTR (gst_replace_unlock);
  base_sink_class->event = GST_DEBUG_FUNCPTR (gst_replace_event);
  base_sink_class->preroll = GST_DEBUG_FUNCPTR (gst_replace_preroll);
  base_sink_class->render = GST_DEBUG_FUNCPTR (gst_replace_render);
  base_sink_class->async_play = GST_DEBUG_FUNCPTR (gst_replace_async_play);
  base_sink_class->activate_pull = GST_DEBUG_FUNCPTR (gst_replace_activate_pull);
  base_sink_class->fixate = GST_DEBUG_FUNCPTR (gst_replace_fixate);
  base_sink_class->unlock_stop = GST_DEBUG_FUNCPTR (gst_replace_unlock_stop);
  base_sink_class->render_list = GST_DEBUG_FUNCPTR (gst_replace_render_list);
% methods


static GstCaps *
gst_replace_get_caps (GstBaseSink * sink)
{

  return NULL;
}

static gboolean
gst_replace_set_caps (GstBaseSink * sink, GstCaps * caps)
{

  return FALSE;
}

static GstFlowReturn
gst_replace_buffer_alloc (GstBaseSink * sink, guint64 offset, guint size,
    GstCaps * caps, GstBuffer ** buf)
{

  return GST_FLOW_ERROR;
}

static void
gst_replace_get_times (GstBaseSink * sink, GstBuffer * buffer,
    GstClockTime * start, GstClockTime * end)
{

}

static gboolean
gst_replace_start (GstBaseSink * sink)
{

  return TRUE;
}

static gboolean
gst_replace_stop (GstBaseSink * sink)
{

  return TRUE;
}

static gboolean
gst_replace_unlock (GstBaseSink * sink)
{

  return TRUE;
}

static gboolean
gst_replace_event (GstBaseSink * sink, GstEvent * event)
{

  return TRUE;
}

static GstFlowReturn
gst_replace_preroll (GstBaseSink * sink, GstBuffer * buffer)
{

  return GST_FLOW_OK;
}

static GstFlowReturn
gst_replace_render (GstBaseSink * sink, GstBuffer * buffer)
{

  return GST_FLOW_OK;
}

static GstStateChangeReturn
gst_replace_async_play (GstBaseSink * sink)
{

  return GST_STATE_CHANGE_SUCCESS;
}

static gboolean
gst_replace_activate_pull (GstBaseSink * sink, gboolean active)
{

  return TRUE;
}

static void
gst_replace_fixate (GstBaseSink * sink, GstCaps * caps)
{

}

static gboolean
gst_replace_unlock_stop (GstBaseSink * sink)
{

  return TRUE;
}

static GstFlowReturn
gst_replace_render_list (GstBaseSink * sink, GstBufferList * buffer_list)
{

  return GST_FLOW_OK;
}
% end



