#include"MinerOwnedStates.h"
#include"Miner.h"
#include "EntityNames.h"
#include"misc/ConsoleUtils.h"
#include "time/CrudeTimer.h"
#include "MessageTypes.h"
#include "msg/MessageDispatcher.h"
#include<iostream>

#pragma region 进入金矿挖掘金块
void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
	if (pMiner->Location() != goldmine)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "进入金矿";
		pMiner->ChangeLocation(goldmine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "挖到一个金块";
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
	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "离开金矿";
}
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}
//消息处理
bool EnterMineAndDigForNugget::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}
#pragma endregion


#pragma region 进入银行存钱
void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
	if (pMiner->Location() != bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "进入银行";
		pMiner->ChangeLocation(bank);
	}
}
void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
	int goldCarried = pMiner->GoldCarried();
	pMiner->AddToWealth(goldCarried);
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":"
		<< "存入" << goldCarried << "。共计：" << pMiner->Wealth();

	if (pMiner->Wealth() >= ComfortLevel)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "钱足够了！回家歇着了";

		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTillRested::Instance());

	}
	//继续挖矿
	else
	{
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}


}
void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "离开银行";
	
}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}


//消息处理
bool VisitBankAndDepositGold::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}

#pragma endregion


#pragma region 回家
void GoHomeAndSleepTillRested::Enter(Miner *pMiner)
{
	if (pMiner->Location() != shack)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "准备回家";

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
			<< "休息完毕，疲劳值恢复";

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

	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "停止休息";
	
}
GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance()
{
	static GoHomeAndSleepTillRested instance;
	return &instance;
}
//消息处理
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
			<< ": 马上就来吃饭 !";

		pMiner->GetFSM()->ChangeState(EatStew::Instance());

		return true;

	}//end switch

	return false; //send message to global message handler
}
#pragma endregion

#pragma region 解渴

//------------------------------------------------methods for QuenchThirst



void QuenchThirst::Enter(Miner* pMiner)
{
	if (pMiner->Location() != saloon)
	{
		pMiner->ChangeLocation(saloon);

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "渴了去酒吧";
	}
}

void QuenchThirst::Execute(Miner* pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "小酌一杯";

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
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "离开酒吧，感觉不错";
}
QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;

	return &instance;
}
//消息处理
bool QuenchThirst::OnMessage(Miner* pMiner, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}
#pragma endregion

#pragma region 吃饭
EatStew* EatStew::Instance()
{
	static EatStew instance;
	return &instance;
}


void EatStew::Enter(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "准备吃饭";
}

void EatStew::Execute(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "吃饭中。。。";

	pMiner->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "吃完";

}

  bool EatStew::OnMessage(Miner* pMiner, const Telegram& msg)
  {
	  return false;
  }
#pragma endregion
