#pragma once
#include "fsm/State.h"
class Miner;
class EnterMineAndDigForNugget:public State<Miner>
{
public:
	//����ģʽ
	static EnterMineAndDigForNugget*Instance();


	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	virtual bool OnMessage(Miner* pMiner, const Telegram& msg);
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

	virtual bool OnMessage(Miner* pMiner, const Telegram& msg);
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

	virtual bool OnMessage(Miner* pMiner, const Telegram& msg);
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

	virtual bool OnMessage(Miner* pMiner, const Telegram& msg);
private:
	QuenchThirst(){}
	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);

};

class EatStew :public State<Miner>
{
public:
	//����ģʽ
	static EatStew*Instance();


	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	virtual bool OnMessage(Miner* pMiner, const Telegram& msg);
private:
	EatStew(){}
	EatStew(const EatStew&);
	EatStew& operator=(const EatStew&);

};
