#include "MidiMapCreator.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiReceiver.h"

void MidiMapCreator::HandleMidiInput(juce::MidiMessage message, String source)
{
	Log_MidiMessage(&message);
}

void MidiMapCreator::Log_MidiMessage(MidiMessage* msg)
{
	int channel = msg->getChannel();
	int controllernum = msg->getControllerNumber();
	int controllervalue = msg->getControllerValue();

	const uint8* const rawmessage = msg->getRawData();
	int messagesize = msg->getRawDataSize();
	String output;
	for (auto i = 0; i < messagesize; i++)
	{
		output += rawmessage[i];
	}

	DBG(output);
}

MidiMapCreator::MidiMapCreator()
{
	_midi_receiver_ = new MidiReceiver();
}
