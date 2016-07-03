#ifndef __MSG_OBJECT_H__
#define __MSG_OBJECT_H__
#include "msg_header.h"
#include <vector>

class MsgType
{
public:
virtual int32_t Input(Msg_Header &MsgHd,string &Payload)=0;
virtual int32_t Output(Msg_Header &MsgHd,string &Payload)=0;
public:
	Command	Cmd;	
};

#endif