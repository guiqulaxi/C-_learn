#pragma once
#include <iostream>
#include <math.h>


struct Telegram
{
	//������
	int          Sender;

	//������
	int          Receiver;

	
	//��Ϣ����
	int          Msg;

	
	//��Ϣ�ӳٷ���ʱ��
	double       DispatchTime;

	//������Ϣ
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


//��Ϣ֮�����С���
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
	os << "ʱ��: " << t.DispatchTime << "  ������: " << t.Sender
		<< "   ������: " << t.Receiver << "   ��Ϣ: " << t.Msg;

	return os;
}

//ȥ����
template <class T>
inline T DereferenceToType(void* p)
{
	return *(T*)(p);
}