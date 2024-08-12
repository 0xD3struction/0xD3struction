/*

     ToHide.c 
       
     FROM VIDEO:
	   https://www.youtube.com/watch?v=BKZ1MfQHC-c

     DO NOT USE THIS CODE !

     0xD3struction

    2o24
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
	int MsgRet = 0;
	printf("[0xD3struction HIDE CONSOLE WINDOW]\n");
	printf("[ + ]MESSAGE FROM CONSOLE[ + ]\n");
	
	MsgRet = MessageBox(0,"[ + ]  MESSAGE FROM CONSOLE [ + ]","[0xD3struction HIDE CONSOLE WINDOW]\n",MB_ICONINFORMATION|MB_YESNO);
	printf("MessageBox RET = %s\n\n",(MsgRet==6) ? "YES" : "NO");
	
}
