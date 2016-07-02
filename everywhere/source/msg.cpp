#include"msg.h"
#include"msg_heartbeat.h"
Msg::Msg(void)
{
	MsgType* Msg = new Msg_Heartbeat;
	Msg->Cmd = HEARBEAT;
	Parsers.push_back(Msg);
}
int32_t Msg::Input(Msg_Header &MsgHd,string &Payload)
{
	Request Req;Response Rsps;Notify Ntf;
	const string *StrBuf;
	if(MsgHd.MsgType == MSG_REQUEST){
		Req.ParseFromString(Payload);
		MsgHd.Session = Req.session();
		MsgHd.Sequence = Req.sequence();
		MsgHd.Cmd = Req.command();
		StrBuf = &Req.content();	
	}
	else if(MsgHd.MsgType == MSG_RESPONSE){				
		Rsps.ParseFromString(Payload);
		MsgHd.Session = Rsps.session();
		MsgHd.Sequence = Rsps.sequence();
		MsgHd.Cmd = Rsps.command();
		StrBuf = &Rsps.content();
	}
	else if(MsgHd.MsgType == MSG_NOTIFY){				
		Ntf.ParseFromString(Payload);
		MsgHd.Session = Ntf.session();
		MsgHd.Cmd = Ntf.command();
		StrBuf = &Ntf.content();
	}
	for(vector<MsgType*>::iterator iter = Parsers.begin();iter != Parsers.end();iter++){	
		if(MsgHd.Cmd == (*iter)->Cmd){
			(*iter)->Input(MsgHd,(string)(*StrBuf));
			break;
		}
	}
	return 0;
}
int32_t Msg::Output(Msg_Header &MsgHd,string &Payload)
{	
	Request Rqst;
	Response Rsps;
	Notify   Ntf;
	Msg_NWPb MsgNWPb;
	string Buf;
	if(MsgHd.MsgType == MSG_REQUEST){
		Rqst.set_session(MsgHd.Session);
		Rqst.set_sequence(MsgHd.Sequence);
		Rqst.set_command(MsgHd.Cmd);
		Rqst.set_content((const void*)Payload.data(),Payload.size());
		Rqst.SerializeToString(&Buf);
	}
	else if(MsgHd.MsgType == MSG_RESPONSE){
		Rsps.set_session(MsgHd.Session);
		Rsps.set_sequence(MsgHd.Sequence);
		Rsps.set_command(MsgHd.Cmd);
		Rsps.set_err(Response_Error_NWPB_ERROR_OK);
		Rsps.set_content((const void*)Payload.data(),Payload.size());
		Rsps.SerializeToString(&Buf);
	}
	else if(MsgHd.MsgType == MSG_NOTIFY){
		Ntf.set_session(MsgHd.Session);
		Ntf.set_command(MsgHd.Cmd);
		Ntf.set_content((const void*)Payload.data(),Payload.size());
		Ntf.SerializeToString(&Buf);
	}
	MsgNWPb.Output(MsgHd,Buf);
	return 0;
}
size_t Msg::Msg_Parser_Add(MsgType* MsgParser)
{
	Parsers.push_back(MsgParser);
	return Parsers.size();
}