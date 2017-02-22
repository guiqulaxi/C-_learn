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

		return "亲爱的，我回来了";

	case Msg_StewReady:

		return "饭好了";

	default:

		return "未识别消息";
	}
}
