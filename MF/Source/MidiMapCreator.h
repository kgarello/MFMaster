#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "iMidiHandler.h"

class MidiReceiver;

class MidiMapCreator:public Component, public IMidiHandler
{
private:
	AudioDeviceManager						_device_manager_;
	ScopedPointer<MidiReceiver>				_midi_receiver_;


	// Inherited via IMidiHandler
	virtual void					HandleMidiInput(juce::MidiMessage message, String source) override;
	void							Log_MidiMessage(MidiMessage* msg);

public:
	MidiMapCreator();
};