#include <stdlib.h>
#include <stdio.h>

int main(int argc,char*argv[])
{
	printf("[0xD3struction Create NOP File]\n");
	unsigned short i;
	FILE *NopFile = NULL;
	if(!(NopFile=fopen("nop_file.nop","wb")))
		 return 0;
    for(i=0;i<0x1F;++i)
        fputc(0x90,NopFile);
    fclose(NopFile);
}
