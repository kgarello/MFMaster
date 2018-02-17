#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

enum
{
	ent_Program_Loop
};


inline String get_Name_Of_Entity(int n)
{
	switch (n)
	{
	case ent_Program_Loop:
		return "Program Loop";
	default:
		return "UNKNOWN";
	}
}
