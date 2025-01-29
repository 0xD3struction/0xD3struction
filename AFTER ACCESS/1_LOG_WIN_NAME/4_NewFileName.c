#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void)
{
	time_t rawtime;
	struct tm* timeinfo;
    char FileName[34] = { 0 };
    
    while(1)
	{
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		sprintf(FileName,"Log_File_%d_%d_%d-%d-%d-%d.txt", timeinfo->tm_hour, timeinfo->tm_min, 
		        timeinfo->tm_sec,timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday);
		printf("%s\n",FileName);
		Sleep(10000); 
	}
}
