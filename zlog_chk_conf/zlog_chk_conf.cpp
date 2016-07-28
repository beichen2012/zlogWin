// zlog_chk_conf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
* This file is part of the zlog Library.
*
* Copyright (C) 2011 by Hardy Simpson <HardySimpson1984@gmail.com>
*
* Licensed under the LGPL v2.1, see the file COPYING in base directory.
*/

//#include "fmacros.h"
#include "../../zlogWin/zlogWin/src/fmacros.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <unistd.h>

#include "zlog.h"
#include "../zlogWin/src/version.h"
//#include "version.h"
#include "getopt.h"


int main(int argc, char *argv[])
{
	int rc = 0;
	int op;
	int quiet = 0;
	static const char *help =
		"useage: zlog-chk-conf [conf files]...\n"
		"\t-q,\tsuppress non-error message\n"
		"\t-h,\tshow help message\n"
		"zlog version: " ZLOG_VERSION "\n";

	while ((op = getopt(argc, argv, "qhv")) > 0) {
		if (op == 'h') {
			fputs(help, stdout);
			return 0;
		}
		else if (op == 'q') {
			quiet = 1;
		}
	}

	argc -= optind;
	argv += optind;

	if (argc == 0) {
		fputs(help, stdout);
		return -1;
	}

	_putenv("ZLOG_PROFILE_ERROR=d:\\debug.log");
	_putenv("ZLOG_CHECK_FORMAT_RULE=d:\\rule.log");
	_putenv("ZLOG_PROFILE_ERROR=d:\\error.log");
	//setenv("ZLOG_PROFILE_ERROR", "/dev/stderr", 1);
	//setenv("ZLOG_CHECK_FORMAT_RULE", "1", 1);

	while (argc > 0) {
		rc = zlog_init(*argv);
		if (rc) {
			printf("\n---[%s] syntax error, see error message above\n",
				*argv);
			printf("test done!");
			getchar();
			exit(2);
		}
		else {
			zlog_fini();
			if (!quiet) {
				printf("--[%s] syntax right\n", *argv);
			}
		}
		argc--;
		argv++;
	}
	printf("test done!");
	getchar();
	exit(0);
}
