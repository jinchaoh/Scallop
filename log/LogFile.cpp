#include "LogFile.hpp"
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <cstring>


using namespace Scallop;

LogFile::LogFile()
	:	logFileName("log"),
		logPath("~/log/")
{ 
	setDate();
	setLogFullPath();
}

LogFile::LogFile(const string logBaseName)
	:	logFileName(logBaseName),
		logPath("~/log/")
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
	cout<<"logfile"<<endl;
}

void LogFile::setDate()
{
	
	cout<<"setdate"<<endl;
	char date_[80];
	memset(date_,0,sizeof(date_));
	time_t now;
	time(&now);
	struct tm *timelt;
	timelt = localtime(&now);	
	cout<<"setdate"<<endl;
	strftime(date_, 24, "%Y%m%d", timelt);
	cout<<"setdate"<<endl;
	date = date_;
	cout<<"setdate"<<endl;
}
void LogFile::setLogFullPath()
{
	logFullPath = logPath;
	logFullPath +=  logFileName;
	logFullPath += date;
	logFullPath += ".log";				
	cout<<"setlogfullpath"<<endl;
}

string LogFile::LogFile::getlogFullPath()
{
	cout<<"getlogfullpath"<<endl;
	return logFullPath;
}
