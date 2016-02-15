#include "LogFile.hpp"
#include "Logger.hpp"
#include <iostream>

using namespace Scallop;
using namespace std;
int main()
{
	LogFile * p_logFile = new LogFile("hello");
	cout<< p_logFile->getlogFullPath() << endl;
	return 0;
} 
