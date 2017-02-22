#pragma once
#include "../msg/Telegram.h"
class BaseGameEntity
{
public:
	BaseGameEntity(int id)
	{
		SetID(id);
	}

	virtual ~BaseGameEntity(){}

	//all entities must implement an update function
	virtual void  Update() = 0;

	int ID()const{ return m_ID; }
	//������Ϣ
	virtual bool HandleMessage(const Telegram& msg){ return false; }
private:
	int  m_ID;
	static int m_iNextValidID;//��һ����ЧID
	void SetID(int val);
	

};

