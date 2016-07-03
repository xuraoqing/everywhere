#ifndef __MSG_NWPB_H__
#define __MSG_NWPB_H__
#include<cstdint>
#include<string>
#include"nwpb.pb.h"
#include"msg_header.h"
class Msg_NWPb
{
public:
	Msg_NWPb(void);
	virtual int32_t Input(Msg_Header &Hd,string &Payload);
	virtual int32_t Output(Msg_Header &Hd,string &Payload);
};
#endif