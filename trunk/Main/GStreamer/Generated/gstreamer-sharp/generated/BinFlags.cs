// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[Flags]
	[Gst.GLib.GType (typeof (Gst.BinFlagsGType))]
	public enum BinFlags {

		Last = ElementFlags.Last << 5,
	}

	internal class BinFlagsGType {
		[DllImport ("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_bin_flags_get_type ();

		public static Gst.GLib.GType GType {
			get {
				return new Gst.GLib.GType (gst_bin_flags_get_type ());
			}
		}
	}
#endregion
}
