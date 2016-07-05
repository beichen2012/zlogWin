#pragma once
#ifdef _MSC_VER
//#include <winsock2.h>
// #ifndef WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// #define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// #include <winsock2.h>
// //#include <windows.h>
// #endif
// #include <winsock2.h>
#include "event.h"

#include <time.h>
#include <stdio.h>

int strcasecmp(char *a, char *b) {
	return(_stricmp(a, b));
}

struct tm *localtime_r(long *clock, struct tm *res)
{
	_localtime32_s(res, clock);
	return(res);
}

int gettimeofday(struct timeval *tp, struct timezone *tz)
{
	SYSTEMTIME st;

	if (tp != NULL) {
		tp->tv_sec = _time32(NULL);
		GetLocalTime(&st);
		tp->tv_usec = 1000L * st.wMilliseconds;
	} /* if */

	return(0);
}

int fsync(int fd) {
	return FlushFileBuffers(fd);
	//return(fflush(fp));
}

int winopen(char *f, int m, int p) {
	//HANDLE h = CreateFile(f,FILE_APPEND_DATA,
	HANDLE h = CreateFileA(f, FILE_APPEND_DATA,
		(FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE),
		NULL,
		OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	return(h);
}
int winwrite(int fd, char *data, int len) {
	int numb = 0;
	int status;

	status = WriteFile(fd, data, len, &numb, NULL);
	if (status == 0) 
		return(-1);
	return(numb);
}
int winclose(int fd) {
	//if (fd != INVALID_HANDLE_VALUE)

		if (CloseHandle(fd))
		{
			return(0);
		}

	return(-1);
}


#define O_SYNC 0x4010

#endif