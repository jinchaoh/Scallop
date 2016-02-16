#define ERROR(...) \
	do \
	{ \
		Logger * p_logger = new Logger(); \
		p_logger->printLog(__FILE__, __LINE__, __FUNCTION__ ,__VA_ARGS__); \
		delete p_logger;\
	} while(0)
	
	
