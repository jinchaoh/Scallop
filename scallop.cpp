#include <iostream>
#include "cJSON.h"

using namespace std;

char text[] = "{\"timestamp\":\"2013-11-19\",\"value\":1}";
int main(int argc,char *argv[]){

	cJSON *json;
	json = cJSON_Parse(text);
	if(!json)
	{
		cout<<"parse json error["<<cJSON_GetErrorPtr()<<"]"<<endl;
	}
	else
	{
		cJSON *findTimestamp=cJSON_GetObjectItem(json,"timestamp");
		if(findTimestamp != NULL)
		{
			cout<<"timestamp=:"<<findTimestamp->valuestring<<endl;
		}
		cJSON *findValue=cJSON_GetObjectItem(json,"value");
		if(findValue != NULL)
		{
			cout<<"value=:"<<findValue->valueint<<endl;
		}	
	cJSON_Delete(json); 
	}
	return 0;
}
