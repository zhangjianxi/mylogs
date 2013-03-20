#include "log_interface.h"

void write_logs(const char *msg, ...)
{
	char message[2048] = {0};
	char szMsg[1024] = {0};
	va_list pArg;
	va_start(pArg, msg);
	vsnprintf(szMsg, 1023, msg, pArg);
	va_end(pArg);
	//printf("%s \n", szMsg);

	time_t nTime = time(NULL);
	struct tm *pDate = localtime(&nTime);

	if (NULL == pDate)
	{
		return;
	}

	int nYear = 1900 + pDate->tm_year;
	int nMonth = pDate->tm_mon + 1;
	int nDay = pDate->tm_mday;
	int nHour = pDate->tm_hour;
	int nMin = pDate->tm_min;
	int nSec = pDate->tm_sec;

	sprintf(message, "%d-%d-%d %d:%d:%d", nYear, nMonth, nDay, nHour, nMin, nSec);

	strcat(message, " ");
	strcat(message, szMsg);
	printf("%s \n", message);
}
