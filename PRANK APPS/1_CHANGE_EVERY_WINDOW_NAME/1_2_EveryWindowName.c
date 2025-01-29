#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


BOOL CALLBACK EnWinProc(HWND WinHandle, LPARAM lPar)
{
	int WinLen;
	if(!(WinLen = GetWindowTextLengthA(WinHandle)))
	   return 1;
	
	printf ("WinLen: %d\n",WinLen++);

	char * WinText = malloc(WinLen);
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
