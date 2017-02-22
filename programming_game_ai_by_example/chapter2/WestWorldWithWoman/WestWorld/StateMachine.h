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

		//��¼ǰһ��״̬
		m_pPreviousState = m_pCurrentState;

		//�˳���ǰ״̬
		m_pCurrentState->Exit(m_pOwner);

		//�ı䵽�µ�״̬
		m_pCurrentState = pNewState;

		//�����µ�״̬
		m_pCurrentState->Enter(m_pOwner);
	}

	//������ǰһ��״̬
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
	//ÿ��״̬��ִ�о͵���
	State<entity_type>* m_pGlobalState;

};

#include <cassert>
#include <string>

#include "State.h"





