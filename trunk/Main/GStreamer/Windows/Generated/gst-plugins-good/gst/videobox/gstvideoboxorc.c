
/* autogenerated from C:\ossbuild\Main\GStreamer\Windows\.\..\Source\gst-plugins-good\gst\videobox\gstvideoboxorc.orc */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifndef DISABLE_ORC
#include <orc/orc.h>
#else
#include <stdint.h>
#endif
#include <glib.h>

void orc_splat_u32 (guint32 * d1, int p1, int n);


/* begin Orc C target preamble */
#define ORC_CLAMP(x,a,b) ((x)<(a) ? (a) : ((x)>(b) ? (b) : (x)))
#define ORC_ABS(a) ((a)<0 ? -(a) : (a))
#define ORC_MIN(a,b) ((a)<(b) ? (a) : (b))
#define ORC_MAX(a,b) ((a)>(b) ? (a) : (b))
#define ORC_SB_MAX 127
#define ORC_SB_MIN (-1-ORC_SB_MAX)
#define ORC_UB_MAX 255
#define ORC_UB_MIN 0
#define ORC_SW_MAX 32767
#define ORC_SW_MIN (-1-ORC_SW_MAX)
#define ORC_UW_MAX 65535
#define ORC_UW_MIN 0
#define ORC_SL_MAX 2147483647
#define ORC_SL_MIN (-1-ORC_SL_MAX)
#define ORC_UL_MAX 4294967295U
#define ORC_UL_MIN 0
#define ORC_CLAMP_SB(x) ORC_CLAMP(x,ORC_SB_MIN,ORC_SB_MAX)
#define ORC_CLAMP_UB(x) ORC_CLAMP(x,ORC_UB_MIN,ORC_UB_MAX)
#define ORC_CLAMP_SW(x) ORC_CLAMP(x,ORC_SW_MIN,ORC_SW_MAX)
#define ORC_CLAMP_UW(x) ORC_CLAMP(x,ORC_UW_MIN,ORC_UW_MAX)
#define ORC_CLAMP_SL(x) ORC_CLAMP(x,ORC_SL_MIN,ORC_SL_MAX)
#define ORC_CLAMP_UL(x) ORC_CLAMP(x,ORC_UL_MIN,ORC_UL_MAX)
#define ORC_SWAP_W(x) ((((x)&0xff)<<8) | (((x)&0xff00)>>8))
#define ORC_SWAP_L(x) ((((x)&0xff)<<24) | (((x)&0xff00)<<8) | (((x)&0xff0000)>>8) | (((x)&0xff000000)>>24))
#define ORC_PTR_OFFSET(ptr,offset) ((void *)(((unsigned char *)(ptr)) + (offset)))
#define ORC_AS_FLOAT(x) (((union { int i; float f; } *)(&x))->f)
typedef union { int32_t i; float f; } orc_union32;
typedef union { int64_t i; double f; } orc_union64;
/* end Orc C target preamble */



/* orc_splat_u32 */
#ifdef DISABLE_ORC
void
orc_splat_u32 (guint32 * d1, int p1, int n){
  int i;
  orc_union32 var0;
  orc_union32 * ptr0;
  const orc_union32 var24 = { p1 };

  ptr0 = (orc_union32 *)d1;

  for (i = 0; i < n; i++) {
    /* 0: copyl */
    var0.i = var24.i;
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_orc_splat_u32 (OrcExecutor *ex)
{
  int i;
  int n = ex->n;
  orc_union32 var0;
  orc_union32 * ptr0;
  const orc_union32 var24 = *(orc_union32 *)(ex->params + 24);

  ptr0 = (orc_union32 *)ex->arrays[0];

  for (i = 0; i < n; i++) {
    /* 0: copyl */
    var0.i = var24.i;
    *ptr0 = var0;
    ptr0++;
  }

}

void
orc_splat_u32 (guint32 * d1, int p1, int n)
{
  OrcExecutor _ex, *ex = &_ex;
  static int p_inited = 0;
  static OrcProgram *p = 0;
  void (*func) (OrcExecutor *);

  if (!p_inited) {
    orc_once_mutex_lock ();
    if (!p_inited) {
      OrcCompileResult result;

      p = orc_program_new ();
      orc_program_set_name (p, "orc_splat_u32");
      orc_program_set_backup_function (p, _backup_orc_splat_u32);
      orc_program_add_destination (p, 4, "d1");
      orc_program_add_parameter (p, 4, "p1");

      orc_program_append (p, "copyl", ORC_VAR_D1, ORC_VAR_P1, ORC_VAR_D1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->params[ORC_VAR_P1] = p1;

  func = p->code_exec;
  func (ex);
}
#endif

