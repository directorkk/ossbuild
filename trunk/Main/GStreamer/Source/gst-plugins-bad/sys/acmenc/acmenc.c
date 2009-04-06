/* GStreamer
 * Copyright (C) 2008 Pioneers of the Inevitable <songbird@songbirdnest.com>
 *
 * Authors: Michael Smith <msmith@songbirdnest.com>
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
#include "config.h"
#endif  /* 
    
#include <windows.h>
#include <mmreg.h>
#include <msacm.h>
    
#include <gst/gst.h>
#include <gst/riff/riff-media.h>
    
/* This has to be bigger than some unspecified minimum size or things
 * break; I don't understand why (4kB isn't enough). Make it nice and
 * big.
 */ 
#define ACM_BUFFER_SIZE (64 * 1024)

{ 
};

#define DEFAULT_BITRATE 128000
    
#define ACMENC_PARAMS_QDATA g_quark_from_static_string("acmenc-params")
    
#define GST_CAT_DEFAULT acmenc_debug
    GST_DEBUG_CATEGORY_STATIC (acmenc_debug);

    
    
        "width = (int)16, " 
        ", " 
        "rate = (int)[1, MAX]") 

    
    


{
  
  


{
  
  
  
  
  
  
  
  
  
  
      /* Offset into input buffer to write next data */ 
  int offset;
   
      /* Number of bytes written */ 
  int bytes_output;
   
      /* From received caps */ 
  int rate;
   
   
      /* Set in properties */ 
  int selected_bitrate;
   
 

{
  
  
  


acmenc_caps_from_format (WAVEFORMATEX * fmt) 
{
  
      (gst_riff_strf_auds *) fmt, NULL, NULL, NULL);



{
  
  
  
  
  
  
  
  



    DWORD_PTR dwInstance, DWORD fdwSupport) 
{
  
  
  
  
    
        /* First one is always the best so far */ 
        enc->outfmt =
        (WAVEFORMATEX *) g_malloc (fd->pwfx->cbSize + sizeof (WAVEFORMATEX));
    
    
  
  
      /* We prefer a format with exact rate/channels match,
       * and the closest bitrate match. Otherwise, we accept
       * the closest bitrate match.
       */ 
      newmatch = (enc->channels == fd->pwfx->nChannels) && 
      (enc->rate == fd->pwfx->nSamplesPerSec);
  
      (enc->outfmt->nSamplesPerSec == enc->rate);
  
  
  
      (!newmatch && !oldmatch && (newbrdiff < oldbrdiff)))
    
    
    
        (WAVEFORMATEX *) g_malloc (fd->pwfx->cbSize + sizeof (WAVEFORMATEX));
    
    
  
      /* Always return TRUE to continue enumeration */ 
      return TRUE;



{
  
  
  
  
  
      /* Input is fixed */ 
      acmenc_set_input_format (enc, &enc->infmt);
  
      /* Select the closest output that matches */ 
      res =
      acmMetrics ((HACMOBJ) enc->driver, ACM_METRIC_MAX_SIZE_FORMAT, &maxSize);
  
      /* Set the format to match what we'll be providing */ 
      in = (WAVEFORMATEX *) g_malloc (maxSize);
  
  
  
  
  
  
  
  
  
      /* We set enc->outfmt to the closest match in the callback */ 
      res =
      acmFormatEnum (enc->driver, &details, acmenc_format_enum, (DWORD_PTR) enc,
      ACM_FORMATENUMF_CONVERT);
  
  
    
    
  
  
    
    
  
  


acmenc_setup (ACMEnc * enc) 
{
  
  
  
  
  
    
    
  
  
    
  
      acmStreamOpen (&enc->stream, enc->driver, &enc->infmt, enc->outfmt, 
      0, ACM_STREAMOPENF_NONREALTIME);
  
    
    
  
  
  
  
  
  
  
  
  
      /* Ask what buffer size we need to use for our output */ 
      acmStreamSize (enc->stream, ACM_BUFFER_SIZE, 
      ACM_STREAMSIZEF_SOURCE);
  
  
  
  
  
  
    
    
  
  
  
    
  
  
  


acmenc_teardown (ACMEnc * enc) 
{
  
    
    
  
  
    
    
  
  
    
  
    
  
  
    
    
  
  
    
    
  
  
  
  


acmenc_sink_setcaps (GstPad * pad, GstCaps * caps) 
{
  
  
  
  
  
  
  
    
  
  


acmenc_push_output (ACMEnc * enc) 
{
  
  
    
        gst_buffer_new_and_alloc (enc->header.cbDstLengthUsed);
    
        enc->header.cbDstLengthUsed);
    
      
          /* We have a bitrate, so we can create a timestamp, hopefully */ 
          GST_BUFFER_TIMESTAMP (outbuf) =
          gst_util_uint64_scale_int (
          enc->outfmt->nAvgBytesPerSec);
    
    
    
        enc->header.cbDstLengthUsed);
    
  
  


acmenc_chain (GstPad * pad, GstBuffer * buf) 
{
  
  
  
  
  
  
  
    
    
    
    
    
    
        /* Now we have a buffer ready to go */ 
        res =
        acmStreamConvert (enc->stream, &enc->header,
        
    
      
      
    
    
      
      
        
            /* Only part of input consumed */ 
            memmove (enc->header.pbSrc,
            enc->header.pbSrc + enc->header.cbSrcLengthUsed,
            
        
      
      
      else
        
      
    
        /* Write out any data produced */ 
        acmenc_push_output (enc);
  
  



{
  
  
  
  
      /* Ensure any remaining input data is consumed */ 
      len = enc->offset;
  
  
      acmStreamConvert (enc->stream, &enc->header,
      
  
    
    
  
  
  


acmenc_sink_event (GstPad * pad, GstEvent * event) 
{
  
  
  
    
      
      
      
    
      
      
  
  


acmenc_dispose (GObject * obj) 
{
  
  
  


acmenc_init (ACMEnc * enc) 
{
  
      gst_pad_new_from_static_template (&acmenc_sink_template, "sink");
  
      
  
  
      
  
  
      gst_pad_new_from_static_template (&acmenc_src_template, "src");
  
  

acmenc_set_property (GObject * obj, guint prop_id, 
    GParamSpec * pspec) 
{
  
  
    
      
      
    
      
  


acmenc_get_property (GObject * obj, guint prop_id, 
    GParamSpec * pspec) 
{
  
  
    
      
      
    
      
  


acmenc_class_init (ACMEncClass * klass) 
{
  
  
  
  
  
  
      
          0, 1000000, DEFAULT_BITRATE, 


acmenc_base_init (ACMEncClass * klass) 
{
  
  
  
  
  
  
  
      
  
      
  
      (ACMEncParams *) 
      ACMENC_PARAMS_QDATA);
  
  
  
  
  
    
  
  
      g_utf16_to_utf8 (driverdetails.szShortName, -1, NULL, NULL, NULL);
  
  
          && *shortname) ? shortname : params->name);
  
  
          && *longname) ? longname : params->name);
  
  
  
  
  
  
  


acmenc_open_driver (wchar_t * filename) 
{
  
  
  
  
  
  
  
  
    
    
  
  
  
    
    
  
  
      acmDriverAdd (&driverid, mod, (LPARAM) func, 0, ACM_DRIVERADDF_FUNCTION);
  
    
    
  
  
  
  
  

    
  
    
  


acmenc_register_file (GstPlugin * plugin, wchar_t * filename) 
{
  
  
  
  
  
        (GBaseInitFunc) acmenc_base_init, 
        (GClassInitFunc) acmenc_class_init, 
        
  
  
    
  
      /* Strip .acm off the end, convert to utf-8 */ 
      name =
      g_utf16_to_utf8 (filename, (glong) wcslen (filename) - 4, 
      NULL);
  
  
  
  
      /* Store params in type qdata */ 
      g_type_set_qdata (type, ACMENC_PARAMS_QDATA, (gpointer) params);
  
      /* register type */ 
      if (!gst_element_register (plugin, type_name, GST_RANK_NONE, type)) {
    
    
    
    
    
    
  
  
  


acmenc_register (GstPlugin * plugin) 
{
  
  
  
  
  
  
    
    
  
  
  
  
    
    
  
  
  do {
    
        g_utf16_to_utf8 (filedata.cFileName, -1, NULL, NULL, NULL);
    
    
      
    
    else
      
    
  
  
  


plugin_init (GstPlugin * plugin) 
{
  
  
  
  
  



    
    "http://gstreamer.net/") 