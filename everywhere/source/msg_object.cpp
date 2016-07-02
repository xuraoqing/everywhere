#include "msg_object.h"
#include "msg_heartbeat.h"
MsgObjectCreate::MsgObjectCreate(void)
{
	MsgType* Msg = new MsgType;
	Msg->PMsg = new Msg_Heartbeat;
	MsgObject.push_back(Msg);
}
Msg_NWPb* MsgObjectCreate::MsgObjectGet(Command m_Cmd)
{
	vector<MsgType*>::iterator iter;
	for(iter = MsgObject.begin();iter != MsgObject.end();iter++){
		if((*iter)->Cmd == m_Cmd){
			return ((*iter)->PMsg);
		}
	}
	return ;
}