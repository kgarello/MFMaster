#pragma once
#include <string>
#include "Telegram.h"
#include "EntityManager.h"
class BaseEntity
{
private:

	//unique entity ID
	int			m_id_;
	static int	m_next_valid_id_;

	//this must be called within the constructor to make sure the ID is set
	//correctly. It verifies that the value passed to the method is greater
	//or equal to the next valid ID, before setting the ID and incrementing
	//the next valid ID
	void set_ID(int val);

public:

	BaseEntity(/*int id*/)
	{
		set_ID(EntityMgr->getNextId());

		
	}

	virtual ~BaseEntity() {}

	virtual void Update() = 0;
	//all entities can communicate using messages. They are sent
	//using the MessageDispatcher singleton class
	virtual bool  HandleMessage(const Telegram& msg) = 0;

	int			ID()const { return m_id_; }

};
