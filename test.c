#include <stdio.h>
#include "log_interface.h"

int main()
{
	int i = 0;
	int max = 1000;
	create_sock();
	for (i; i < max; i++)
	{
		create_msg(1, "log %s, %d, %s", "zhangjianxi", i, "client.c");
		sleep(1);
	}
	end_sock();
	return 1;
}
