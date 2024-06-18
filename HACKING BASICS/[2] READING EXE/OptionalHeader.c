/*
     [C] READING IMAGE_OPTIONAL_HEADER
    
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

void PrintOptionalHeader(IMAGE_OPTIONAL_HEADER *OpPrint)
{
	/* 1st */
	puts("\n========[0xD3struction]====[IMAGE OPTIONAL HEADER]===========\n");
	printf("\tMagic: ............................ 0x%02X\n",OpPrint->Magic);
    printf("\tMajorLinkerVersion: ............... 0x%X\n",OpPrint->AddressOfEntryPoint);
    printf("\tMinorLinkerVersion: ............... 0x%X\n",OpPrint->MinorLinkerVersion);
    printf("\tSizeOfCode: ....................... 0x%08X\n",OpPrint->SizeOfCode);
    printf("\tSizeOfInitializedData: ............ 0x%08X\n",OpPrint->SizeOfInitializedData);
    printf("\tAddressOfEntryPoint: .............. 0x%08X\n",OpPrint->AddressOfEntryPoint);
    printf("\tBaseOfCode: ....................... 0x%08X\n",OpPrint->BaseOfCode);
    printf("\tBaseOfData: ....................... 0x%08X\n",OpPrint->BaseOfData);
    printf("\tImageBase: ........................ 0x%08X\n",OpPrint->ImageBase);
    printf("\tSectionAlignment: ................. 0x%08X\n",OpPrint->SectionAlignment);
    printf("\tFileAlignment: .................... 0x%08X\n",OpPrint->FileAlignment);
    printf("\tMajorOperatingSystemVersion: ...... 0x%02X\n",OpPrint->MajorOperatingSystemVersion);
    printf("\tMinorOperatingSystemVersion: ...... 0x%02X\n",OpPrint->MinorOperatingSystemVersion);
    printf("\tMajorImageVersion: ................ 0x%02X\n",OpPrint->MajorImageVersion);
    printf("\tMinorImageVersion: ................ 0x%02X\n",OpPrint->MinorImageVersion);
    printf("\tMajorSubsystemVersion: ............ 0x%02X\n",OpPrint->MajorSubsystemVersion);
    printf("\tMinorSubsystemVersion: ............ 0x%02X\n",OpPrint->MinorSubsystemVersion);
    printf("\tWin32VersionValue: ................ 0x%08X\n",OpPrint->Win32VersionValue);
    printf("\tSizeOfImage: ...................... 0x%08X\n",OpPrint->SizeOfImage);
    printf("\tSizeOfHeaders: .................... 0x%08X\n",OpPrint->SizeOfHeaders);
    printf("\tCheckSum: ......................... 0x%08X\n",OpPrint->CheckSum);
    printf("\tSubsystem: ........................ 0x%02X\n",OpPrint->Subsystem);
    printf("\tDllCharacteristics: ............... 0x%02X\n",OpPrint->DllCharacteristics);
    printf("\tSizeOfStackReserve: ............... 0x%08X\n",OpPrint->SizeOfStackReserve);
    printf("\tSizeOfStackCommit: ................ 0x%08X\n",OpPrint->SizeOfStackCommit);
    printf("\tSizeOfHeapReserve: ................ 0x%08X\n",OpPrint->SizeOfHeapReserve);
    printf("\tSizeOfHeapCommit: ................. 0x%08X\n",OpPrint->SizeOfHeapCommit);
    printf("\tLoaderFlags: ...................... 0x%08X\n",OpPrint->LoaderFlags);
    printf("\tNumberOfRvaAndSizes: .............. 0x%08X\n\n",OpPrint->NumberOfRvaAndSizes);
    
    /* 2nd */
    unsigned short i;
    					/* 16 */
    for(i=0;i<IMAGE_NUMBEROF_DIRECTORY_ENTRIES;++i)
    {
    	printf("\tDataDirectory[%d].VirtualAddress = . 0x%X\n",i,OpPrint->DataDirectory[i].VirtualAddress);
    	printf("\tDataDirectory[%d].Size = ........... 0x%X\n",i,OpPrint->DataDirectory[i].Size);
    }
}



void PrintFileHeader(IMAGE_FILE_HEADER *PePrint)
{
	puts("\n========[0xD3struction]====[IMAGE FILE HEADER]===========\n");
	printf("\tMachine: .......................... 0x%X\n",PePrint->Machine);
    printf("\tNumberOfSections: ................. 0x%X\n",PePrint->NumberOfSections);
    printf("\tTimeDateStamp: .................... 0x%X\n",PePrint->TimeDateStamp);
    printf("\tPointerToSymbolTable: ............. 0x%X\n",PePrint->PointerToSymbolTable);
    printf("\tNumberOfSymbols: .................. 0x%X\n",PePrint->NumberOfSymbols);
    printf("\tSizeOfOptionalHeader: ............. 0x%X\n",PePrint->SizeOfOptionalHeader);
	printf("\tCharacteristics: .................. 0x%X\n",PePrint->Characteristics);
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
	
	IMAGE_FILE_HEADER FileHeader;
	IMAGE_OPTIONAL_HEADER32 OptionalHeader;
	printf("\t\t\t[0xD3struction] IMAGE OPTIONAL HEADER \n\n");

	
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
    printf("IMAGE FILE HEADER size : %d \n",sizeof(FileHeader));
    printf("IMAGE OPTIONAL HEADER size : %d \n",sizeof(OptionalHeader));
    
    memcpy(&FileHeader,FILE_BUFF+Pe_Offset+4,sizeof(FileHeader));
    PrintFileHeader(&FileHeader);
    
    memcpy(&OptionalHeader,FILE_BUFF+Pe_Offset+4+sizeof(FileHeader),sizeof(OptionalHeader));
	PrintOptionalHeader(&OptionalHeader);
    
    system("pause");
	return 0;
	
}
