// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[Gst.GLib.GType (typeof (Gst.BufferListItemGType))]
	public enum BufferListItem {

		Continue,
		SkipGroup,
		End,
	}

	internal class BufferListItemGType {
		[DllImport ("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_buffer_list_item_get_type ();

		public static Gst.GLib.GType GType {
			get {
				return new Gst.GLib.GType (gst_buffer_list_item_get_type ());
			}
		}
	}
#endregion
}
