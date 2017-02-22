#pragma once
#include"State.h"
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

	virtual void Enter(MinersWife* wife){}

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife){}
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

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

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

};
