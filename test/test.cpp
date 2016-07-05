#include "stdafx.h"
#include <stdio.h>
#include "../zlogWin/src/zlog.h"

int main(int argc, char** argv)
{
	int rc = -1;
	zlog_category_t *zc = NULL;

	rc = zlog_init("D:\\projects\\zlogWin\\zlogWin\\zlog.conf");

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
	while(true)
	{
		zlog_info(zc, "hello, zlog");
	}
	

	zlog_fini();


	return 0;
}
