/*
  ==============================================================================

    MidiReceiver.h
    Created: 17 Dec 2017 9:58:42am
    Author:  Ken

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
class IMidiHandler;

//==============================================================================
/*
*/
class MidiReceiver    : public Component, public MidiInputCallback
{
public:
    MidiReceiver();
    ~MidiReceiver();

    void paint (Graphics&) override;
    void resized() override;
	virtual void handleIncomingMidiMessage(MidiInput * source, const MidiMessage & message) override;
	void SetMidiHandlerObject(IMidiHandler* handler);
private:
	IMidiHandler* myHandler = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiReceiver)

		// Inherited via MidiInputCallback
		
};
