/*
     C OS VARS EXAMPLE

     FROM VIDEO:
	   https://www.youtube.com/watch?v=s4p41u60Zio

     DO NOT USE THIS CODE !

     0xD3struction

    2o24
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("[0xD3struction] HACKING BASICS : OS VARS.\n\n");
	printf("ALLUSERSPROFILE = %s\n\n",getenv("ALLUSERSPROFILE"));
	printf("USERNAME = %s\n\n",getenv("USERNAME"));
	printf("USER PROFILE = %s\n\n",getenv("USERPROFILE"));
	printf("COMPUTERNAME = %s\n\n",getenv("COMPUTERNAME"));
	printf("HOMEDRIVE = %s\n\n",getenv("HOMEDRIVE"));
	printf("ProgramFiles = %s\n\n",getenv("ProgramFiles"));
	printf("WinDir = %s\n\n",getenv("WinDir"));
	system("pause");
	return 0;
}
