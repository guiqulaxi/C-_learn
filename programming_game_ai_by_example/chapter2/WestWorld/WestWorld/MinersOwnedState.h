#pragma once
#include "State.h"
class EnterMineAndDigForNugget:public State
{
public:
	//����ģʽ
	static EnterMineAndDigForNugget*Instance();


	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

private:
	EnterMineAndDigForNugget(){}
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);

};

class VisitBankAndDepositGold :public State
{
public:
	//����ģʽ
	static VisitBankAndDepositGold*Instance();


	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

private:
	VisitBankAndDepositGold(){}
	VisitBankAndDepositGold(const VisitBankAndDepositGold&);
	VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);

};
class GoHomeAndSleepTillRested :public State
{
public:
	//����ģʽ
	static GoHomeAndSleepTillRested*Instance();


	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

private:
	GoHomeAndSleepTillRested(){}
	GoHomeAndSleepTillRested(const GoHomeAndSleepTillRested&);
	GoHomeAndSleepTillRested& operator=(const GoHomeAndSleepTillRested&);

};
class QuenchThirst :public State
{
public:
	//����ģʽ
	static QuenchThirst*Instance();


	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

private:
	QuenchThirst(){}
	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);

};
