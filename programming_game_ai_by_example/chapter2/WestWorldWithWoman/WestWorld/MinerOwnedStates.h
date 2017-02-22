#pragma once
#include "State.h"
class Miner;
class EnterMineAndDigForNugget:public State<Miner>
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

class VisitBankAndDepositGold :public State<Miner>
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
class GoHomeAndSleepTillRested :public State<Miner>
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
class QuenchThirst :public State<Miner>
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
