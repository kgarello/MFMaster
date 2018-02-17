#include "MidiMapCreator.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiReceiver.h"


MidiMapCreator::MidiMapCreator()
{
	_midi_receiver_ = new MidiReceiver();
	_midi_receiver_->SetMidiHandlerObject(this);
	InitializeMidiInput();
}
void MidiMapCreator::HandleMidiInput(juce::MidiMessage message, String source)
{
	Log_MidiMessage(&message);
}

void MidiMapCreator::Log_MidiMessage(MidiMessage* msg)
{
	if (msg->isController())
	{
		int channel = msg->getChannel();
		int controllernum = msg->getControllerNumber();
		int controllervalue = msg->getControllerValue();
	}
	const uint8* const rawmessage = msg->getRawData();
	int messagesize = msg->getRawDataSize();
	String output;
	for (auto i = 0; i < messagesize; i++)
	{

		output += ( String::toHexString(rawmessage[i])) + ":";
	}

	DBG(output);
}

void MidiMapCreator::InitializeMidiInput()
{
	const StringArray list(MidiInput::getDevices());
	for (auto i = 0; i < list.size(); i++)
	{
		_device_manager_.removeMidiInputCallback(list[i], _midi_receiver_);
	}

	for (auto i = 0; i < list.size(); i++)
	{
		const String newInput(list[i]);
		DBG(list[i]);

		if (!_device_manager_.isMidiInputEnabled(newInput))
			_device_manager_.setMidiInputEnabled(newInput, true);
		_device_manager_.addMidiInputCallback(newInput, _midi_receiver_);
	}
}



