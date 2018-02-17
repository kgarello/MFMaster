/*
  ==============================================================================

    MidiReceiver.cpp
    Created: 17 Dec 2017 9:58:42am
    Author:  Ken

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiReceiver.h"
#include "iMidiHandler.h"
#include "IncomingMessageCallback.h"

//==============================================================================
MidiReceiver::MidiReceiver()
{

	DBG("In Receiver");

}

MidiReceiver::~MidiReceiver()
{
}

void MidiReceiver::paint (Graphics& g)
{

}

void MidiReceiver::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void MidiReceiver::handleIncomingMidiMessage(MidiInput * source, const juce::MidiMessage & message)
{
	if (myHandler)
		(new IncomingMessageCallback(myHandler, message, source->getName()))->post();	
}

void MidiReceiver::SetMidiHandlerObject(IMidiHandler * handler)
{
	myHandler = handler;
}
