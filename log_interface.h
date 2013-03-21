#ifndef _LOG_INTERFACE_H
#define _LOG_INTERFACE_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


#define UINT unsigned int

int ret;
int sock_fd;
struct sockaddr_in addr;

int create_sock();
void create_msg(UINT u_type, const char *msg, ...);
int end_sock();

#endif
