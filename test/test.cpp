#include "stdafx.h"
#include <stdio.h>
#include "../zlogWin/src/zlog.h"
#include <Windows.h>
//#include <WinZlog.h>

int main(int argc, char** argv)
{
	int rc = -1;
	zlog_category_t *zc = NULL;

	_putenv("ZLOG_PROFILE_ERROR=d:\\debug.log");
	_putenv("ZLOG_CHECK_FORMAT_RULE=d:\\rule.log");
	_putenv("ZLOG_PROFILE_ERROR=d:\\error.log");
	rc = zlog_init("D:\\projects\\zlogWin\\Debug\\zlog.conf");

	if (rc) {
		printf("init failed\n");
		return -1;
	}

	zc = zlog_get_category("catc");
	if (!zc) {
		printf("get cat fail\n");
		zlog_fini();
		return -2;
	}
	zlog_info(zc, "hello");
	zlog_fini();
	
	//LOG_INIT();
	////while(true)
	////{
	////	LOGI("hello zlog-win!");
	////	Sleep(10);
	////	//zlog_notice(zc, "hello, zlog");
	////}
	//
	//LOGI("oooo");
	//zlog_fini();
	//LOG_FINI();
	//printf("done");
	//getchar();
	return 0;
}
