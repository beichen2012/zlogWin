// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
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