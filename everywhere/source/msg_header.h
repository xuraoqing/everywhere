#ifndef __MESSAGE_HEADER_H__
#define __MESSAGE_HEADER_H__
#include<cstdint>
#include<packetio.h>
#include"nwpb.pb.h"
using namespace std;

typedef enum{
	MSG_REQUEST   = 0,
	MSG_RESPONSE  = 1,
	MSG_NOTIFY    = 2
}Msg_Type_t;

class Msg_Header
{
public:
	Msg_Header(void){
		Session  = 0;
		Sequence = 0;
		MsgType  = MSG_REQUEST;
		Cmd      = HEARBEAT;
	}
public:
	PacketIO *SockInfo;
	uint32_t Session;
	uint32_t Sequence;
	Command  Cmd;
	Msg_Type_t  MsgType;	
};
#endif