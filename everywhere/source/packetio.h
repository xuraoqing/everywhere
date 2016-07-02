#ifndef __PACKETIO_H__
#define __PACKETIO_H__
#include"winsock2.h"
class PacketIO
{
public:
	PacketIO(void){}
	PacketIO(int32_t m_num):Num(m_num){}
public:
	int32_t		Num;
	SOCKET		SockConn;
	SOCKADDR_IN	AddrClient;
};
#endif