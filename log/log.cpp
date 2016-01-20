#include "log.hpp"

void LogContent::getDateTime(string &res)
{
	std::string strTime = boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time()); 
	int pos = strTime.find('T');    
    strTime.replace(pos,1,std::string("-"));    
    strTime.replace(pos + 3,0,std::string(":"));    
    strTime.replace(pos + 6,0,std::string(":"));  
	
	res = strTime;
}

void LogContent::printLog( const char* fileName, long lineNum, const char* func, const char* fmt, ...)
{	
	getDateTime(dateTime);
	
	fprintf(file, "[%s] ", dateTime.c_str());
	fprintf(file, "[%s:%d] ", file_name, line);
	fprintf(file, "[%s()]: ", func);
	
	va_list ap;
	va_start(ap, fmt);
	vfprintf(file, fmt, ap);
	va_end(ap);

	fprintf(file, "\n");
	fflush(file);
}

void Log::setDate(string &res)
{
	res = boost::gregorian::to_iso_string(boost::gregorian::day_clock::local_day()); 
}

void Log::setFileName(string &logFileName)
{
	setDate(date);
	logFileName = "scallop-"+date;
}

void Log::setLogPath(string &logPath)
{
	logPath = "~/scallop_log";
}

void Log::openLogFile(char * log_file_name)
{
	
}

void Log::isOpenFile(FILE* file)
{
	
}