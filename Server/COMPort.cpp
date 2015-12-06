#include "COMPort.h"

COMPort::COMPort(const char* portname){
	Port = CreateFileA(
			portname,
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			OPEN_EXISTING,
			FILE_FLAG_OVERLAPPED,
			NULL
			);
	SetCommMask(Port, EV_RXCHAR);
	SetupComm(Port, 1500, 1500);

	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = TIMEOUT;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
	CommTimeOuts.WriteTotalTimeoutConstant = TIMEOUT;

	if (!SetCommTimeouts(Port, &CommTimeOuts)) {
		Port = 0;
	}

	DCB ComDCM;

	memset(&ComDCM, 0, sizeof(ComDCM));
	ComDCM.DCBlength = sizeof(DCB);
	GetCommState(Port, &ComDCM);
	ComDCM.BaudRate = DWORD(9600);
	ComDCM.ByteSize = 8;
	ComDCM.Parity = NOPARITY;
	ComDCM.StopBits = ONESTOPBIT;
	ComDCM.fAbortOnError = TRUE;
	ComDCM.fDtrControl = DTR_CONTROL_DISABLE;
	ComDCM.fRtsControl = RTS_CONTROL_DISABLE;
	ComDCM.fBinary = TRUE;
	ComDCM.fParity = FALSE;
	ComDCM.fInX = FALSE;
	ComDCM.fOutX = FALSE;
	ComDCM.XonChar = 0;
	ComDCM.XoffChar = (unsigned char)0xFF;
	ComDCM.fErrorChar = FALSE;
	ComDCM.fNull = FALSE;
	ComDCM.fOutxCtsFlow = FALSE;
	ComDCM.fOutxDsrFlow = FALSE;
	ComDCM.XonLim = 128;
	ComDCM.XoffLim = 128;

	if (!SetCommState(Port, &ComDCM)) {
		CloseHandle(Port);
		Port = 0;
	}



}
unsigned long COMPort::Write(const char* data, unsigned int size){
	unsigned long written = 0;
	WriteFile(Port, data, size, &written, 0);
	return written;
}
char* COMPort::Read(){
	const int READ_TIME = 1000;
	OVERLAPPED sync = {0};
	unsigned long wait = 0, read = 0, state = 0, write = 0;
	char buf[1024], *data;
	sync.hEvent = CreateEvent(NULL, TRUE, TRUE, NULL);

	WaitCommEvent(Port, &state, &sync);
	wait = WaitForSingleObject(sync.hEvent, READ_TIME);
	if(wait == WAIT_OBJECT_0){
		ReadFile(Port, buf, 1024, &read, &sync);
		wait = WaitForSingleObject(sync.hEvent, READ_TIME);
		if(wait == WAIT_OBJECT_0)
			if(GetOverlappedResult(Port, &sync, &read, false)){
				//Write(data, 1);
				data = new char[read + 1];
				data[read] = '\0';
				strncpy(data, buf, read);
				CloseHandle(sync.hEvent);
				return data;
			}
	}
	CloseHandle(sync.hEvent);
	return '\0';
}
COMPort::~COMPort(){
	CloseHandle(Port);
}