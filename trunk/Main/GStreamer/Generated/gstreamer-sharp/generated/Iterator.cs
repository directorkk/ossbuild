// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst {

	using System;
	using System.Collections;
	using System.Runtime.InteropServices;

#region Autogenerated code
	public partial class Iterator : Gst.GLib.Opaque, IEnumerable {

		public Iterator(IntPtr raw) : base(raw) {}

#endregion
#region Customized extensions
#line 1 "Iterator.custom"
[DllImport ("libgstreamer-0.10.dll") ]
static extern int gst_iterator_next (IntPtr iterator, out IntPtr elem);
[DllImport ("libgstreamer-0.10.dll") ]
static extern void gst_iterator_resync (IntPtr iterator);

private class Enumerator : IEnumerator {
  Iterator iterator;
  Hashtable seen = new Hashtable ();

  private object current = null;
  public object Current {
    get {
      return current;
    }
  }

  public bool MoveNext () {
    IntPtr raw_ret;
    bool retry = false;

    if (iterator.Handle == IntPtr.Zero)
      return false;

    do {
      int ret = gst_iterator_next (iterator.Handle, out raw_ret);
      switch (ret) {
        case 0:
          return false;
        case 1:
          if (seen.Contains (raw_ret)) {
            retry = true;
            break;
          }
          seen.Add (raw_ret, null);
          current = Gst.GLib.Object.GetObject (raw_ret, true);
          return true;
        case 2:
          gst_iterator_resync (iterator.Handle);
          retry = true;
          break;
        default:
        case 3:
          throw new Exception ("Error while iterating pads");
      }
    } while (retry);

    return false;
  }

  public void Reset () {
    seen.Clear ();
    if (iterator.Handle != IntPtr.Zero)
      gst_iterator_resync (iterator.Handle);
  }

  public Enumerator (Iterator iterator) {
    this.iterator = iterator;
  }
}

private Enumerator enumerator = null;

public IEnumerator GetEnumerator () {
  if (this.enumerator == null)
    this.enumerator = new Enumerator (this);
  return this.enumerator;
}

[DllImport ("libgstreamer-0.10.dll") ]
static extern void gst_iterator_free (IntPtr iterator);

~Iterator () {
  if (Raw != IntPtr.Zero)
    gst_iterator_free (Raw);
}

#endregion
	}
}
