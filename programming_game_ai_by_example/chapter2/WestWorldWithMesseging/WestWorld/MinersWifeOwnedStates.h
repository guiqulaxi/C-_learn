#pragma once
#include"fsm/State.h"
//这个必须加
class MinersWife;
class WifesGlobalState : public State<MinersWife>
{
private:

	WifesGlobalState(){}

	//copy ctor and assignment should be private
	WifesGlobalState(const WifesGlobalState&);
	WifesGlobalState& operator=(const WifesGlobalState&);

public:

	static WifesGlobalState* Instance();

	virtual void Enter(MinersWife* pWife){}

	virtual void Execute(MinersWife* pWife);

	virtual void Exit(MinersWife* pWife){}
	virtual bool OnMessage(MinersWife* pWiffe, const Telegram&);
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class DoHouseWork : public State<MinersWife>
{

private:

	DoHouseWork(){}

	//copy ctor and assignment should be private
	DoHouseWork(const DoHouseWork&);
	DoHouseWork& operator=(const DoHouseWork&);

public:

	static DoHouseWork* Instance();

	virtual void Enter(MinersWife* pWife);

	virtual void Execute(MinersWife* pWife);

	virtual void Exit(MinersWife* pWife);

	virtual bool OnMessage(MinersWife* pWife, const Telegram&) ;

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class VisitBathroom : public State<MinersWife>
{
private:

	VisitBathroom(){}

	//copy ctor and assignment should be private
	VisitBathroom(const VisitBathroom&);
	VisitBathroom& operator=(const VisitBathroom&);

public:

	static VisitBathroom* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* pWiffe, const Telegram&);
};

class CookStew : public State<MinersWife>
{
private:

	CookStew(){}

	//copy ctor and assignment should be private
	CookStew(const CookStew&);
	CookStew& operator=(const CookStew&);

public:

	//this is a singleton
	static CookStew* Instance();

	virtual void Enter(MinersWife* pWife);

	virtual void Execute(MinersWife* pWife);

	virtual void Exit(MinersWife* pWife);

	virtual bool OnMessage(MinersWife* pWife, const Telegram& msg);
};
