/*

     TimeDateStamp.c 
       
     FROM VIDEO:
	   https://www.youtube.com/watch?v=BKZ1MfQHC-c

     DO NOT USE THIS CODE !

     0xD3struction

    2o24
*/




#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winnt.h>

char * FILE_BUFF;
long   FILE_SIZE = 0;
FILE * File = 0;


unsigned short FileRead(char * ThisFile)
{
	
	size_t BytesReaded = 0;
	
	
	if(!(File = fopen(ThisFile,"rb")))
	{
	  printf("[-] Fopen(%s) FAIL!\n",ThisFile);
	  return 0;
	}
	
	printf("[+] fopen SUCCESS !\n");	
		
	if(fseek(File,0,SEEK_END)!=0)
	{
	  printf("[-] fseek FAIL!\n");
	  return 0;
	}
	
	printf("[+] fseek SUCCESS !\n");
	
	if((FILE_SIZE=ftell(File))==-1)
	{
	  printf("[-] ftell FAIL!\n");
	  return 0;
	}
	
	printf("[+] ftell SUCCESS !\n");
	printf("[+] File SIZE %d\n",FILE_SIZE);
	
	rewind(File);
	
	if(!(FILE_BUFF = calloc(FILE_SIZE,1)))
	{
		printf("[-] Memory alocate FAIL !\n");
		fclose(File);
	 	return 0;
	}
	
	printf("[+] Memory Alocate SUCCESS !\n");
	
	 
	if(FILE_SIZE!=(BytesReaded=fread(FILE_BUFF,1,FILE_SIZE,File)))
	 {
	 	fclose(File);
	 	printf("[-] File SIZE != BYTES READED \n");
	 	return 0;
	 }
	 
	printf("[+] File READED !\n\n");
	
	fclose(File);
	return 1;
}

int main(int argc, char * argv[])
{
	char * Name;
	FILE * ToWrite =0; 
	IMAGE_NT_HEADERS32 *NTHeaders;
	IMAGE_SECTION_HEADER SectionHeader;
	
	printf("\t\t\t[0xD3struction] Changing IMAGE_FILE_HEADER.TimeDateStamp \n\n");

	
	if(argc!=2)
	{
		printf("[!] No Arg [!]\n\n");
		printf("Usage : %s <EXE File>\n\n",argv[0]);
	  	return 0;
	}
	else
	{
		printf("[+] ARG FILE : %s\n",argv[1]);
		if(!FileRead(argv[1])) return 0;
		Name = argv[1];
		Name[0]='D';
		Name[1]='3';
		printf("[+] OUTPUT FILE NAME : %s \n\n",Name);
	}
	
	printf("FILE[0] = '%c' \n",FILE_BUFF[0]);
    printf("FILE[1] = '%c' \n",FILE_BUFF[1]);
    
    unsigned char Pe_Offset;
	Pe_Offset = (char)FILE_BUFF[0x3C];
	
    printf("PE HEADER OFFSET (+0x3C) : 0x%X \n\n",Pe_Offset);
    printf("IMAGE NT HEADER size : %d \n",sizeof(NTHeaders));
   
	NTHeaders = (IMAGE_NT_HEADERS32*)(FILE_BUFF+Pe_Offset);
	
	printf("\tTimeDateStamp: [BEFORE] 0x%08X\n",NTHeaders->FileHeader.TimeDateStamp);
    NTHeaders->FileHeader.TimeDateStamp = 0xD3D3D3D3;
    printf("\tTimeDateStamp: [AFTER] 0x%08X\n",NTHeaders->FileHeader.TimeDateStamp);
	
	if(!(ToWrite=fopen(Name,"wb"))) return 0;
	fwrite(FILE_BUFF,1,FILE_SIZE,ToWrite);
	fclose(ToWrite);
	
	printf("[+] FILE %s WITH NEW TIME DATE STAMP CREATED!\n\n",Name);
	
    system("pause");
	return 0;
	
}
