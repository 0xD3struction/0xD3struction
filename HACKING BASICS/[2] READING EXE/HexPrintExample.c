/*
     [C] HEXPRINT EXAMPLE
    
     FROM VIDEO:
	   https://www.youtube.com/watch?v=JNe7dQZ6K8A

     DO NOT USE THIS CODE !

     0xD3struction

     2o24

*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <windows.h>
#include <winnt.h>
char * FILE_BUFF;
long   FILE_SIZE = 0;

/* ToPrint - mem offset | len - how many bytes | sep = separator */
void HexPrint(unsigned char *ToPrint,unsigned short len,char sep)
{
     printf("_________________________________________________________________________________________\n");
     printf("\t[Hex Print]\t[0x%08X]\t[%d bytes]\n",ToPrint,len);
     printf("-----------------------------------------------------------------------------------------\n");
     printf(" Offset\t%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c%04X%c\n",
	        sep,0,sep,1,sep,2,sep,3,sep,4,sep,5,sep,6,sep,7,sep,8,sep,9,sep,10,sep,11,sep,12,sep,13,sep,14,sep,15,sep,16,sep);
     printf("-----------------------------------------------------------------------------------------\n");
     unsigned short i,j;
    
     for(i=0,j=0;i<len;++i)
     {
         if(i%16==0)
         {
            printf("\n\r %c%04X%c\t%c",sep,j,sep,sep);
            j=j+0x0010;
         } 
         printf("0x%02X%c",ToPrint[i],sep);
        
        
     }
     printf("\n-----------------------------------------------------------------------------------------\n");
     printf("_________________________________________________________________________________________\n");
}

unsigned short FileRead(char * ThisFile)
{
	FILE * File = 0;
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
	printf("\t\t\t[0xD3struction] PE HEADER LOCATION\n\n");

	
	if(argc!=2)
	{
		printf("[!] No Arg. Self Read\n\n");
		printf("File PATH :\n\t%s\n\n",argv[0]);
		if(!FileRead(argv[0]))
	  	return 0;
	}
	else
	{
		printf("[+] ARG FILE : %s\n\n",argv[1]);
		if(!FileRead(argv[1])) return 0;
	}
	
	printf("FILE[0] = '%c' \n",FILE_BUFF[0]);
    printf("FILE[1] = '%c' \n",FILE_BUFF[1]);
    
    unsigned char Pe_Offset;
	Pe_Offset = (char)FILE_BUFF[0x3C];
	
    printf("PE HEADER OFFSET (+0x3C) : 0x%X \n\n",Pe_Offset);
    HexPrint(FILE_BUFF,512,'|');
    system("pause");
	return 0;
	
}
