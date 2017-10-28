#pragma once
#include <stdarg.h>
#include "zlog.h"

//init
extern "C" int LOG_INIT(const char* config_file = "zlog.conf",const char* category_name = "cat");
//de-init
extern "C" int LOG_FINI();

#ifndef NO_LOG_OUTPUT
//打开Zlog的日志输出
extern zlog_category_t* g_zc;
#define LOGI(...) zlog_info(g_zc, __VA_ARGS__)
#define LOGE(...) zlog_error(g_zc, __VA_ARGS__)
#define LOGD(...) zlog_debug(g_zc, __VA_ARGS__)
#define LOGW(...) zlog_warn(g_zc, __VA_ARGS__)
#define LOGN(...) zlog_notice(g_zc, __VA_ARGS__)
#define LOGF(...) zlog_fatal(g_zc, __VA_ARGS__)

#else //关掉所有日志的输出
#define LOGI //
#define LOGE //
#define LOGD //
#define LOGW //
#define LOGN //
#define LOGF //
#endif