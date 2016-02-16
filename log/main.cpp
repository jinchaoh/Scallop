#include "LogFile.hpp"
#include "Logger.hpp"
#include "Logdef.hpp"
#include <iostream>

using namespace Scallop;
using namespace std;
int main()
{
	ERROR("%s====[%d]\n","this is my test ","error log");
	ERROR("%s","haoexin");
	return 0;
} 
