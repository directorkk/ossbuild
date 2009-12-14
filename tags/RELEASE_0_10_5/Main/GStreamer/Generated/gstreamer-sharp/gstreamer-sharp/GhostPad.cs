// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst {

	using System;
	using System.Collections;
	using System.Runtime.InteropServices;

#region Autogenerated code
	public partial class GhostPad : Gst.Pad {

		public GhostPad(IntPtr raw) : base(raw) {}

		[DllImport("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_ghost_pad_new(IntPtr name, IntPtr target);

		public GhostPad (string name, Gst.Pad target) : base (IntPtr.Zero)
		{
			if (GetType () != typeof (GhostPad)) {
				throw new InvalidOperationException ("Can't override this constructor.");
			}
			IntPtr native_name = Gst.GLib.Marshaller.StringToPtrGStrdup (name);
			Raw = gst_ghost_pad_new(native_name, target == null ? IntPtr.Zero : target.Handle);
			Gst.GLib.Marshaller.Free (native_name);
		}

		[DllImport("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_ghost_pad_new_from_template(IntPtr name, IntPtr target, IntPtr templ);

		public GhostPad (string name, Gst.Pad target, Gst.PadTemplate templ) : base (IntPtr.Zero)
		{
			if (GetType () != typeof (GhostPad)) {
				throw new InvalidOperationException ("Can't override this constructor.");
			}
			IntPtr native_name = Gst.GLib.Marshaller.StringToPtrGStrdup (name);
			Raw = gst_ghost_pad_new_from_template(native_name, target == null ? IntPtr.Zero : target.Handle, templ == null ? IntPtr.Zero : templ.Handle);
			Gst.GLib.Marshaller.Free (native_name);
		}

		[DllImport("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_ghost_pad_new_no_target(IntPtr name, int dir);

		public GhostPad (string name, Gst.PadDirection dir) : base (IntPtr.Zero)
		{
			if (GetType () != typeof (GhostPad)) {
				throw new InvalidOperationException ("Can't override this constructor.");
			}
			IntPtr native_name = Gst.GLib.Marshaller.StringToPtrGStrdup (name);
			Raw = gst_ghost_pad_new_no_target(native_name, (int) dir);
			Gst.GLib.Marshaller.Free (native_name);
		}

		[DllImport("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_ghost_pad_new_no_target_from_template(IntPtr name, IntPtr templ);

		public GhostPad (string name, Gst.PadTemplate templ) : base (IntPtr.Zero)
		{
			if (GetType () != typeof (GhostPad)) {
				throw new InvalidOperationException ("Can't override this constructor.");
			}
			IntPtr native_name = Gst.GLib.Marshaller.StringToPtrGStrdup (name);
			Raw = gst_ghost_pad_new_no_target_from_template(native_name, templ == null ? IntPtr.Zero : templ.Handle);
			Gst.GLib.Marshaller.Free (native_name);
		}

		[StructLayout (LayoutKind.Sequential)]
		struct GstGhostPadClass {
			[MarshalAs (UnmanagedType.ByValArray, SizeConst=4)]
			public IntPtr[] GstReserved;
		}

		static uint class_offset = ((Gst.GLib.GType) typeof (Gst.Pad)).GetClassSize ();
		static Hashtable class_structs;

		static GstGhostPadClass GetClassStruct (Gst.GLib.GType gtype, bool use_cache)
		{
			if (class_structs == null)
				class_structs = new Hashtable ();

			if (use_cache && class_structs.Contains (gtype))
				return (GstGhostPadClass) class_structs [gtype];
			else {
				IntPtr class_ptr = new IntPtr (gtype.GetClassPtr ().ToInt64 () + class_offset);
				GstGhostPadClass class_struct = (GstGhostPadClass) Marshal.PtrToStructure (class_ptr, typeof (GstGhostPadClass));
				if (use_cache)
					class_structs.Add (gtype, class_struct);
				return class_struct;
			}
		}

		static void OverrideClassStruct (Gst.GLib.GType gtype, GstGhostPadClass class_struct)
		{
			IntPtr class_ptr = new IntPtr (gtype.GetClassPtr ().ToInt64 () + class_offset);
			Marshal.StructureToPtr (class_struct, class_ptr, false);
		}

		[DllImport("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern bool gst_ghost_pad_set_target(IntPtr raw, IntPtr newtarget);

		public bool SetTarget(Gst.Pad newtarget) {
			bool raw_ret = gst_ghost_pad_set_target(Handle, newtarget == null ? IntPtr.Zero : newtarget.Handle);
			bool ret = raw_ret;
			return ret;
		}

		[DllImport("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_ghost_pad_get_target(IntPtr raw);

		public Gst.Pad Target { 
			get {
				IntPtr raw_ret = gst_ghost_pad_get_target(Handle);
				Gst.Pad ret = Gst.GLib.Object.GetObject(raw_ret, true) as Gst.Pad;
				return ret;
			}
		}

		[DllImport("libgstreamer-0.10.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern IntPtr gst_ghost_pad_get_type();

		public static new Gst.GLib.GType GType { 
			get {
				IntPtr raw_ret = gst_ghost_pad_get_type();
				Gst.GLib.GType ret = new Gst.GLib.GType(raw_ret);
				return ret;
			}
		}

#endregion
	}
}
