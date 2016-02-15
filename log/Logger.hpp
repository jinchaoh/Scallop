#ifndef _LOGGER_HPP
#define _LOGGER_HPP
#include <pthread.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

namespace Scallop
{
	class Logger
	{	
		public:
			Logger();
			bool openLogFile();
			bool createNewLogFile();
			bool isNeedOpenNewFile();
			void get_year_month_day(string& res);
			void get_hour_min_sec(string& res);
			bool printLog(const char* file_name, int line, const char* func, const char* fmt, ...);
			~Logger();
			
			enum LogLevel
			{
				TRACE,
				DEBUG,
				INFO,
				WARN,
				ERROR,
				FATAL,
				NUM_LOG_LEVELS,
			};
			
		private:
			LogFile m_LogFile;
			FILE* logFile;
			string logPath;
			bool using_mult_thread;
			pthread_mutex_t mutex;
			
	};
}
#endif