#include<iostream>
#include<stdint.h>
#include<process.h>
#include"everywhere.h"
#include<QtGui/QApplication>
#include"msg_nwpb.h"
#include"packet.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include <fstream>
#include <qerrormessage.h>

using namespace std;
using namespace rapidjson;

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
	//¼ÓÔØÃüÁî
	string file_buf,line;
	ifstream infile("sys_config.txt",ios::in);
	if(infile.fail()){
		exit(-1);
	}
	file_buf.clear();
	while(!infile.eof()){
		getline(infile,line);
		file_buf.append(line);
	}
	infile.close();

	//json½âÎö
	char *json_buf = (char*)malloc(file_buf.length() + 1);
	memcpy(json_buf,file_buf.data(),file_buf.length());
	json_buf[file_buf.length()]='\0';
	Document document;
	if(document.ParseInsitu((json_buf)).HasParseError()){
		exit(-1);
	}
	assert(document.IsObject());
	assert(document.HasMember("listen"));
	string listen_ip;
	uint16_t listen_port;

	listen_port = document["listen"]["port"].GetInt();
	listen_ip = document["listen"]["ip"].GetString();
	free(json_buf);

	WORD wVersionRequested;
	WSADATA wsaData;
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
	
	addrSrv.sin_addr.S_un.S_addr=inet_addr(listen_ip.c_str());
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(listen_port);

	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	listen(sockSrv,5);
	cout<<"server listen at:"<<listen_port<<endl;
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
