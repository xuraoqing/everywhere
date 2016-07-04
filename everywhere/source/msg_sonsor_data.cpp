#include<iostream>
#include"msg_sensor_data.h"
#include"msg.h"
using namespace std;
Msg_Sensor_Data::Msg_Sensor_Data(void)
{
	Cmd = NMP_DATA_UPLOAD;
}

int32_t Msg_Sensor_Data::Input(Msg_Header &MsgHd,string &Payload)
{
	if(MsgHd.MsgType == MSG_REQUEST){
		cout<<endl;
		cout<<"received hearbeat request"<<endl;
	}
	else{
		return 0;
	}
	RequestNodeDataUploadNtf node_data;
	node_data.ParseFromString(Payload);
	string NodeId;
	NodeId = node_data.node_id();
	int data_index = 0,data_total;
	SensorData sensor_data;
	data_total = node_data.data_size();
	for(data_index = 0;data_index < data_total;data_index++){
		sensor_data = node_data.data(data_index);
	}
}
int32_t Msg_Sensor_Data::Output(Msg_Header &MsgHd,string &Payload)
{

}