#pragma once

#include "game/BaseGameEntity.h"
#include "Locations.h"
#include "MinersWifeOwnedStates.h"

#include "Miner.h"
#include "fsm/State.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"
#include "misc/ConsoleUtils.h"

class MinersWife :public BaseGameEntity
{
private:

	StateMachine<MinersWife>*  m_pStateMachine;

	location_type m_Location;

	bool m_bCooking;


public:
	MinersWife(int id) :BaseGameEntity(id), m_Location(shack)
	{
		m_pStateMachine = new StateMachine<MinersWife>(this);
		m_pStateMachine-> SetCurrentState(DoHouseWork::Instance());
		m_pStateMachine->SetGlobalState(WifesGlobalState::Instance());
	}
	~MinersWife()
	{
		delete m_pStateMachine;
	}
	void Update();

	StateMachine<MinersWife>*  GetFSM()const{ return m_pStateMachine; }

	//----------------------------------------------------accessors
	location_type Location()const{ return m_Location; }
	void ChangeLocation(const location_type loc){ m_Location = loc; }


	bool          Cooking()const{ return m_bCooking; }
	void          SetCooking(bool val){ m_bCooking = val; }
	bool MinersWife::HandleMessage(const Telegram& msg);
};


