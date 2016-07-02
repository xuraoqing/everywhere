#ifndef __MSG_H__
#include<string>
#include<vector>
#include"msg_nwpb.h"
#include"msg_object.h"

class Msg:public Msg_NWPb
{
public:
	Msg(void);	
	int32_t Input(Msg_Header &MsgHd,string &Payload);
	int32_t Output(Msg_Header &MsgHd,string &Payload);
	size_t Msg_Parser_Add(MsgType* MsgParser);
private:
	vector<MsgType*> Parsers;
};
#endif