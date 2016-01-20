#ifndef _LOG_H
#define _LOG_H

#include<iostream>
#include<string>
#include <boost/date_time/gregorian/gregorian.hpp>

namespace Scallop
{
	class LogContent
	{
		public:
		virtual void getDateTime(string &res);
		virtual void printLog(const char* fileName, long lineNum, const char* func, const char* fmt, ...);
		
		private:
		string dateTime;

	};

	class Log: public LogContent
	{
		public:
		void setDate(string &res);
		void setFileName(string &logFileName);
		void setLogPath(string &logPath);
		void openLogFile(char * log_file_name);
		void isOpenFile(FILE* file);
		
		private:
		string date;
		string dateTime;
		FILE* file;
		LogContent* logContent;
		string logFileName;
	};
	
	#define DEBUG_LOG(...) \
	do \
	{ \
		Log* p = LogContainer::get(); \
		p->print(__FILE__, __LINE__, __FUNCTION__ ,__VA_ARGS__); \
	} while(0)

	
}
#endif