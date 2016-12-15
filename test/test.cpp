#include "stdafx.h"
#include <stdio.h>
#include "../zlogWin/src/zlog.h"
#include <Windows.h>

int main(int argc, char** argv)
{
	int rc = -1;
	zlog_category_t *zc = NULL;

	_putenv("ZLOG_CHECK_FORMAT_RULE=rule.log");
	_putenv("ZLOG_PROFILE_ERROR=error.log");
	rc = zlog_init("zlog.conf");

	if (rc) {
		printf("init failed\n");
		return -1;
	}

	zc = zlog_get_category("cat");
	if (!zc) {
		printf("get cat fail\n");
		zlog_fini();
		return -2;
	}
	int i = 0;
	while (true)
	{
		zlog_info(zc, "this is idx:%d", i++);
		printf("the idx:%d\n", i);
		zlog_error(zc, "this is fatal error!:%d", i);
	}
	zlog_fini();

	return 0;
}
