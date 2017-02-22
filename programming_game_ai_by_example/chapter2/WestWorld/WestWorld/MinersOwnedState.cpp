#include"MinersOwnedState.h"
#include"Miner.h"
#include "EntityNames.h"
#include"misc/ConsoleUtils.h"
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
		pMiner->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if (pMiner->Thirsty())
	{
		pMiner->ChangeState(QuenchThirst::Instance());
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

		pMiner->ChangeState(GoHomeAndSleepTillRested::Instance());

	}
	//继续挖矿
	else
	{
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
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
#pragma endregion


#pragma region 回家休息直到体力恢复
void GoHomeAndSleepTillRested::Enter(Miner *pMiner)
{
	if (pMiner->Location() != shack)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "进入屋子";
		pMiner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTillRested::Execute(Miner *pMiner)
{
	//不累就继续挖矿
	if (!pMiner->Fatigued())
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "睡你麻痹，去挖矿";
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());

	}
	else//睡觉
	{
		pMiner->DecreaseFatigue();
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "ZZZZZZ....";
		
	}
}

void GoHomeAndSleepTillRested::Exit(Miner *pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "离开屋子";
	
}
GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance()
{
	static GoHomeAndSleepTillRested instance;
	return &instance;
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
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "伙计，渴了去酒吧";
	}
}

void QuenchThirst::Execute(Miner* pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "小酌一杯";

		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
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
#pragma endregion