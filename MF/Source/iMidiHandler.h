/*
  ==============================================================================

    iMidiHandler.h
    Created: 17 Dec 2017 9:59:01am
    Author:  Ken

  ==============================================================================
*/

#pragma once
#include "..\JuceLibraryCode\JuceHeader.h"

class IMidiHandler: public Component
{
public:
	virtual void HandleMidiInput(juce::MidiMessage message, String source) = 0;
};