/*
     [C] READING SECTIONS 
    
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

void PrintSectionHeader(IMAGE_SECTION_HEADER *SecPrint)
{
	printf("========[0xD3struction]====[SECTION %s]===========\n",SecPrint->Name);
	printf("Name[8]: %s\n",SecPrint->Name);
    printf("PhysicalAddress: 0x%X\n",SecPrint->Misc.PhysicalAddress);
	printf("VirtualSize: 0x%X\n",SecPrint->Misc.VirtualSize);
    printf("VirtualAddress: 0x%X\n",SecPrint->VirtualAddress);
    printf("SizeOfRawData: 0x%X\n",SecPrint->SizeOfRawData);
    printf("PointerToRawData: 0x%X\n",SecPrint->PointerToRawData);
    printf("PointerToRelocations: 0x%X\n",SecPrint->PointerToRelocations);
    printf("PointerToLinenumbers: 0x%X\n",SecPrint->PointerToLinenumbers);
    printf("NumberOfRelocations: 0x%X\n",SecPrint->NumberOfRelocations);
    printf("NumberOfLinenumbers: 0x%X\n",SecPrint->NumberOfLinenumbers);
    printf("Characteristics: 0x%X\n",SecPrint->Characteristics);
}

void PrintOptionalHeader(IMAGE_OPTIONAL_HEADER *OpPrint)
{
	puts("========[0xD3struction]====[IMAGE OPTIONAL HEADER]===========\n");
	printf("Magic: 0x%X\n",OpPrint->Magic);
    printf("MajorLinkerVersion: 0x%X\n",OpPrint->AddressOfEntryPoint);
    printf("MinorLinkerVersion: 0x%X\n",OpPrint->MinorLinkerVersion);
    printf("SizeOfCode: 0x%X\n",OpPrint->SizeOfCode);
    printf("SizeOfInitializedData: 0x%X\n",OpPrint->SizeOfInitializedData);
    printf("AddressOfEntryPoint: 0x%X\n",OpPrint->AddressOfEntryPoint);
    printf("BaseOfCode: 0x%X\n",OpPrint->BaseOfCode);
    printf("BaseOfData: 0x%X\n",OpPrint->BaseOfData);
    printf("ImageBase: 0x%X\n",OpPrint->ImageBase);
    printf("SectionAlignment: 0x%X\n",OpPrint->SectionAlignment);
    printf("FileAlignment: 0x%X\n",OpPrint->FileAlignment);
    printf("MajorOperatingSystemVersion: 0x%X\n",OpPrint->MajorOperatingSystemVersion);
    printf("MinorOperatingSystemVersion: 0x%X\n",OpPrint->MinorOperatingSystemVersion);
    printf(" MajorImageVersion: 0x%X\n",OpPrint->MajorImageVersion);
    printf("MinorImageVersion: 0x%X\n",OpPrint->MinorImageVersion);
    printf("MajorSubsystemVersion: 0x%X\n",OpPrint->MajorSubsystemVersion);
    printf("MinorSubsystemVersion: 0x%X\n",OpPrint->MinorSubsystemVersion);
    printf("Win32VersionValue: 0x%X\n",OpPrint->Win32VersionValue);
    printf("SizeOfImage: 0x%X\n",OpPrint->SizeOfImage);
    printf("SizeOfHeaders: 0x%X\n",OpPrint->SizeOfHeaders);
    printf("CheckSum: 0x%X\n",OpPrint->CheckSum);
    printf("Subsystem: 0x%X\n",OpPrint->Subsystem);
    printf("DllCharacteristics: 0x%X\n",OpPrint->DllCharacteristics);
    printf("SizeOfStackReserve: 0x%X\n",OpPrint->SizeOfStackReserve);
    printf("SizeOfStackCommit: 0x%X\n",OpPrint->SizeOfStackCommit);
    printf("SizeOfHeapReserve: 0x%X\n",OpPrint->SizeOfHeapReserve);
    printf("SizeOfHeapCommit: 0x%X\n",OpPrint->SizeOfHeapCommit);
    printf("LoaderFlags: 0x%X\n",OpPrint->LoaderFlags);
    printf("NumberOfRvaAndSizes: 0x%X\n",OpPrint->NumberOfRvaAndSizes);
    
    unsigned short i;
    					/* 16 */
    for(i=0;i<IMAGE_NUMBEROF_DIRECTORY_ENTRIES;++i)
    {
    	printf("DataDirectory[%d].VirtualAddress = %X\n",i,OpPrint->DataDirectory[i].VirtualAddress);
    	printf("DataDirectory[%d].Size = %X\n-\n",i,OpPrint->DataDirectory[i].Size);
    }
}



void PrintFileHeader(IMAGE_FILE_HEADER *PePrint)
{
	puts("========[0xD3struction]====[IMAGE FILE HEADER]===========\n");
	printf("Machine:............... 0x%X\n",PePrint->Machine);
    printf("NumberOfSections:...... 0x%X\n",PePrint->NumberOfSections);
    printf("TimeDateStamp:......... 0x%X\n",PePrint->TimeDateStamp);
    printf("PointerToSymbolTable:.. 0x%X\n",PePrint->PointerToSymbolTable);
    printf("NumberOfSymbols:....... 0x%X\n",PePrint->NumberOfSymbols);
    printf("SizeOfOptionalHeader:.. 0x%X\n",PePrint->SizeOfOptionalHeader);
	printf("Characteristics:....... 0x%X\n",PePrint->Characteristics);
    puts("========[0xD3struction]====[IMAGE FILE HEADER]===========\n\n");
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
	IMAGE_SECTION_HEADER SectionHeader;
	printf("\t\t\t[0xD3struction] IMAGE FILE HEADER32\n\n");

	
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
	
	unsigned short i,j;
	printf("NumberOfSections:...... 0x%X\n",FileHeader.NumberOfSections);
	for(i=0,j=0;i<FileHeader.NumberOfSections;j=j+sizeof(SectionHeader),++i)
	{
		memcpy(&SectionHeader,FILE_BUFF+Pe_Offset+4+sizeof(FileHeader)+sizeof(OptionalHeader)+j,sizeof(SectionHeader));
		PrintSectionHeader(&SectionHeader);
	}
    
    system("pause");
	return 0;
	
}
