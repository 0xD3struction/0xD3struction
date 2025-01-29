/*

! FOR EDUCATIONAL PURPOSES ONLY ! 
FROM VIDEO : https://www.youtube.com/watch?v=OSZrT22hibI

0xD3struction 2o25

*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

FILE * LogFile = 0;

BOOL CALLBACK EnWinProc(HWND WinHandle, LPARAM lPar)
{
	int WinLen;
	char * WinText;
	
	if(!(WinLen = GetWindowTextLengthA(WinHandle)))
	   return 1;
	
	if(!IsWindowVisible(WinHandle)) 
	  return 1;
	 
	   WinLen++;

	   WinText = malloc(WinLen);
	   GetWindowText(WinHandle,WinText,WinLen);
	   fprintf (LogFile,"(%d)[%s]\n",WinLen,WinText);
	   
       free(WinText);
    
}

int main(void)
{
	char FileName[32] = { 0 };

	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	sprintf(FileName, "Log_File_%d_%d_%d.txt\0", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	
	if(!(LogFile=fopen(FileName,"a")))
	  return 0;
	
	printf("[+] %s CREATED !\n",FileName);
	
	while(1)
    {
    	fprintf(LogFile,".\n");
    	EnumWindows(&EnWinProc,0);
    	Sleep(1000);
	}
	
}
