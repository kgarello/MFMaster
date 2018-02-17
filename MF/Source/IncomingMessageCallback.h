/*
  ==============================================================================

    IncomingMessageCallback.h
    Created: 17 Dec 2017 10:41:03am
    Author:  Ken

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "iMidiHandler.h"
//==============================================================================
/*
*/

class IncomingMessageCallback : public CallbackMessage
{
public:
	IncomingMessageCallback(IMidiHandler* o, const juce::MidiMessage& m, const juce::String& s);
	void messageCallback() override;
	

	Component::SafePointer<IMidiHandler> owner;
	MidiMessage message;
	String source;
};
