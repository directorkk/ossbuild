
/* autogenerated from gstcolorspaceorc.orc */

#ifndef _GSTCOLORSPACEORC_H_
#define _GSTCOLORSPACEORC_H_

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif



#ifndef _ORC_INTEGER_TYPEDEFS_
#define _ORC_INTEGER_TYPEDEFS_
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdint.h>
typedef int8_t orc_int8;
typedef int16_t orc_int16;
typedef int32_t orc_int32;
typedef int64_t orc_int64;
typedef uint8_t orc_uint8;
typedef uint16_t orc_uint16;
typedef uint32_t orc_uint32;
typedef uint64_t orc_uint64;
#define ORC_UINT64_C(x) UINT64_C(x)
#elif defined(_MSC_VER)
typedef signed __int8 orc_int8;
typedef signed __int16 orc_int16;
typedef signed __int32 orc_int32;
typedef signed __int64 orc_int64;
typedef unsigned __int8 orc_uint8;
typedef unsigned __int16 orc_uint16;
typedef unsigned __int32 orc_uint32;
typedef unsigned __int64 orc_uint64;
#define ORC_UINT64_C(x) (x##Ui64)
#else
#include <limits.h>
typedef signed char orc_int8;
typedef short orc_int16;
typedef int orc_int32;
typedef unsigned char orc_uint8;
typedef unsigned short orc_uint16;
typedef unsigned int orc_uint32;
#if INT_MAX == LONG_MAX
typedef long long orc_int64;
typedef unsigned long long orc_uint64;
#define ORC_UINT64_C(x) (x##ULL)
#else
typedef long orc_int64;
typedef unsigned long orc_uint64;
#define ORC_UINT64_C(x) (x##UL)
#endif
#endif
typedef union { orc_int16 i; orc_int8 x2[2]; } orc_union16;
typedef union { orc_int32 i; float f; orc_int16 x2[2]; orc_int8 x4[4]; } orc_union32;
typedef union { orc_int64 i; double f; orc_int32 x2[2]; float x2f[2]; orc_int16 x4[4]; } orc_union64;
#endif
void cogorc_memcpy_2d (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_downsample_horiz_cosite_1tap (guint8 * d1, const guint8 * s1, int n);
void cogorc_downsample_horiz_cosite_3tap (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void cogorc_downsample_420_jpeg (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void cogorc_downsample_vert_halfsite_2tap (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void cogorc_downsample_vert_cosite_3tap (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void cogorc_downsample_vert_halfsite_4tap (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, int n);
void cogorc_upsample_horiz_cosite_1tap (guint8 * d1, const guint8 * s1, int n);
void cogorc_upsample_horiz_cosite (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void cogorc_upsample_vert_avgub (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void orc_unpack_yuyv_y (guint8 * d1, const guint8 * s1, int n);
void orc_unpack_yuyv_u (guint8 * d1, const guint8 * s1, int n);
void orc_unpack_yuyv_v (guint8 * d1, const guint8 * s1, int n);
void orc_pack_yuyv (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void orc_unpack_uyvy_y (guint8 * d1, const guint8 * s1, int n);
void orc_unpack_uyvy_u (guint8 * d1, const guint8 * s1, int n);
void orc_unpack_uyvy_v (guint8 * d1, const guint8 * s1, int n);
void orc_pack_uyvy (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void orc_matrix2_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, int p1, int p2, int p3, int n);
void orc_matrix2_11_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, int p1, int p2, int n);
void orc_matrix2_12_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, int p1, int p2, int n);
void orc_matrix3_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int p1, int p2, int p3, int p4, int n);
void orc_matrix3_100_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int p1, int p2, int p3, int n);
void orc_matrix3_100_offset_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int p1, int p2, int p3, int p4, int p5, int n);
void orc_matrix3_000_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int p1, int p2, int p3, int p4, int p5, int n);
void orc_pack_123x (guint32 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int p1, int n);
void orc_pack_x123 (guint32 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int p1, int n);
void cogorc_combine2_u8 (guint8 * d1, const guint8 * s1, const guint8 * s2, int p1, int p2, int n);
void cogorc_convert_I420_UYVY (guint8 * d1, guint8 * d2, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, int n);
void cogorc_convert_I420_YUY2 (guint8 * d1, guint8 * d2, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, int n);
void cogorc_convert_I420_AYUV (guint8 * d1, guint8 * d2, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, int n);
void cogorc_convert_YUY2_I420 (guint8 * d1, guint8 * d2, guint8 * d3, guint8 * d4, const guint8 * s1, const guint8 * s2, int n);
void cogorc_convert_UYVY_YUY2 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_planar_chroma_420_422 (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_planar_chroma_420_444 (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_planar_chroma_422_444 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_planar_chroma_444_422 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_planar_chroma_444_420 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, int n, int m);
void cogorc_planar_chroma_422_420 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, int n, int m);
void cogorc_convert_YUY2_AYUV (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_UYVY_AYUV (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_YUY2_Y42B (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, guint8 * d3, int d3_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_UYVY_Y42B (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, guint8 * d3, int d3_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_YUY2_Y444 (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, guint8 * d3, int d3_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_UYVY_Y444 (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, guint8 * d3, int d3_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_UYVY_I420 (guint8 * d1, guint8 * d2, guint8 * d3, guint8 * d4, const guint8 * s1, const guint8 * s2, int n);
void cogorc_convert_AYUV_I420 (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, guint8 * d3, int d3_stride, guint8 * d4, int d4_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, int n, int m);
void cogorc_convert_AYUV_YUY2 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_AYUV_UYVY (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_AYUV_Y42B (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, guint8 * d3, int d3_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_AYUV_Y444 (guint8 * d1, int d1_stride, guint8 * d2, int d2_stride, guint8 * d3, int d3_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_Y42B_YUY2 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, const guint8 * s3, int s3_stride, int n, int m);
void cogorc_convert_Y42B_UYVY (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, const guint8 * s3, int s3_stride, int n, int m);
void cogorc_convert_Y42B_AYUV (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, const guint8 * s3, int s3_stride, int n, int m);
void cogorc_convert_Y444_YUY2 (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, const guint8 * s3, int s3_stride, int n, int m);
void cogorc_convert_Y444_UYVY (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, const guint8 * s3, int s3_stride, int n, int m);
void cogorc_convert_Y444_AYUV (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, const guint8 * s2, int s2_stride, const guint8 * s3, int s3_stride, int n, int m);
void cogorc_convert_AYUV_ARGB (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_AYUV_BGRA (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_AYUV_ABGR (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_AYUV_RGBA (guint8 * d1, int d1_stride, const guint8 * s1, int s1_stride, int n, int m);
void cogorc_convert_I420_BGRA (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void cogorc_convert_I420_BGRA_avg (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, const guint8 * s5, int n);
void cogorc_getline_I420 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void cogorc_getline_YUV9 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void cogorc_getline_YUY2 (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_UYVY (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_YVYU (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_Y42B (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void cogorc_getline_Y444 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);
void cogorc_getline_Y800 (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_Y16 (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_BGRA (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_ABGR (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_RGBA (guint8 * d1, const guint8 * s1, int n);
void cogorc_getline_NV12 (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void cogorc_getline_NV21 (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void cogorc_getline_A420 (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, int n);
void cogorc_putline_I420 (guint8 * d1, guint8 * d2, guint8 * d3, const guint8 * s1, int n);
void cogorc_putline_YUY2 (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_YVYU (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_UYVY (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_Y42B (guint8 * d1, guint8 * d2, guint8 * d3, const guint8 * s1, int n);
void cogorc_putline_Y444 (guint8 * d1, guint8 * d2, guint8 * d3, const guint8 * s1, int n);
void cogorc_putline_Y800 (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_Y16 (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_BGRA (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_ABGR (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_RGBA (guint8 * d1, const guint8 * s1, int n);
void cogorc_putline_NV12 (guint8 * d1, guint8 * d2, const guint8 * s1, int n);
void cogorc_putline_NV21 (guint8 * d1, guint8 * d2, const guint8 * s1, int n);
void cogorc_putline_A420 (guint8 * d1, guint8 * d2, guint8 * d3, guint8 * d4, const guint8 * s1, int n);

#ifdef __cplusplus
}
#endif

#endif

