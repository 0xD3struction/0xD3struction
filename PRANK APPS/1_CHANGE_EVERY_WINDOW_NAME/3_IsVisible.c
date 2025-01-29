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
	 
	   printf ("winlen: %d\n",WinLen++);

	   WinText = malloc(WinLen);
	   GetWindowText(WinHandle,WinText,WinLen);
	   printf ("text: %s\n\n",WinText);
	
       free(WinText);
    
}

int main(void)
{
	EnumWindows(&EnWinProc,0);
	system("pause");
	return 0;
}
