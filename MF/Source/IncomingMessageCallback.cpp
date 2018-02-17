/*
  ==============================================================================

    IncomingMessageCallback.cpp
    Created: 17 Dec 2017 10:41:03am
    Author:  Ken

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "IncomingMessageCallback.h"
#include "iMidiHandler.h"

IncomingMessageCallback::IncomingMessageCallback(IMidiHandler* o, const MidiMessage & m, const String & s) : owner(o), message(m), source(s)
{
}

void IncomingMessageCallback::messageCallback()
{
	if (owner != nullptr)
		owner->HandleMidiInput(message, source);
}
