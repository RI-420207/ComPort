#pragma once
#include <windows.h>

static int TIMEOUT = 1000;

class COMPort
{
private:
	HANDLE Port;
public:
	COMPort(const char*);
	unsigned long Write(const char*, unsigned int);
	char* Read();
	~COMPort(void);
};

