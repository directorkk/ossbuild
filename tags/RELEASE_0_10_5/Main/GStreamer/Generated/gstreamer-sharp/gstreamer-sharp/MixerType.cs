// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst.Interfaces {

	using System;
	using System.Runtime.InteropServices;

#region Autogenerated code
	[Gst.GLib.GType (typeof (Gst.Interfaces.MixerTypeGType))]
	public enum MixerType {

		Hardware,
		Software,
	}

	internal class MixerTypeGType {
		[DllImport ("libgstinterfaces-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_mixer_type_get_type ();

		public static Gst.GLib.GType GType {
			get {
				return new Gst.GLib.GType (gst_mixer_type_get_type ());
			}
		}
	}
#endregion
}
