#pragma once
#include "MinersWifeOwnedStates.h"
#include"MinersWife.h"
#include "misc/utils.h"
#include "EntityNames.h"
#include "msg/MessageDispatcher.h"
#include "time/CrudeTimer.h"
#include "MessageTypes.h"

#include<iostream>
#pragma region ȫ��״̬
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

#pragma region ������
//---------------------------------------DoHouseWork

DoHouseWork* DoHouseWork::Instance()
{
	static DoHouseWork instance;

	return &instance;
}


void DoHouseWork::Enter(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": ׼��������";
}


void DoHouseWork::Execute(MinersWife* pWife)
{
	switch (RandInt(0, 2))
	{
	case 0:

		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": �ϵ�";

		break;

	case 1:

		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": ϴ��";

		break;

	case 2:

		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": �̴�";

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

#pragma region �ϲ���
VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;

	return &instance;
}


void VisitBathroom::Enter(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": ����������";
}


void VisitBathroom::Execute(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ":�ϲ���!";

	pWife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": �뿪������";
}
bool VisitBathroom::OnMessage(MinersWife* pWiffe, const Telegram&)
{
	return false;
}
#pragma endregion

#pragma region ����

	//this is a singleton
CookStew* CookStew::Instance()
{
	static  CookStew instance;
	return &instance;
}

void CookStew::Enter(MinersWife* pWife)
{
	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": ׼������";
}

void CookStew::Execute(MinersWife* pWife)
{
	//if not already cooking put the stew in the oven
	if (!pWife->Cooking())
	{
		std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": ��������";

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

	std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": ������";
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
						  std::cout << "\n" << GetNameOfEntity(pWife->ID()) << ": ������ �Է���";

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