#include "BaseEntity.h"
#include "../JuceLibraryCode/JuceHeader.h"

#include <cassert>

int BaseEntity::m_next_valid_id_ = 0;

void BaseEntity::set_ID(int val)
{
	//make sure the val is equal to or greater than the next available ID
	jassert((val >= m_next_valid_id_) && "<BaseGameEntity::SetID>: invalid ID");
	m_id_ = val;
	m_next_valid_id_ = m_id_ + 1;
}