#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

BOOL CALLBACK EnWinChld(HWND ChldHandle, LPARAM lPar)
{
	int WinLen;
	char * WinText;
	
	if(!(WinLen = GetWindowTextLengthA(ChldHandle)))
	   return 1;
	
	if(!IsWindowVisible(ChldHandle)) 
	  return 1; 
	 
	   printf ("\t| winlen: %d\n",WinLen++);

	   WinText = malloc(WinLen);
	   GetWindowText(ChldHandle,WinText,WinLen);
	   printf ("\t| text: %s\n\n",WinText);
	
       free(WinText);
    

}



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
	   
	   EnumChildWindows(WinHandle,&EnWinChld,0);
	
       free(WinText);
    
}

int main(void)
{
  
	EnumWindows(&EnWinProc,0);
	Sleep(500);

	system("pause");
	return 0;
}
