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
	//处理消息
	virtual bool HandleMessage(const Telegram& msg){ return false; }
private:
	int  m_ID;
	static int m_iNextValidID;//下一个有效ID
	void SetID(int val);
	

};

