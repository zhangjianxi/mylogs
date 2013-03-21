#include "log_interface.h"

int create_sock()
{
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(addr.sin_zero), 8);

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (0 > sock_fd)
	{
		write_logs(0, "create_sock failed");
		return -1;
	}

	ret = connect(sock_fd, (struct sockaddr*)&addr, sizeof(struct sockaddr));

	if (-1 == ret)
	{
		write_logs(0, "connect to the server failed");
		return -1;
	}

	return 0;
}


int send_msg(UINT u_type, const char *msg, ...)
{
	char msg_send[1024];
	var_list 
}

int end_sock()
{
	close(sock_fd);
}

void write_logs(UINT u_type, const char *msg, ...)
{
	char message[2048] = {0};
	char szMsg[1024] = {0};
	char *pDirPath = NULL;
	char szLogPath[1024] = {0};
	
	/*
	 *user va_list to create the **argv
	 *va_start to read the **argv	 
	 */
	va_list pArg;
	va_start(pArg, msg);
	vsnprintf(szMsg, 1023, msg, pArg);
	va_end(pArg);

	/*
	 *time_t used to save the time
	 *localtime get the time now
	 */
	time_t nTime = time(NULL);
	struct tm *pDate = localtime(&nTime);

	if (NULL == pDate)
	{
		return;
	}

	/*
	 *get year month day hour min sec
	 */
	int nYear = 1900 + pDate->tm_year;
	int nMonth = pDate->tm_mon + 1;
	int nDay = pDate->tm_mday;
	int nHour = pDate->tm_hour;
	int nMin = pDate->tm_min;
	int nSec = pDate->tm_sec;

	/*
	 *create the logpath by the time year-month-day
	 *if the file is exist then add the message to this file
	 */
	pDirPath = "/logs";
	sprintf(szLogPath, "%s/%d-%d-%d", pDirPath, nYear, nMonth, nDay);
	
	/*
	 *access if the path is exist
	 */
	if (0 != access(pDirPath, 0))
	{
		if (0 != mkdir(pDirPath, 0775))
		{
			return;
		}
	}

	FILE *pLoger = fopen(szLogPath, "a");
	if (NULL == pLoger)
	{
		return;
	}

	/*
	 *create the logs by **argv message and the time create this log
	 */
	sprintf(message, "%d-%d-%d %d:%d:%d", nYear, nMonth, nDay, nHour, nMin, nSec);
	strcat(message, " ");
	strcat(message, szMsg);
	
	fprintf(pLoger, "%s \n", message);
	fclose(pLoger);
}
