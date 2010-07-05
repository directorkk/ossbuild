
/* autogenerated from C:\ossbuild\Main\GStreamer\Windows\.\..\Source\gst-plugins-good\gst\deinterlace\tvtime.orc */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifndef DISABLE_ORC
#include <orc/orc.h>
#else
#include <stdint.h>
#endif
#include <glib.h>

void deinterlace_line_vfir (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, const guint8 * s5, int n);
void deinterlace_line_linear (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void deinterlace_line_linear_blend (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);


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



/* deinterlace_line_vfir */
#ifdef DISABLE_ORC
void
deinterlace_line_vfir (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, const guint8 * s5, int n){
  int i;
  int8_t var0;
  int8_t * ptr0;
  int8_t var4;
  const int8_t * ptr4;
  int8_t var5;
  const int8_t * ptr5;
  int8_t var6;
  const int8_t * ptr6;
  int8_t var7;
  const int8_t * ptr7;
  int8_t var8;
  const int8_t * ptr8;
  const int16_t var16 = 2;
  const int16_t var17 = 1;
  const int16_t var18 = 4;
  const int16_t var19 = 3;
  int16_t var32;
  int16_t var33;
  int16_t var34;
  int16_t var35;
  int16_t var36;
  int16_t var37;
  int16_t var38;
  int16_t var39;
  int16_t var40;
  int16_t var41;
  int16_t var42;
  int16_t var43;
  int16_t var44;

  ptr0 = (int8_t *)d1;
  ptr4 = (int8_t *)s1;
  ptr5 = (int8_t *)s2;
  ptr6 = (int8_t *)s3;
  ptr7 = (int8_t *)s4;
  ptr8 = (int8_t *)s5;

  for (i = 0; i < n; i++) {
    var4 = *ptr4;
    ptr4++;
    var5 = *ptr5;
    ptr5++;
    var6 = *ptr6;
    ptr6++;
    var7 = *ptr7;
    ptr7++;
    var8 = *ptr8;
    ptr8++;
    /* 0: convubw */
    var32 = (uint8_t)var4;
    /* 1: convubw */
    var33 = (uint8_t)var8;
    /* 2: addw */
    var35 = var32 + var33;
    /* 3: convubw */
    var36 = (uint8_t)var5;
    /* 4: convubw */
    var34 = (uint8_t)var7;
    /* 5: addw */
    var37 = var36 + var34;
    /* 6: shlw */
    var38 = var37 << var16;
    /* 7: convubw */
    var39 = (uint8_t)var6;
    /* 8: shlw */
    var40 = var39 << var17;
    /* 9: subw */
    var41 = var38 - var35;
    /* 10: addw */
    var42 = var41 + var40;
    /* 11: addw */
    var43 = var42 + var18;
    /* 12: shrsw */
    var44 = var43 >> var19;
    /* 13: convsuswb */
    var0 = ORC_CLAMP_UB(var44);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_deinterlace_line_vfir (OrcExecutor *ex)
{
  int i;
  int n = ex->n;
  int8_t var0;
  int8_t * ptr0;
  int8_t var4;
  const int8_t * ptr4;
  int8_t var5;
  const int8_t * ptr5;
  int8_t var6;
  const int8_t * ptr6;
  int8_t var7;
  const int8_t * ptr7;
  int8_t var8;
  const int8_t * ptr8;
  const int16_t var16 = 2;
  const int16_t var17 = 1;
  const int16_t var18 = 4;
  const int16_t var19 = 3;
  int16_t var32;
  int16_t var33;
  int16_t var34;
  int16_t var35;
  int16_t var36;
  int16_t var37;
  int16_t var38;
  int16_t var39;
  int16_t var40;
  int16_t var41;
  int16_t var42;
  int16_t var43;
  int16_t var44;

  ptr0 = (int8_t *)ex->arrays[0];
  ptr4 = (int8_t *)ex->arrays[4];
  ptr5 = (int8_t *)ex->arrays[5];
  ptr6 = (int8_t *)ex->arrays[6];
  ptr7 = (int8_t *)ex->arrays[7];
  ptr8 = (int8_t *)ex->arrays[8];

  for (i = 0; i < n; i++) {
    var4 = *ptr4;
    ptr4++;
    var5 = *ptr5;
    ptr5++;
    var6 = *ptr6;
    ptr6++;
    var7 = *ptr7;
    ptr7++;
    var8 = *ptr8;
    ptr8++;
    /* 0: convubw */
    var32 = (uint8_t)var4;
    /* 1: convubw */
    var33 = (uint8_t)var8;
    /* 2: addw */
    var35 = var32 + var33;
    /* 3: convubw */
    var36 = (uint8_t)var5;
    /* 4: convubw */
    var34 = (uint8_t)var7;
    /* 5: addw */
    var37 = var36 + var34;
    /* 6: shlw */
    var38 = var37 << var16;
    /* 7: convubw */
    var39 = (uint8_t)var6;
    /* 8: shlw */
    var40 = var39 << var17;
    /* 9: subw */
    var41 = var38 - var35;
    /* 10: addw */
    var42 = var41 + var40;
    /* 11: addw */
    var43 = var42 + var18;
    /* 12: shrsw */
    var44 = var43 >> var19;
    /* 13: convsuswb */
    var0 = ORC_CLAMP_UB(var44);
    *ptr0 = var0;
    ptr0++;
  }

}

void
deinterlace_line_vfir (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, const guint8 * s5, int n)
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
      orc_program_set_name (p, "deinterlace_line_vfir");
      orc_program_set_backup_function (p, _backup_deinterlace_line_vfir);
      orc_program_add_destination (p, 1, "d1");
      orc_program_add_source (p, 1, "s1");
      orc_program_add_source (p, 1, "s2");
      orc_program_add_source (p, 1, "s3");
      orc_program_add_source (p, 1, "s4");
      orc_program_add_source (p, 1, "s5");
      orc_program_add_constant (p, 2, 2, "c1");
      orc_program_add_constant (p, 2, 1, "c2");
      orc_program_add_constant (p, 2, 4, "c3");
      orc_program_add_constant (p, 2, 3, "c4");
      orc_program_add_temporary (p, 2, "t1");
      orc_program_add_temporary (p, 2, "t2");
      orc_program_add_temporary (p, 2, "t3");

      orc_program_append (p, "convubw", ORC_VAR_T1, ORC_VAR_S1, ORC_VAR_D1);
      orc_program_append (p, "convubw", ORC_VAR_T2, ORC_VAR_S5, ORC_VAR_D1);
      orc_program_append (p, "addw", ORC_VAR_T1, ORC_VAR_T1, ORC_VAR_T2);
      orc_program_append (p, "convubw", ORC_VAR_T2, ORC_VAR_S2, ORC_VAR_D1);
      orc_program_append (p, "convubw", ORC_VAR_T3, ORC_VAR_S4, ORC_VAR_D1);
      orc_program_append (p, "addw", ORC_VAR_T2, ORC_VAR_T2, ORC_VAR_T3);
      orc_program_append (p, "shlw", ORC_VAR_T2, ORC_VAR_T2, ORC_VAR_C1);
      orc_program_append (p, "convubw", ORC_VAR_T3, ORC_VAR_S3, ORC_VAR_D1);
      orc_program_append (p, "shlw", ORC_VAR_T3, ORC_VAR_T3, ORC_VAR_C2);
      orc_program_append (p, "subw", ORC_VAR_T2, ORC_VAR_T2, ORC_VAR_T1);
      orc_program_append (p, "addw", ORC_VAR_T2, ORC_VAR_T2, ORC_VAR_T3);
      orc_program_append (p, "addw", ORC_VAR_T2, ORC_VAR_T2, ORC_VAR_C3);
      orc_program_append (p, "shrsw", ORC_VAR_T2, ORC_VAR_T2, ORC_VAR_C4);
      orc_program_append (p, "convsuswb", ORC_VAR_D1, ORC_VAR_T2, ORC_VAR_D1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *)s1;
  ex->arrays[ORC_VAR_S2] = (void *)s2;
  ex->arrays[ORC_VAR_S3] = (void *)s3;
  ex->arrays[ORC_VAR_S4] = (void *)s4;
  ex->arrays[ORC_VAR_S5] = (void *)s5;

  func = p->code_exec;
  func (ex);
}
#endif


/* deinterlace_line_linear */
#ifdef DISABLE_ORC
void
deinterlace_line_linear (guint8 * d1, const guint8 * s1, const guint8 * s2, int n){
  int i;
  int8_t var0;
  int8_t * ptr0;
  int8_t var4;
  const int8_t * ptr4;
  int8_t var5;
  const int8_t * ptr5;

  ptr0 = (int8_t *)d1;
  ptr4 = (int8_t *)s1;
  ptr5 = (int8_t *)s2;

  for (i = 0; i < n; i++) {
    var4 = *ptr4;
    ptr4++;
    var5 = *ptr5;
    ptr5++;
    /* 0: avgub */
    var0 = ((uint8_t)var4 + (uint8_t)var5 + 1)>>1;
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_deinterlace_line_linear (OrcExecutor *ex)
{
  int i;
  int n = ex->n;
  int8_t var0;
  int8_t * ptr0;
  int8_t var4;
  const int8_t * ptr4;
  int8_t var5;
  const int8_t * ptr5;

  ptr0 = (int8_t *)ex->arrays[0];
  ptr4 = (int8_t *)ex->arrays[4];
  ptr5 = (int8_t *)ex->arrays[5];

  for (i = 0; i < n; i++) {
    var4 = *ptr4;
    ptr4++;
    var5 = *ptr5;
    ptr5++;
    /* 0: avgub */
    var0 = ((uint8_t)var4 + (uint8_t)var5 + 1)>>1;
    *ptr0 = var0;
    ptr0++;
  }

}

void
deinterlace_line_linear (guint8 * d1, const guint8 * s1, const guint8 * s2, int n)
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
      orc_program_set_name (p, "deinterlace_line_linear");
      orc_program_set_backup_function (p, _backup_deinterlace_line_linear);
      orc_program_add_destination (p, 1, "d1");
      orc_program_add_source (p, 1, "s1");
      orc_program_add_source (p, 1, "s2");

      orc_program_append (p, "avgub", ORC_VAR_D1, ORC_VAR_S1, ORC_VAR_S2);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *)s1;
  ex->arrays[ORC_VAR_S2] = (void *)s2;

  func = p->code_exec;
  func (ex);
}
#endif


/* deinterlace_line_linear_blend */
#ifdef DISABLE_ORC
void
deinterlace_line_linear_blend (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n){
  int i;
  int8_t var0;
  int8_t * ptr0;
  int8_t var4;
  const int8_t * ptr4;
  int8_t var5;
  const int8_t * ptr5;
  int8_t var6;
  const int8_t * ptr6;
  const int16_t var16 = 2;
  const int16_t var17 = 2;
  int16_t var32;
  int16_t var33;
  int16_t var34;
  int16_t var35;
  int16_t var36;
  int16_t var37;
  int16_t var38;
  int16_t var39;

  ptr0 = (int8_t *)d1;
  ptr4 = (int8_t *)s1;
  ptr5 = (int8_t *)s2;
  ptr6 = (int8_t *)s3;

  for (i = 0; i < n; i++) {
    var4 = *ptr4;
    ptr4++;
    var5 = *ptr5;
    ptr5++;
    var6 = *ptr6;
    ptr6++;
    /* 0: convubw */
    var32 = (uint8_t)var4;
    /* 1: convubw */
    var33 = (uint8_t)var5;
    /* 2: convubw */
    var34 = (uint8_t)var6;
    /* 3: addw */
    var35 = var32 + var33;
    /* 4: addw */
    var36 = var34 + var34;
    /* 5: addw */
    var37 = var35 + var36;
    /* 6: addw */
    var38 = var37 + var16;
    /* 7: shrsw */
    var39 = var38 >> var17;
    /* 8: convsuswb */
    var0 = ORC_CLAMP_UB(var39);
    *ptr0 = var0;
    ptr0++;
  }

}

#else
static void
_backup_deinterlace_line_linear_blend (OrcExecutor *ex)
{
  int i;
  int n = ex->n;
  int8_t var0;
  int8_t * ptr0;
  int8_t var4;
  const int8_t * ptr4;
  int8_t var5;
  const int8_t * ptr5;
  int8_t var6;
  const int8_t * ptr6;
  const int16_t var16 = 2;
  const int16_t var17 = 2;
  int16_t var32;
  int16_t var33;
  int16_t var34;
  int16_t var35;
  int16_t var36;
  int16_t var37;
  int16_t var38;
  int16_t var39;

  ptr0 = (int8_t *)ex->arrays[0];
  ptr4 = (int8_t *)ex->arrays[4];
  ptr5 = (int8_t *)ex->arrays[5];
  ptr6 = (int8_t *)ex->arrays[6];

  for (i = 0; i < n; i++) {
    var4 = *ptr4;
    ptr4++;
    var5 = *ptr5;
    ptr5++;
    var6 = *ptr6;
    ptr6++;
    /* 0: convubw */
    var32 = (uint8_t)var4;
    /* 1: convubw */
    var33 = (uint8_t)var5;
    /* 2: convubw */
    var34 = (uint8_t)var6;
    /* 3: addw */
    var35 = var32 + var33;
    /* 4: addw */
    var36 = var34 + var34;
    /* 5: addw */
    var37 = var35 + var36;
    /* 6: addw */
    var38 = var37 + var16;
    /* 7: shrsw */
    var39 = var38 >> var17;
    /* 8: convsuswb */
    var0 = ORC_CLAMP_UB(var39);
    *ptr0 = var0;
    ptr0++;
  }

}

void
deinterlace_line_linear_blend (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n)
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
      orc_program_set_name (p, "deinterlace_line_linear_blend");
      orc_program_set_backup_function (p, _backup_deinterlace_line_linear_blend);
      orc_program_add_destination (p, 1, "d1");
      orc_program_add_source (p, 1, "s1");
      orc_program_add_source (p, 1, "s2");
      orc_program_add_source (p, 1, "s3");
      orc_program_add_constant (p, 2, 2, "c1");
      orc_program_add_constant (p, 2, 2, "c2");
      orc_program_add_temporary (p, 2, "t1");
      orc_program_add_temporary (p, 2, "t2");
      orc_program_add_temporary (p, 2, "t3");

      orc_program_append (p, "convubw", ORC_VAR_T1, ORC_VAR_S1, ORC_VAR_D1);
      orc_program_append (p, "convubw", ORC_VAR_T2, ORC_VAR_S2, ORC_VAR_D1);
      orc_program_append (p, "convubw", ORC_VAR_T3, ORC_VAR_S3, ORC_VAR_D1);
      orc_program_append (p, "addw", ORC_VAR_T1, ORC_VAR_T1, ORC_VAR_T2);
      orc_program_append (p, "addw", ORC_VAR_T3, ORC_VAR_T3, ORC_VAR_T3);
      orc_program_append (p, "addw", ORC_VAR_T1, ORC_VAR_T1, ORC_VAR_T3);
      orc_program_append (p, "addw", ORC_VAR_T1, ORC_VAR_T1, ORC_VAR_C1);
      orc_program_append (p, "shrsw", ORC_VAR_T1, ORC_VAR_T1, ORC_VAR_C2);
      orc_program_append (p, "convsuswb", ORC_VAR_D1, ORC_VAR_T1, ORC_VAR_D1);

      result = orc_program_compile (p);
    }
    p_inited = TRUE;
    orc_once_mutex_unlock ();
  }
  ex->program = p;

  ex->n = n;
  ex->arrays[ORC_VAR_D1] = d1;
  ex->arrays[ORC_VAR_S1] = (void *)s1;
  ex->arrays[ORC_VAR_S2] = (void *)s2;
  ex->arrays[ORC_VAR_S3] = (void *)s3;

  func = p->code_exec;
  func (ex);
}
#endif

