#include"MinerOwnedStates.h"
#include"Miner.h"
#include "EntityNames.h"
#include"misc/ConsoleUtils.h"
#include "time/CrudeTimer.h"
#include "MessageTypes.h"
#include "msg/MessageDispatcher.h"
#include<iostream>

#pragma region �������ھ���
void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
	if (pMiner->Location() != goldmine)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "������";
		pMiner->ChangeLocation(goldmine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "�ڵ�һ�����";
	if (pMiner->PocketsFull())
	{
		
		pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if (pMiner->Thirsty())
	{
		pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "�뿪���";
}
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}
//��Ϣ����
bool EnterMineAndDigForNugget::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}
#pragma endregion


#pragma region �������д�Ǯ
void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
	if (pMiner->Location() != bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "��������";
		pMiner->ChangeLocation(bank);
	}
}
void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
	int goldCarried = pMiner->GoldCarried();
	pMiner->AddToWealth(goldCarried);
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":"
		<< "����" << goldCarried << "�����ƣ�" << pMiner->Wealth();

	if (pMiner->Wealth() >= ComfortLevel)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Ǯ�㹻�ˣ��ؼ�Ъ����";

		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTillRested::Instance());

	}
	//�����ڿ�
	else
	{
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}


}
void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "�뿪����";
	
}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}


//��Ϣ����
bool VisitBankAndDepositGold::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}

#pragma endregion


#pragma region �ؼ�
void GoHomeAndSleepTillRested::Enter(Miner *pMiner)
{
	if (pMiner->Location() != shack)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "׼���ؼ�";

		pMiner->ChangeLocation(shack);

		//let the wife know I'm home
		Dispatcher->DispatchMessages(SEND_MSG_IMMEDIATELY, //time delay
			pMiner->ID(),        //ID of sender
			ent_Elsa,            //ID of recipient
			Msg_HiHoneyImHome,   //the message
			NO_ADDITIONAL_INFO);
	}
}

void GoHomeAndSleepTillRested::Execute(Miner *pMiner)
{
	//if miner is not fatigued start to dig for nuggets again.
	if (!pMiner->Fatigued())
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "��Ϣ��ϣ�ƣ��ֵ�ָ�";

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}

	else
	{
		
		pMiner->DecreaseFatigue();
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "ZZZZ... ";
	}
	
}

void GoHomeAndSleepTillRested::Exit(Miner *pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "ֹͣ��Ϣ";
	
}
GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance()
{
	static GoHomeAndSleepTillRested instance;
	return &instance;
}
//��Ϣ����
bool GoHomeAndSleepTillRested::OnMessage(Miner* pMiner, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_StewReady:

		std::cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		std::cout << "\n" << GetNameOfEntity(pMiner->ID())
			<< ": ���Ͼ����Է� !";

		pMiner->GetFSM()->ChangeState(EatStew::Instance());

		return true;

	}//end switch

	return false; //send message to global message handler
}
#pragma endregion

#pragma region ���

//------------------------------------------------methods for QuenchThirst



void QuenchThirst::Enter(Miner* pMiner)
{
	if (pMiner->Location() != saloon)
	{
		pMiner->ChangeLocation(saloon);

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "����ȥ�ư�";
	}
}

void QuenchThirst::Execute(Miner* pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "С��һ��";

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}

	else
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\nERROR!\nERROR!\nERROR!";
	}
}

void QuenchThirst::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "�뿪�ưɣ��о�����";
}
QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;

	return &instance;
}
//��Ϣ����
bool QuenchThirst::OnMessage(Miner* pMiner, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}
#pragma endregion

#pragma region �Է�
EatStew* EatStew::Instance()
{
	static EatStew instance;
	return &instance;
}


void EatStew::Enter(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "׼���Է�";
}

void EatStew::Execute(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "�Է��С�����";

	pMiner->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "����";

}

  bool EatStew::OnMessage(Miner* pMiner, const Telegram& msg)
  {
	  return false;
  }
#pragma endregion
