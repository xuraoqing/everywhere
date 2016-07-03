#include<iostream>
#include"msg_heartbeat.h"
#include"msg.h"
using namespace std;
Msg_Heartbeat::Msg_Heartbeat(void)
{
	Cmd = HEARBEAT;
}
int32_t Msg_Heartbeat::Input(Msg_Header &MsgHd,string &Payload)
{
	if(MsgHd.MsgType == MSG_REQUEST){
		cout<<endl;
		cout<<"received hearbeat request"<<endl;
	}
	else{
		return 0;
	}
	HeartbeatRqst Rqst;
	Rqst.ParseFromString(Payload);
	if(Rqst.has_expires()){
		cout<<"heartbeat expires:"<<Rqst.expires()<<endl;
	}
	if(Rqst.has_time()){
		cout<<"heartbeat time:"<<Rqst.time()<<endl;
	}
	HeartbeatRsps Rsps;
	Rsps.set_expires(Rqst.expires());
	Rsps.set_capability(0);
	Rsps.set_nodes(100);
	Rsps.set_sessions(MsgHd.Session);
	string StrBuf;
	Rsps.SerializeToString(&StrBuf);
	Msg_Header Hd=MsgHd;
	Hd.MsgType = MSG_RESPONSE;
	Output(Hd,StrBuf);
	return 0;
}
int32_t Msg_Heartbeat::Output(Msg_Header &MsgHd,string &Payload)
{	
	Msg MsgSend;
	return MsgSend.Output(MsgHd,Payload);
}
