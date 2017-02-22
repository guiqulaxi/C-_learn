#pragma once
#include"State.h"
#include<stdio.h>
#include<assert.h>

template<class entity_type>
class StateMachine
{
public:
	StateMachine(entity_type *owner) :m_pOwner(owner), m_pCurrentState(NULL), m_pPreviousState(NULL), m_pGlobalState(NULL){}
	
	virtual ~StateMachine(){}
	//use these methods to initialize the FSM
	void SetCurrentState(State<entity_type>* s){ m_pCurrentState = s; }
	void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }
	void SetPreviousState(State<entity_type>* s){ m_pPreviousState = s; }

	
	void  Update()const
	{
		//if a global state exists, call its execute method, else do nothing
		if (m_pGlobalState)   m_pGlobalState->Execute(m_pOwner);

		//same for the current state
		if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
	}

	//change to a new state
	void  ChangeState(State<entity_type>* pNewState)
	{
		assert(pNewState &&
			"<StateMachine::ChangeState>: trying to change to NULL state");

		//记录前一个状态
		m_pPreviousState = m_pCurrentState;

		//退出当前状态
		m_pCurrentState->Exit(m_pOwner);

		//改变到新的状态
		m_pCurrentState = pNewState;

		//进入新的状态
		m_pCurrentState->Enter(m_pOwner);
	}

	//返回至前一个状态
	void  RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}

	//returns true if the current state's type is equal to the type of the
	//class passed as a parameter. 
	bool  isInState(const State<entity_type>& st)const
	{
		return typeid(*m_pCurrentState) == typeid(st);
	}

	State<entity_type>*  CurrentState()  const{ return m_pCurrentState; }
	State<entity_type>*  GlobalState()   const{ return m_pGlobalState; }
	State<entity_type>*  PreviousState() const{ return m_pPreviousState; }

private:
	entity_type *m_pOwner;
	State<entity_type>* m_pCurrentState;
	State<entity_type>* m_pPreviousState;
	//每次状态机执行就调用
	State<entity_type>* m_pGlobalState;

};

#include <cassert>
#include <string>

#include "State.h"





