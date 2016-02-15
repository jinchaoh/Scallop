#include "LogFile.hpp"
#include "Logger.hpp"

using namespace Scallop;

Logger::Logger()
{
	m_LogFile = LogFile();
}

/*
bool Logger::createNewLogFile()
{
	printf("create new log file!\n");
	logFile = fopen(m_LogFile.logFullPath.c_str(), "ab+");
	if (logFile == NULL)
	{
		printf("open false!\n");
		return false;
	}
}


bool isNeedOpenNewFile()
{
	
}
*/

bool Logger::printLog(const char* file_name, int line, 
		const char* func, const char* fmt, ...)
{
	if(using_mult_thread)
	{
		pthread_mutex_lock(&mutex);
	}
	
	if(!openLogFile())
	{
		return false;
	}
	
	string day, hour, tm;
	get_year_month_day(day);
	get_hour_min_sec(hour);
	
	tm = day + " " + hour; 
	fprintf(logFile, "[%s] ", tm.c_str());
	fprintf(logFile, "[%s:%d] ", file_name, line);
	fprintf(logFile, "[%s()]: ", func);
	
	va_list ap;
	va_start(ap, fmt);
	vfprintf(logFile, fmt, ap);
	va_end(ap);
	
	fprintf(logFile, "\n");
	fflush(logFile);
	
	if(using_mult_thread)
	{
		pthread_mutex_unlock(&mutex);
	}
}

bool Logger::openLogFile()
{	
	logPath = m_LogFile.getlogFullPath();
	logFile = fopen(logPath.c_str(), "ab+");
	if (logFile == NULL)
	{
		printf("open false!\n");
		return false;
	}
}

void Logger::get_year_month_day(string& res)
{
	time_t cur_time = time(NULL);
	struct tm * timeinfo = localtime(&cur_time);

	char buffer[] = {"yyyy-mm-dd"};
	strftime(buffer, sizeof(buffer), "%F", timeinfo);
	res = string(buffer);
}

void Logger::get_hour_min_sec(string& res)
{
	time_t cur_time = time(NULL);
	struct tm * timeinfo = localtime(&cur_time);

	char buffer[] = {"hh:mm:ss"};
	strftime(buffer, sizeof(buffer), "%T", timeinfo);
	res = string(buffer);
}

Logger::~Logger(){}