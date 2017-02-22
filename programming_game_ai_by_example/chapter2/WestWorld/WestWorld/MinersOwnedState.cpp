#include"MinersOwnedState.h"
#include"Miner.h"
#include "EntityNames.h"
#include"misc/ConsoleUtils.h"
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
	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "�뿪���";
}
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
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

		pMiner->ChangeState(GoHomeAndSleepTillRested::Instance());

	}
	//�����ڿ�
	else
	{
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
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
#pragma endregion


#pragma region �ؼ���Ϣֱ�������ָ�
void GoHomeAndSleepTillRested::Enter(Miner *pMiner)
{
	if (pMiner->Location() != shack)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "��������";
		pMiner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTillRested::Execute(Miner *pMiner)
{
	//���۾ͼ����ڿ�
	if (!pMiner->Fatigued())
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "˯����ԣ�ȥ�ڿ�";
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());

	}
	else//˯��
	{
		pMiner->DecreaseFatigue();
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "ZZZZZZ....";
		
	}
}

void GoHomeAndSleepTillRested::Exit(Miner *pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	std::cout << '\n' << GetNameOfEntity(pMiner->ID()) << ":" << "�뿪����";
	
}
GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance()
{
	static GoHomeAndSleepTillRested instance;
	return &instance;
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
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "��ƣ�����ȥ�ư�";
	}
}

void QuenchThirst::Execute(Miner* pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "С��һ��";

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
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ":" << "�뿪�ưɣ��о�����";
}
QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;

	return &instance;
}
#pragma endregion