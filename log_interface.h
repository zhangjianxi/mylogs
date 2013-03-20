#ifndef _LOG_INTERFACE_H
#define _LOG_INTERFACE_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define UINT unsigned int

void write_logs(UINT u_type, const char *msg, ...);

#endif
