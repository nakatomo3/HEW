#pragma once
using namespace std;
#include <string>
#include "Singleton.h"
class LogWriter : public Singleton<LogWriter> {
public:
	friend class Singleton<LogWriter>;

	void Log(const char*, ...);
	void LogWorning(const char* format, ...);
	void LogError(const char * format, ...);

private:
	LogWriter();
	~LogWriter();
};