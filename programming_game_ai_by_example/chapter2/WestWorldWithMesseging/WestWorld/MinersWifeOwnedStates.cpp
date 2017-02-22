#pragma once
#include "MinersWifeOwnedStates.h"
#include"MinersWife.h"
#include "misc/utils.h"
#include "EntityNames.h"
#include "msg/MessageDispatcher.h"
#include "time/CrudeTimer.h"
#include "MessageTypes.h"

#include<iostream>
#pragma region 全局状态
WifesGlobalState* WifesGlobalState::Instance()
{
	static WifesGlobalState instance;

	return &instance;
}


void WifesGlobalState::Execute(MinersWife* pWife)
{
	//1 in 10 chance of needing the bathroom
	if (RandFloat() < 0.1)
	{
		pWife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
}
bool WifesGlobalState::OnMessage(MinersWife* pWife, const Telegram& msg)
{

	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_HiHoneyImHome:
	{
							  std::cout << "\nMessage handled by " << GetNameOfEntity(pWife->ID()) << " at time: "
								  << Clock->GetCurrentTime();

							  SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

							  std::cout << "\n" << GetNameOfEntity(pWife->ID()) <<
								  ": Hi honey. Let me make you some of mah fine country stew";

							  pWife->GetFSM()->ChangeState(CookStew::Instance());
	}

		return true;

	}//end switch

	return false;
}
#pragma endregion

#pragma region 做家务
//---------------------------------------DoHouseWork

DoHouseWork* DoHouseWork::Instance()
{
	static DoHouseWork instance;

	return &instance;
}


void DoHouseWork::Enter(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 准备做家务";
}


void DoHouseWork::Execute(MinersWife* pWife)
{
	switch (RandInt(0, 2))
	{
	case 0:

		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 拖地";

		break;

	case 1:

		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 洗碗";

		break;

	case 2:

		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 铺床";

		break;
	}
}

void DoHouseWork::Exit(MinersWife* pWife)
{
}
bool DoHouseWork::OnMessage(MinersWife* pWife, const Telegram& msg)
{
	
	return false;
}

#pragma endregion

#pragma region 上厕所
VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;

	return &instance;
}


void VisitBathroom::Enter(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 进入卫生间";
}


void VisitBathroom::Execute(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ":上厕所!";

	pWife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 离开卫生间";
}
bool VisitBathroom::OnMessage(MinersWife* pWiffe, const Telegram&)
{
	return false;
}
#pragma endregion

#pragma region 做饭

	//this is a singleton
CookStew* CookStew::Instance()
{
	static  CookStew instance;
	return &instance;
}

void CookStew::Enter(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 准备做饭";
}

void CookStew::Execute(MinersWife* pWife)
{
	//if not already cooking put the stew in the oven
	if (!pWife->Cooking())
	{
		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 生火做饭";

		//send a delayed message myself so that I know when to take the stew
		//out of the oven
		Dispatcher->DispatchMessages(1.5,                  //time delay
			pWife->ID(),           //sender ID
			pWife->ID(),           //receiver ID
			Msg_StewReady,        //msg
			NO_ADDITIONAL_INFO);

		pWife->SetCooking(true);
	}
}

void CookStew::Exit(MinersWife* pWife)
{
	SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 铺桌布";
}

bool CookStew::OnMessage(MinersWife* pWife, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_StewReady:
	{
						  std::cout << "\nMessage received by " << GetNameOfEntity(pWife->ID()) <<
							  " at time: " << Clock->GetCurrentTime();

						  SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						  std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": 饭好了 吃饭吧";

						  //let hubby know the stew is ready
						  Dispatcher->DispatchMessages(SEND_MSG_IMMEDIATELY,
							  pWife->ID(),
							  ent_Miner_Bob,
							  Msg_StewReady,
							  NO_ADDITIONAL_INFO);

						  pWife->SetCooking(false);

						  pWife->GetFSM()->ChangeState(DoHouseWork::Instance());
	}

		return true;

	}//end switch

	return false;
}

#pragma endregion