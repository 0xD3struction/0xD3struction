#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

BOOL CALLBACK EnWinChld(HWND ChldHandle, LPARAM lPar)
{
	int WinLen;
	WinLen = GetWindowTextLengthA(ChldHandle)+1;
	 printf ("\t| winlen: %d\n",WinLen++);
	char * WinText = malloc(WinLen);
	GetWindowText(ChldHandle,WinText,WinLen);
	
	printf ("\t| text: %s\n\n",WinText);
	  
	  SetWindowText(ChldHandle,"HaCkeD By 0xD3struction");
	
	
	free(WinText);
}

BOOL CALLBACK EnWinProc(HWND WinHandle, LPARAM lPar)
{
	int WinLen;
	WinLen = GetWindowTextLengthA(WinHandle)+1;
	printf ("winlen: %d\n",WinLen++);
	char * WinText = malloc(WinLen);
	GetWindowText(WinHandle,WinText,WinLen);

	printf ("text: %s\n\n",WinText);
	SetWindowText(WinHandle,"HaCkeD By 0xD3struction");
	EnumChildWindows(WinHandle,&EnWinChld,0);
	  
	
	
	free(WinText);
}

int main(void)
{
  while(1)
  {
	EnumWindows(&EnWinProc,0);
	Sleep(500);
}
	system("pause");
	return 0;
}
