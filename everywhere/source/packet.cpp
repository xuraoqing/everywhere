#include"packet.h"
#include<iostream>
using namespace std;

int32_t Packet::Input(uint8_t *Bytes,int32_t Len)
{	int Count;
	for(Count = 0;Count < Len;Count++){
		Buf.push(*Bytes);
		Bytes++;
	}
	return Count;
}
int32_t Packet::Output(uint8_t *Bytes,int32_t Len)
{
	cout<<"send packet len="<<Len+4<<endl;
	uint32_t LenFlag = Len;
	send(SockInfo->SockConn,(const char*)&LenFlag,4,0);
	return send(SockInfo->SockConn,(const char*)Bytes,Len,0);
}
/*
return actual filled length
*/
int32_t Packet::Pkt_Fill(queue<uint8_t> &SrcBuf)
{
	int32_t BufLen = SrcBuf.size();
	if(PacketLeftLen <= BufLen){
		while(PacketLeftLen){
			PacketBuf += SrcBuf.front();
			PacketLeftLen--;
			SrcBuf.pop();
		}
		return PacketBuf.size();//packet ready
	}
	else{
		int32_t ReturnLen = BufLen;
		while(BufLen--){
			PacketBuf += SrcBuf.front();
			SrcBuf.pop();
		}
		PacketLeftLen -= ReturnLen;
		return ReturnLen;//packet not ready
	}
}
/*buf structure
length  `			octets length  `			octets
4B(Little endian)	....   4B(Little endian)	....
*/
int32_t Packet::Pkt_Get(string &Pkt)
{
	uint32_t Temp;
	if(PacketState == 0){
		if(Buf.size() >= 4){
			Temp = Buf.front();
			Buf.pop();
			PacketTotalLen = Temp;

			Temp = Buf.front();
			Buf.pop();
			PacketTotalLen |= (Temp<<8);
			
			Temp = Buf.front();
			Buf.pop();
			PacketTotalLen |= (Temp<<16);
			
			Temp = Buf.front();
			Buf.pop();
			PacketTotalLen |= (Temp<<24);
			PacketLeftLen = PacketTotalLen;
		}
		else{
			return 0;
		}
	}
	Pkt_Fill(Buf);
	if(PacketLeftLen == 0){
		PacketState = 0;
		/*for(int32_t PktLen = 0;PktLen < PacketTotalLen;PktLen++){
			Pkt += PacketBuf.at(PktLen);
			PacketBuf.erase(PktLen,1);
		}*/
		Pkt = PacketBuf;
		return Pkt.length();//packet ready
	}
	else{
		PacketState = 1;
		return 0;
	}
}