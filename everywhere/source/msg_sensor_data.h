#ifndef MSG_SENSOR_DATA_H_
#define MSG_SENSOR_DATA_H_
#include<string>
#include<vector>
#include"msg_object.h"
class Msg_Sensor_Data:public MsgType
{
public:
	Msg_Sensor_Data(void);
	int32_t Input(Msg_Header &MsgHd,string &Payload);
	int32_t Output(Msg_Header &MsgHd,string &Payload);
public:
	Command Cmd;
};


#endif