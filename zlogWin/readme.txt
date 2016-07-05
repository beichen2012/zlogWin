使用说明：
基于VS2010+win7重新编译了winzlog。（源码见github）
1、将相关文件（xxx.lib,xxx.dll, zlog.h, zlog.conf），直接拷贝到源码目录
2、包含以下预编译指令：
#ifdef _DEBUG
#ifndef _WIN64
#pragma comment(lib, "zlogvc140x86d.lib")
#else
#pragma comment(lib, "zlogvc140x64d.lib")
#endif
#else
#ifndef _WIN64
#pragma comment(lib, "zlogvc140x86.lib")
#else
#pragma comment(lib, "zlogvc140x64.lib")
#endif
#endif

3、包含头文件zlog.h

enjoy it。


备注：
1、（可忽略）在x86平台编译时，使用的是pthreadVSE2.dll，而在x64平台编译时，使用的是pthreadVC2.dll。
2、zlog.conf是zlog的配置文件。具体使用可以参照Zlog UsersGuide-CN.pdf的指导。
3、代码示例：
#include "stdafx.h"
#include <stdio.h>
#include "zlog.h"
#ifdef _DEBUG
#ifndef _WIN64
#pragma comment(lib, "zlog_vc100x86.debug.lib")
#else
#pragma comment(lib, "zlog_vc100x64.debug.lib")
#endif
#else
#ifndef _WIN64
#pragma comment(lib, "zlog_vc100x86.release.lib")
#else
#pragma comment(lib, "zlog_vc100x64.release.lib")
#endif
#endif
int main(int argc, char** argv)
{
	int rc = -1;
	zlog_category_t *zc = NULL;

	rc = zlog_init(".\\zlog.conf");
	
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

	zlog_info(zc, "hello, zlog");

	zlog_fini();
	
	
	return 0;
}
