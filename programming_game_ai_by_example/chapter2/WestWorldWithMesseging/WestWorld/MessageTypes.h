#pragma once

#include <string>

enum message_type
{
	Msg_HiHoneyImHome,
	Msg_StewReady,
};


inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case Msg_HiHoneyImHome:

		return "�װ��ģ��һ�����";

	case Msg_StewReady:

		return "������";

	default:

		return "δʶ����Ϣ";
	}
}
