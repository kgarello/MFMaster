#include "CrudeTimer.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "BaseEntity.h"

#include "EntityManager.h"
#include "MessageTypes.h"
#include "EntityNames.h"
#include "MessageDispatcher.h"
#include <iostream>
using std::cout;

using std::set;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

void MessageDispatcher::Discharge(BaseEntity * pReceiver, const Telegram & msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
		DBG("Message Not Handled");
	}
}

MessageDispatcher * MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}
//---------------------------- DispatchMessage ---------------------------
//
//  given a message, a receiver, a sender and any time delay , this function
//  routes the message to the correct agent (if no delay) or stores
//  in the message queue to be dispatched at the correct time
//------------------------------------------------------------------------
void MessageDispatcher::Dispatch_Message(double delay, int sender, int receiver, int msg, void * ExtraInfo)
{
	BaseEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	if (pReceiver == NULL)
	{
		DBG("Warning No receiver with Id of " + String(receiver) + " found");
		return;
	}

	Telegram telegram(0, sender, receiver, msg, ExtraInfo);

	if (delay <= 0.0f)
	{
		cout << "\nInstant telegram dispatched at time: " << Clock->Get_CurrentTime()
			<< " by " << get_Name_Of_Entity(pSender->ID()) << " for " << get_Name_Of_Entity(pReceiver->ID())
			<< ". Msg is " << MsgToStr(msg);
		Discharge(pReceiver, telegram);

	}
	else
	{
		double CurrentTime = Clock->Get_CurrentTime();

		telegram.DispatchTime = CurrentTime + delay;

		PriorityQ.insert(telegram);

	}



}

void MessageDispatcher::DispatchDelayedMessages()
{
	double CurrentTime = Clock->Get_CurrentTime();

	//now peek at the queue to see if any telegrams need dispatching.
	//remove all telegrams from the front of the queue that have gone
	//past their sell by date
	while (!PriorityQ.empty() &&
		(PriorityQ.begin()->DispatchTime < CurrentTime) &&
		(PriorityQ.begin()->DispatchTime > 0))
	{
		const Telegram& telegram = *PriorityQ.begin();

		BaseEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);
		cout << "\nQueued telegram ready for dispatch: Sent to "
			<< get_Name_Of_Entity(pReceiver->ID()) << ". Msg is " << MsgToStr(telegram.Msg);

		//send the telegram to the recipient
		Discharge(pReceiver, telegram);

		PriorityQ.erase(PriorityQ.begin());
	}
}
