
#ifndef __gst_install_marshal_MARSHAL_H__
#define __gst_install_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:POINTER,BOXED */
extern void gst_install_marshal_VOID__POINTER_BOXED (GClosure     *closure,
                                                     GValue       *return_value,
                                                     guint         n_param_values,
                                                     const GValue *param_values,
                                                     gpointer      invocation_hint,
                                                     gpointer      marshal_data);

G_END_DECLS

#endif /* __gst_install_marshal_MARSHAL_H__ */

