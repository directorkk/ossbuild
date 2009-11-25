using System;
using System.Collections;
using System.Runtime.InteropServices;
using Gst.GLib;
using Gst;
using Gst.Interfaces;

namespace Gst.CorePlugins {
#region Autogenerated code
	[GTypeName ("GstFdSink")]
	public sealed class FdSink : Gst.Base.BaseSink, Gst.URIHandler {
		public FdSink (IntPtr raw) : base (raw) { }

		[DllImport("libgstreamer-0.10.dll") ]
		static extern IntPtr gst_element_factory_make (IntPtr element, IntPtr name);

		public FdSink (string name) : base (IntPtr.Zero) {
			IntPtr native_name = Gst.GLib.Marshaller.StringToPtrGStrdup (name);
			IntPtr native_element = Gst.GLib.Marshaller.StringToPtrGStrdup ("fdsink");
			Raw = gst_element_factory_make (native_element, native_name);
			Gst.GLib.Marshaller.Free (native_name);
			Gst.GLib.Marshaller.Free (native_element);
			if (Raw == IntPtr.Zero)
				throw new Exception ("Failed to instantiate element \"fdsink\"");
		}

		public FdSink () : this ((string) null) { }

		public static FdSink Make (string name) {
			return Gst.ElementFactory.Make ("fdsink", name) as FdSink;
		}

		public static FdSink Make () { return Make (null); } 

		[Gst.GLib.Property ("fd")]
		public int Fd {
			get {
				Gst.GLib.Value val = GetProperty ("fd");
				int ret = (int) val.Val;
				val.Dispose ();
				return ret;
			}
			set {
				Gst.GLib.Value val = new Gst.GLib.Value (this, "fd");
				val.Val = value;
				SetProperty ("fd", val);
				val.Dispose ();
			}
		}


#endregion
#region Customized code
#line 1 "GstURIHandler.cs"
[GLib.Signal ("new-uri") ]
event Gst.NewUriHandler Gst.URIHandler.NewUri {
  add {
    GLib.Signal sig = GLib.Signal.Lookup (GLib.Object.GetObject (Handle), "new-uri", typeof (Gst.NewUriArgs));
    sig.AddDelegate (value);
  }
  remove {
    GLib.Signal sig = GLib.Signal.Lookup (GLib.Object.GetObject (Handle), "new-uri", typeof (Gst.NewUriArgs));
    sig.RemoveDelegate (value);
  }
}

[DllImport ("libgstreamer-0.10.dll") ]
static extern uint gst_uri_handler_get_uri_type (IntPtr raw);

Gst.URIType Gst.URIHandler.UriType {
  get {
    uint raw_ret = gst_uri_handler_get_uri_type (Handle);
    Gst.URIType ret = (Gst.URIType) raw_ret;
    return ret;
  }
}

[DllImport ("libgstreamer-0.10.dll") ]
static extern bool gst_uri_handler_set_uri (IntPtr raw, IntPtr uri);

bool Gst.URIHandler.SetUri (string uri) {
  IntPtr native_uri = GLib.Marshaller.StringToPtrGStrdup (uri);
  bool raw_ret = gst_uri_handler_set_uri (Handle, native_uri);
  bool ret = raw_ret;
  GLib.Marshaller.Free (native_uri);
  return ret;
}

[DllImport ("libgstreamer-0.10.dll") ]
static extern IntPtr gst_uri_handler_get_protocols (IntPtr raw);

string[] Gst.URIHandler.Protocols {
  get {
    IntPtr raw_ret = gst_uri_handler_get_protocols (Handle);
    string[] ret = GLib.Marshaller.NullTermPtrToStringArray (raw_ret, false);
    return ret;
  }
}

[DllImport ("libgstreamer-0.10.dll") ]
static extern IntPtr gst_uri_handler_get_uri (IntPtr raw);

string Gst.URIHandler.Uri {
  get {
    IntPtr raw_ret = gst_uri_handler_get_uri (Handle);
    string ret = GLib.Marshaller.Utf8PtrToString (raw_ret);
    return ret;
  }
}


#endregion
	}

}
