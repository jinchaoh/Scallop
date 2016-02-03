#ifndef _LOGFILE_HPP
#define _LOGFILE_HPP

#include<iostream>
#include<string>
using namespace std;
namespace Scallop
{
	class LogFile
	{
		public:
			LogFile();
			LogFile(const string logBaseName);
			LogFile(const string logBaseName,
					const string logPath);
			
			void setLogFullPath();
			void setDate();
			string getlogFullPath();
			
			~LogFile();
		
		private:
			string logFileName;
			string logPath;
			string date;
			string logFullPath;
	};
}
#endif
