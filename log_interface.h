#ifndef _LOG_INTERFACE_H
#define _LOG_INTERFACE_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
void write_logs(const char *msg, ...);

#endif
