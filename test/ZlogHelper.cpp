#include "stdafx.h"
#include "ZlogHelper.h"

#ifndef NO_LOG_OUTPUT
#include <stdio.h>
#include <stdarg.h> /* for va_list */
#include <Windows.h>
//link the library
#ifdef _DEBUG
#pragma comment(lib, "zlogWind.lib")
#else
#pragma comment(lib, "zlogWin.lib")
#endif

//global 
zlog_category_t* g_zc = NULL;

//macros

#define INNER_LOGI(...) \
	zlog_info(g_zc,...)


extern "C" int LOG_INIT(const char* config_file,const char* category_name)
{
	_putenv("ZLOG_CHECK_FORMAT_RULE=rule.log");
	_putenv("ZLOG_PROFILE_ERROR=error.log");
	int ret = zlog_init(config_file);
	if (ret)
	{
		printf("init failed!\n");
		return -1;
	}
	g_zc = zlog_get_category(category_name);
	if (!g_zc)
	{
		printf("get category failed!\n");
		zlog_fini();
		return -2;
	}
	return 0;
}
extern "C" int LOG_FINI()
{
	zlog_fini();
	return 0;
}

#else
extern "C" int LOG_INIT(char* config_file, char* category_name)
{
	return 0;
}
extern "C" int LOG_FINI()
{
	retrun 0;
}
#endif
