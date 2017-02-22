#pragma once
#include "MinersWifeOwnedStates.h"
#include"MinersWife.h"
#include "misc/utils.h"
#include "EntityNames.h"

#include<iostream>
//-----------------------------------------------------------------------Global state
WifesGlobalState* WifesGlobalState::Instance()
{
	static WifesGlobalState instance;

	return &instance;
}


void WifesGlobalState::Execute(MinersWife* wife)
{
	//1 in 10 chance of needing the bathroom
	if (RandFloat() < 0.1)
	{
		wife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
}

//---------------------------------------DoHouseWork

DoHouseWork* DoHouseWork::Instance()
{
	static DoHouseWork instance;

	return &instance;
}


void DoHouseWork::Enter(MinersWife* wife)
{
}


void DoHouseWork::Execute(MinersWife* wife)
{
	switch (RandInt(0, 2))
	{
	case 0:

		std::cout << "\n" << GetNameOfEntity(wife->ID()) << ": ÍÏµØ";

		break;

	case 1:

		std::cout << "\n" << GetNameOfEntity(wife->ID()) << ": Ï´Íë";

		break;

	case 2:

		std::cout << "\n" << GetNameOfEntity(wife->ID()) << ": ÆÌ´²";

		break;
	}
}

void DoHouseWork::Exit(MinersWife* wife)
{
}



//------------------------------------------------------------------------VisitBathroom
VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;

	return &instance;
}


void VisitBathroom::Enter(MinersWife* wife)
{
	std::cout << "\n" << GetNameOfEntity(wife->ID()) << ": ½øÈëîÂÏ´ÊÒ";
}


void VisitBathroom::Execute(MinersWife* wife)
{
	std::cout << "\n" << GetNameOfEntity(wife->ID()) << ":Ï´Ôè!";

	wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* wife)
{
	std::cout << "\n" << GetNameOfEntity(wife->ID()) << ": Àë¿ªîÂÏ´ÊÒ";
}