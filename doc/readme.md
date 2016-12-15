只需要一个头文件`zlog.h`，然后引入对应的dll即可：
```c++
#ifdef _DEBUG
#ifndef _WIN64
#pragma comment(lib, "zlogx86d.lib")
#else
#pragma comment(lib, "zlogx64d.lib")
#endif
#else
#ifndef _WIN64
#pragma comment(lib, "zlogx86.lib")
#else
#pragma comment(lib, "zlogx64.lib")
#endif
#endif
```
一个例子如下(对应的conf文件见同级目录)：
```c++
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
```
