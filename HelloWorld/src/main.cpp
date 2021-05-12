#include <iostream>

//int main1();

class Logger
{
private:
	int logLevel = 0;
public:
	enum class LogTypes : unsigned short
	{
		logTypeWarning = 0, logTypeError, logTypeInfo
	};
	/*int logTypeWarning = 0;
	int logTypeError = 1;
	int logTypeInfo = 2;*/
public:
	void logToConsole(LogTypes type, const char* message)
	{
		std::cout << "[ " << getTypeFromInt(type) << " ] : " << message << std::endl;
	}
	static Logger& getInstance()
	{
		static Logger newLog;
		return newLog;
	}
private:
	const char* getTypeFromInt(LogTypes type)
	{
		switch (type)
		{
		case LogTypes::logTypeWarning:
			return "WARNING";
		case LogTypes::logTypeError:
			return "ERROR";
		case LogTypes::logTypeInfo:
			return "INFO";
		default:
			return "UNKNOWN TYPE";
		}
	}
};
int main()
{
	//main1();
	//return 0;
	//logger instance =  logger::getinstance();
	//std::cout << sizeof logger::logtypes << std::endl;
	
	//instance.logToConsole(Logger::logTypeError, "This is an error type");
	Logger log, log2;
	log.logToConsole(Logger::LogTypes::logTypeInfo, "this is an info");
	log2.logToConsole(Logger::LogTypes::logTypeError, "test message");
	return 0;
}