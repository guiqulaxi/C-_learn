#pragma once
#include <iostream>
#include <math.h>


struct Telegram
{
	//发送者
	int          Sender;

	//接收者
	int          Receiver;

	
	//消息本身
	int          Msg;

	
	//消息延迟发送时间
	double       DispatchTime;

	//额外信息
	void*        ExtraInfo;


	Telegram() :DispatchTime(-1),
		Sender(-1),
		Receiver(-1),
		Msg(-1)
	{}


	Telegram(double time,
		int    sender,
		int    receiver,
		int    msg,
		void*  info = NULL) : DispatchTime(time),
		Sender(sender),
		Receiver(receiver),
		Msg(msg),
		ExtraInfo(info)
	{}

};


//消息之间的最小间隔
const double SmallestDelay = 0.25;


inline bool operator==(const Telegram& t1, const Telegram& t2)
{
	return (fabs(t1.DispatchTime - t2.DispatchTime) < SmallestDelay) &&
		(t1.Sender == t2.Sender) &&
		(t1.Receiver == t2.Receiver) &&
		(t1.Msg == t2.Msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
	if (t1 == t2)
	{
		return false;
	}

	else
	{
		return  (t1.DispatchTime < t2.DispatchTime);
	}
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t)
{
	os << "时间: " << t.DispatchTime << "  发送者: " << t.Sender
		<< "   接收者: " << t.Receiver << "   消息: " << t.Msg;

	return os;
}

//去引用
template <class T>
inline T DereferenceToType(void* p)
{
	return *(T*)(p);
}