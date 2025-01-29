/*

! FOR EDUCATIONAL PURPOSES ONLY ! 
FROM VIDEO : https://www.youtube.com/watch?v=OSZrT22hibI

0xD3struction 2o25

*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


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
	   printf ("(%d)[%s]\n",WinLen,WinText);
	
       free(WinText);
    
}

int main(void)
{
	while(1)
	{
		printf(".\n");
		EnumWindows(&EnWinProc,0);
		Sleep(10000);
	}
}
