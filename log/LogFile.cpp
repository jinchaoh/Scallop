#include "LogFile.hpp"
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <cstring>


using namespace Scallop;

LogFile::LogFile()
	:	logFileName("log"),
		logPath("/home/hankin/log/")
{ 
	setDate();
	setLogFullPath();
}

LogFile::LogFile(const string logBaseName)
	:	logFileName(logBaseName),
		logPath("/home/hankin/log/")
{
	setDate();
	setLogFullPath();
}

LogFile::LogFile(const string logBaseName,
		const string logPath)
	:	logFileName(logBaseName),
		logPath(logPath)	
{
	setDate();
	setLogFullPath();
}

void LogFile::setDate()
{
	char date_[80];
	memset(date_,0,sizeof(date_));
	time_t now;
	time(&now);
	struct tm *timelt;
	timelt = localtime(&now);	
	strftime(date_, 24, "%Y%m%d", timelt);
	date = date_;
}

void LogFile::setLogFullPath()
{
	logFullPath = logPath;
	logFullPath +=  logFileName;
	logFullPath += date;
	logFullPath += ".log";				
}

string LogFile::LogFile::getlogFullPath()
{
	return logFullPath;
}

LogFile::~LogFile()
{
	
}
