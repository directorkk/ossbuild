using System;
using System.Collections;
using System.Runtime.InteropServices;
using Gst.GLib;
using Gst;
using Gst.Interfaces;

namespace Gst.CorePlugins {
#region Autogenerated code
	[GTypeName ("GstQueue")]
	public sealed class Queue : Gst.Element {
		public Queue (IntPtr raw) : base (raw) { }

		[DllImport("libgstreamer-0.10.dll") ]
		static extern IntPtr gst_element_factory_make (IntPtr element, IntPtr name);

		public Queue (string name) : base (IntPtr.Zero) {
			IntPtr native_name = Gst.GLib.Marshaller.StringToPtrGStrdup (name);
			IntPtr native_element = Gst.GLib.Marshaller.StringToPtrGStrdup ("queue");
			Raw = gst_element_factory_make (native_element, native_name);
			Gst.GLib.Marshaller.Free (native_name);
			Gst.GLib.Marshaller.Free (native_element);
			if (Raw == IntPtr.Zero)
				throw new Exception ("Failed to instantiate element \"queue\"");
		}

		public Queue () : this ((string) null) { }

		public static Queue Make (string name) {
			return Gst.ElementFactory.Make ("queue", name) as Queue;
		}

		public static Queue Make () { return Make (null); } 

		[Gst.GLib.Property ("name")]
		public string Name {
			get {
				Gst.GLib.Value val = GetProperty ("name");
				string ret = (string) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "name");
				val.Val = value;
				SetProperty ("name", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("current-level-buffers")]
		public uint CurrentLevelBuffers {
			get {
				Gst.GLib.Value val = GetProperty ("current-level-buffers");
				uint ret = (uint) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "current-level-buffers");
				val.Val = value;
				SetProperty ("current-level-buffers", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("current-level-bytes")]
		public uint CurrentLevelBytes {
			get {
				Gst.GLib.Value val = GetProperty ("current-level-bytes");
				uint ret = (uint) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "current-level-bytes");
				val.Val = value;
				SetProperty ("current-level-bytes", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("current-level-time")]
		public ulong CurrentLevelTime {
			get {
				Gst.GLib.Value val = GetProperty ("current-level-time");
				ulong ret = (ulong) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "current-level-time");
				val.Val = value;
				SetProperty ("current-level-time", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("max-size-buffers")]
		public uint MaxSizeBuffers {
			get {
				Gst.GLib.Value val = GetProperty ("max-size-buffers");
				uint ret = (uint) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "max-size-buffers");
				val.Val = value;
				SetProperty ("max-size-buffers", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("max-size-bytes")]
		public uint MaxSizeBytes {
			get {
				Gst.GLib.Value val = GetProperty ("max-size-bytes");
				uint ret = (uint) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "max-size-bytes");
				val.Val = value;
				SetProperty ("max-size-bytes", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("max-size-time")]
		public ulong MaxSizeTime {
			get {
				Gst.GLib.Value val = GetProperty ("max-size-time");
				ulong ret = (ulong) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "max-size-time");
				val.Val = value;
				SetProperty ("max-size-time", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("min-threshold-buffers")]
		public uint MinThresholdBuffers {
			get {
				Gst.GLib.Value val = GetProperty ("min-threshold-buffers");
				uint ret = (uint) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "min-threshold-buffers");
				val.Val = value;
				SetProperty ("min-threshold-buffers", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("min-threshold-bytes")]
		public uint MinThresholdBytes {
			get {
				Gst.GLib.Value val = GetProperty ("min-threshold-bytes");
				uint ret = (uint) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "min-threshold-bytes");
				val.Val = value;
				SetProperty ("min-threshold-bytes", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("min-threshold-time")]
		public ulong MinThresholdTime {
			get {
				Gst.GLib.Value val = GetProperty ("min-threshold-time");
				ulong ret = (ulong) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "min-threshold-time");
				val.Val = value;
				SetProperty ("min-threshold-time", val);
				val.Dispose ();
			}
		}

		[Gst.GLib.Property ("leaky")]
		public LeakyType Leaky {
			get {
				Gst.GLib.Value val = GetProperty ("leaky");
				LeakyType ret = (LeakyType) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "leaky");
				val.Val = value;
				SetProperty ("leaky", val);
				val.Dispose ();
			}
		}


		public event SignalHandler Underrun {
			add {
				DynamicSignal.Connect (this, "underrun", value);
			}

			remove {
				DynamicSignal.Disconnect (this, "underrun", value);
			}
		}
		public event SignalHandler Running {
			add {
				DynamicSignal.Connect (this, "running", value);
			}

			remove {
				DynamicSignal.Disconnect (this, "running", value);
			}
		}
		public event SignalHandler Overrun {
			add {
				DynamicSignal.Connect (this, "overrun", value);
			}

			remove {
				DynamicSignal.Disconnect (this, "overrun", value);
			}
		}
		public event SignalHandler Pushing {
			add {
				DynamicSignal.Connect (this, "pushing", value);
			}

			remove {
				DynamicSignal.Disconnect (this, "pushing", value);
			}
		}
		[GTypeName ("GstQueueLeaky")]
		public enum LeakyType {
			No = 0, 
			Upstream = 1, 
			Downstream = 2, 
		}

#endregion
	}

}
