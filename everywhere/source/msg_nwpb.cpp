#include<iostream>
#include<string>
#include"msg_nwpb.h"
#include"msg.h"
#include"packet.h"
using namespace std;

Msg_NWPb::Msg_NWPb(void)
{
}
int32_t Msg_NWPb::Input(Msg_Header &Hd,string &Payload)
{
	NWPb	MsgNWPb;
	Msg SubMsg;
	string  StrMsg;
	Msg_Header MsgHd = Hd;

	MsgNWPb.ParseFromString(Payload);
	if(MsgNWPb.has_rqst()){
		const Request &Rqst = MsgNWPb.rqst();
		Rqst.SerializeToString(&StrMsg);
		MsgHd.MsgType = MSG_REQUEST;		
	}
	else if(MsgNWPb.has_rsps()){
		const Response &Rsps = MsgNWPb.rsps();
		Rsps.SerializeToString(&StrMsg);
		MsgHd.MsgType = MSG_RESPONSE;
	}
	else if(MsgNWPb.has_ntf()){
		const Notify &Ntf = MsgNWPb.ntf();
		Ntf.SerializeToString(&StrMsg);
		MsgHd.MsgType = MSG_NOTIFY;
	}
	SubMsg.Input(MsgHd,StrMsg);
	MsgNWPb.Clear();
	return Payload.size();
}
int32_t Msg_NWPb::Output(Msg_Header &Hd,string &Payload)
{
	Packet Pkt(0);
	Pkt.SockInfo = Hd.SockInfo;
	NWPb MsgNWPb;
	MsgNWPb.clear_rqst();
	MsgNWPb.clear_rsps();
	MsgNWPb.clear_ntf();
	if(Hd.MsgType == MSG_REQUEST){
		cout<<"send request"<<endl;
		Request *Rqst = new Request;
		Rqst->ParseFromString(Payload);
		MsgNWPb.set_allocated_rqst(Rqst);
		MsgNWPb.SerializeToString(&Pkt.PacketBuf);
	}
	else if(Hd.MsgType == MSG_RESPONSE){
		cout<<"send response"<<endl;
		Response *Rsps = new Response;
		Rsps->ParseFromString(Payload);
		MsgNWPb.set_allocated_rsps(Rsps);
		MsgNWPb.SerializeToString(&Pkt.PacketBuf);
	}
	else if(Hd.MsgType == MSG_NOTIFY){
		cout<<"send notify"<<endl;
		Notify *Ntf = new Notify;
		Ntf->ParseFromString(Payload);
		MsgNWPb.set_allocated_ntf(Ntf);
		MsgNWPb.SerializeToString(&Pkt.PacketBuf);
	}
	else{
		return 0;
	}
	return Pkt.Output((uint8_t*)Pkt.PacketBuf.data(),Pkt.PacketBuf.size());
}