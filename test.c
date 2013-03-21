#include <stdio.h>
#include "log_interface.h"

int main()
{
	create_sock();
	//while (1)
	//{
	//	send_msg(0, "%s \n", "zhangjianxi");
		//sleep(2);
	//}
	//end_sock();	
	create_msg(1, "log %s, %s, %s", "zhangjianxi", "44", "client.c");
	end_sock();
	return 1;
}
