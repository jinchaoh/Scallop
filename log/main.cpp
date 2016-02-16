#include "LogFile.hpp"
#include "Logger.hpp"
#include "Logdef.hpp"
#include <iostream>

using namespace Scallop;
using namespace std;
int main()
{
	long i = 99999999999;
	while(i--)
	{
		ERROR("%s====[%d]\n","this is my test ","error log");
		ERROR("%s","haoexin");	
	}
	return 0;
} 
