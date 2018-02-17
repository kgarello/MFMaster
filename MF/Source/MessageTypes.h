#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

enum message_type
{
	Msg_AllLightsMessage,
	MSG_HANDLE_GUI_BUTTON
};

inline String MsgToStr(int msg)
{
	switch (msg)
	{
	case Msg_AllLightsMessage:
		return "All Lights Message";

	case MSG_HANDLE_GUI_BUTTON:

		return "Handle Gui Button";
	}
}