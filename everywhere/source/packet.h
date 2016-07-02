#ifndef __PACKET_H__
#define __PACKET_H__
#include<queue>
#include<cstdint>
#include<packetio.h>
using namespace std;
class Packet
{
public:
	Packet(int32_t m_num):PacketState(0),PacketTotalLen(0),PacketLeftLen(0),PakcetFilledLen(0){}
	int32_t Input(uint8_t *Bytes,int32_t Len);
	int32_t Output(uint8_t *Bytes,int32_t Len);
	int32_t Pkt_Get(string &Pkt);

private:
	int32_t Pkt_Fill( queue<uint8_t> &SrcBuf);
public:
	PacketIO *SockInfo;
	queue<uint8_t> Buf;	//store all flow data
	uint8_t PacketState;//indication packet state
	string  PacketBuf;	//store a packet data
	int32_t PacketTotalLen;
	int32_t PacketLeftLen;
	int32_t PakcetFilledLen;
};
#endif