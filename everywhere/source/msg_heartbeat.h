#ifndef MSG_HEARTBEAT_H_
#include<string>
#include<vector>
#include"msg_object.h"
class Msg_Heartbeat:public MsgType
{
public:
	Msg_Heartbeat(void);	
	int32_t Input(Msg_Header &MsgHd,string &Payload);
	int32_t Output(Msg_Header &MsgHd,string &Payload);
public:
	Command Cmd;
};
#endif