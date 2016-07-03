#include<iostream>
#include<stdint.h>
#include<process.h>
#include "everywhere.h"
#include <QtGui/QApplication>
#include"msg_nwpb.h"
#include"packet.h"

using namespace std;

#pragma comment(lib,"ws2_32.lib")

void Server_Thread(void *SocketHandle);
void main_task(void *ptr);

int ConCount=0;

void Server_Thread(void *SocketHandle)
{
	uint8_t recvBuf[512];int32_t recvLen;
	string  PBBuf;
	Packet	Pkt(0);
	Msg_NWPb Msg;
	Msg_Header MsgHd;
	Pkt.SockInfo = (PacketIO *)SocketHandle;
	MsgHd.SockInfo = Pkt.SockInfo;
	cout<<"NO"<<Pkt.SockInfo->Num<<"enter"<<endl;

	do{
		recvLen = recv(Pkt.SockInfo->SockConn,(char*)recvBuf,512,0);
		if(recvLen <= 0){
			closesocket(Pkt.SockInfo->SockConn);
			break;
		}
		cout<<endl;
		cout<<"received length:"<<recvLen;
		Pkt.Input(recvBuf,recvLen);
		Pkt.Pkt_Get(PBBuf);
		if(PBBuf.size() != 0){
			Msg.Input(MsgHd,PBBuf);
			PBBuf.clear();
		}
	}while(1);
	cout<<endl<<"NO"<<Pkt.SockInfo->Num<<"exit"<<endl;
	free(SocketHandle);
	_endthread();
}

void main_task(void *ptr)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	uint16_t ListenPort=8001;
	int err;
	wVersionRequested = MAKEWORD(2,0);
	err = WSAStartup(wVersionRequested,&wsaData);
	if(err != 0){
		cout<<"WSAStartup failure"<<endl;
		return;
	}
	if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0){
		WSACleanup();
		std::cout<<"WSA version != 2.0"<<endl;
		return;
	}
	SOCKET sockSrv = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(ListenPort);

	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	listen(sockSrv,5);
	cout<<"server listen at:"<<ListenPort<<endl;
	while(1){
		//SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&(sockInfoPtr->addrClient),&len);
		SOCKET sockConn=accept(sockSrv,NULL,NULL);
		if(sockConn == -1){
			cout<<"accept errno=%s"<<strerror(errno);
		}
		else{
			cout<<"new client:"<<endl;
		}
		ConCount++;
		PacketIO *SockInfoPtr= new PacketIO(ConCount); 
		SockInfoPtr->SockConn = sockConn;
		SockInfoPtr->Num = ConCount;
		_beginthread(Server_Thread,0,SockInfoPtr);
	}
	WSACleanup();
}

int main(int argc, char *argv[])
{
	_beginthread(main_task,0,NULL);
	QApplication a(argc, argv);
	everywhere w;
	w.show();
	return a.exec();
}
