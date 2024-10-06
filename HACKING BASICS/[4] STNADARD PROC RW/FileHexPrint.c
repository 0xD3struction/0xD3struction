#include <stdlib.h>
#include <stdio.h>

int FILE_SIZE = 0;
char * GLOBAL_FILE_BUFFER;

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

unsigned short SelfRead(char * ThisFile)
{
	FILE * File = 0;
	size_t BytesReaded = 0;
	
	
	if(!(File = fopen(ThisFile,"rb")))
	  return 0;
	if(fseek(File,0,SEEK_END)!=0)
	  return 0;
	if((FILE_SIZE=ftell(File))==-1)
	  return 0;
	printf("FILE SIZE : %x %d\n",FILE_SIZE,FILE_SIZE);
	
	rewind(File);
	
	if(!(GLOBAL_FILE_BUFFER = calloc(FILE_SIZE,1)))
	{
		fclose(File);
	 	return 0;
	}
	 
	if(FILE_SIZE!=(BytesReaded=fread(GLOBAL_FILE_BUFFER,1,FILE_SIZE,File)))
	 return 0;
	
	fclose(File);
	return 1;
}

int main(int argc, char * argv[])
{
	printf("[0xD3struction] FILE TO HEX\n");
	if(argc!=2)
	{
		printf("[!] No Arg [!]\n\n");
		printf("Usage : %s <File To Hex>\n\n",argv[0]);
	  	return 0;
	}
	
	if(!SelfRead(argv[1]))
	{
		printf("[-] Can't read %s \n",argv[1]);
		return 0;
	}
	
	printf("[+] File %s Readed !\n",argv[1]);
	
	HexPrint(GLOBAL_FILE_BUFFER,FILE_SIZE,'|');
	
	system("pause");
	
	return 0;
	
}
	
