ʹ��˵����
����VS2010+win7���±�����winzlog����Դ���github��
1��������ļ���xxx.lib,xxx.dll, zlog.h, zlog.conf����ֱ�ӿ�����Դ��Ŀ¼
2����������Ԥ����ָ�
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

3������ͷ�ļ�zlog.h

enjoy it��


��ע��
1�����ɺ��ԣ���x86ƽ̨����ʱ��ʹ�õ���pthreadVSE2.dll������x64ƽ̨����ʱ��ʹ�õ���pthreadVC2.dll��
2��zlog.conf��zlog�������ļ�������ʹ�ÿ��Բ���Zlog UsersGuide-CN.pdf��ָ����
3������ʾ����
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
