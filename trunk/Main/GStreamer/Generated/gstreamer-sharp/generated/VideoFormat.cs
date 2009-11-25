// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst.Video {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[Gst.GLib.GType (typeof (Gst.Video.VideoFormatGType))]
	public enum VideoFormat {

		Unknown,
		I420,
		YV12,
		YUY2,
		UYVY,
		AYUV,
		RGBX,
		BGRX,
		XRGB,
		XBGR,
		RGBA,
		BGRA,
		ARGB,
		ABGR,
		RGB,
		BGR,
		Y41B,
		Y42B,
		YVYU,
		Y444,
		V210,
		V216,
	}

	internal class VideoFormatGType {
		[DllImport ("libgstvideo-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_video_format_get_type ();

		public static Gst.GLib.GType GType {
			get {
				return new Gst.GLib.GType (gst_video_format_get_type ());
			}
		}
	}
#endregion
}
