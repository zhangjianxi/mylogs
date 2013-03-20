#include <stdio.h>
#include "log_interface.h"

int main()
{
	write_logs("log %s, %s, %s", "zhangjianxi", "3", "client.c");
	return 1;
}
