// This file was generated by the Gtk# code generator.
// Any changes made will be lost if regenerated.

namespace Gst.Interfaces {

	using System;

#region Autogenerated code
	public partial interface Tuner : Gst.GLib.IWrapper {

		event Gst.Interfaces.SignalChangedHandler SignalChanged;
		event Gst.Interfaces.ChannelChangedHandler ChannelChanged;
		event Gst.Interfaces.FrequencyChangedHandler FrequencyChanged;
		event Gst.Interfaces.NormChangedHandler NormChanged;
		void EmitFrequencyChanged(Gst.Interfaces.TunerChannel channel, ulong frequency);
		Gst.Interfaces.TunerChannel[] ListChannels();
		void SetFrequency(Gst.Interfaces.TunerChannel channel, ulong frequency);
		Gst.Interfaces.TunerChannel[] ListNorms();
		int SignalStrength(Gst.Interfaces.TunerChannel channel);
		Gst.Interfaces.TunerNorm FindNormByName(string norm);
		void EmitNormChanged(Gst.Interfaces.TunerNorm norm);
		Gst.Interfaces.TunerNorm Norm { 
			get; set;
		}
		Gst.Interfaces.TunerChannel FindChannelByName(string channel);
		Gst.Interfaces.TunerChannel Channel { 
			get; set;
		}
		void EmitSignalChanged(Gst.Interfaces.TunerChannel channel, int signal);
		void EmitChannelChanged(Gst.Interfaces.TunerChannel channel);
		ulong GetFrequency(Gst.Interfaces.TunerChannel channel);
	}

	[Gst.GLib.GInterface (typeof (TunerAdapter))]
	public partial interface TunerImplementor : Gst.GLib.IWrapper {

		Gst.Interfaces.TunerChannel[] ListChannels ();
		Gst.Interfaces.TunerChannel Channel { get; set; }
		Gst.Interfaces.TunerChannel[] ListNorms ();
		Gst.Interfaces.TunerNorm Norm { get; set; }
		void SetFrequency (Gst.Interfaces.TunerChannel channel, ulong frequency);
		ulong GetFrequency (Gst.Interfaces.TunerChannel channel);
		int SignalStrength (Gst.Interfaces.TunerChannel channel);
	}
#endregion
}
