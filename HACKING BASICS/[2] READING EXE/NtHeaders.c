/*
     [C] READING IMAGE_NT_HEADERS32
    
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

void PrintNT(IMAGE_NT_HEADERS32 *NtPrint)
{
	puts("========[0xD3struction]====[IMAGE FILE HEADER]===========\n");
	printf("\tMachine: ............................ 0x%04X\n",NtPrint->FileHeader.Machine);
    printf("\tNumberOfSections: ................... 0x%04X\n",NtPrint->FileHeader.NumberOfSections);
    printf("\tTimeDateStamp: ...................... 0x%08X\n",NtPrint->FileHeader.TimeDateStamp);
    printf("\tPointerToSymbolTable: ............... 0x%08X\n",NtPrint->FileHeader.PointerToSymbolTable);
    printf("\tNumberOfSymbols: .................... 0x%08X\n",NtPrint->FileHeader.NumberOfSymbols);
    printf("\tSizeOfOptionalHeader: ............... 0x%04X\n",NtPrint->FileHeader.SizeOfOptionalHeader);
	printf("\tCharacteristics: .................... 0x%04X\n\n",NtPrint->FileHeader.Characteristics);
	
	puts("\n========[0xD3struction]====[IMAGE OPTIONAL HEADER]===========\n");
	printf("\tMagic: ............................ 0x%02X\n",NtPrint->OptionalHeader.Magic);
    printf("\tMajorLinkerVersion: ............... 0x%X\n",NtPrint->OptionalHeader.AddressOfEntryPoint);
    printf("\tMinorLinkerVersion: ............... 0x%X\n",NtPrint->OptionalHeader.MinorLinkerVersion);
    printf("\tSizeOfCode: ....................... 0x%08X\n",NtPrint->OptionalHeader.SizeOfCode);
    printf("\tSizeOfInitializedData: ............ 0x%08X\n",NtPrint->OptionalHeader.SizeOfInitializedData);
    printf("\tAddressOfEntryPoint: .............. 0x%08X\n",NtPrint->OptionalHeader.AddressOfEntryPoint);
    printf("\tBaseOfCode: ....................... 0x%08X\n",NtPrint->OptionalHeader.BaseOfCode);
    printf("\tBaseOfData: ....................... 0x%08X\n",NtPrint->OptionalHeader.BaseOfData);
    printf("\tImageBase: ........................ 0x%08X\n",NtPrint->OptionalHeader.ImageBase);
    printf("\tSectionAlignment: ................. 0x%08X\n",NtPrint->OptionalHeader.SectionAlignment);
    printf("\tFileAlignment: .................... 0x%08X\n",NtPrint->OptionalHeader.FileAlignment);
    printf("\tMajorOperatingSystemVersion: ...... 0x%02X\n",NtPrint->OptionalHeader.MajorOperatingSystemVersion);
    printf("\tMinorOperatingSystemVersion: ...... 0x%02X\n",NtPrint->OptionalHeader.MinorOperatingSystemVersion);
    printf("\tMajorImageVersion: ................ 0x%02X\n",NtPrint->OptionalHeader.MajorImageVersion);
    printf("\tMinorImageVersion: ................ 0x%02X\n",NtPrint->OptionalHeader.MinorImageVersion);
    printf("\tMajorSubsystemVersion: ............ 0x%02X\n",NtPrint->OptionalHeader.MajorSubsystemVersion);
    printf("\tMinorSubsystemVersion: ............ 0x%02X\n",NtPrint->OptionalHeader.MinorSubsystemVersion);
    printf("\tWin32VersionValue: ................ 0x%08X\n",NtPrint->OptionalHeader.Win32VersionValue);
    printf("\tSizeOfImage: ...................... 0x%08X\n",NtPrint->OptionalHeader.SizeOfImage);
    printf("\tSizeOfHeaders: .................... 0x%08X\n",NtPrint->OptionalHeader.SizeOfHeaders);
    printf("\tCheckSum: ......................... 0x%08X\n",NtPrint->OptionalHeader.CheckSum);
    printf("\tSubsystem: ........................ 0x%02X\n",NtPrint->OptionalHeader.Subsystem);
    printf("\tDllCharacteristics: ............... 0x%02X\n",NtPrint->OptionalHeader.DllCharacteristics);
    printf("\tSizeOfStackReserve: ............... 0x%08X\n",NtPrint->OptionalHeader.SizeOfStackReserve);
    printf("\tSizeOfStackCommit: ................ 0x%08X\n",NtPrint->OptionalHeader.SizeOfStackCommit);
    printf("\tSizeOfHeapReserve: ................ 0x%08X\n",NtPrint->OptionalHeader.SizeOfHeapReserve);
    printf("\tSizeOfHeapCommit: ................. 0x%08X\n",NtPrint->OptionalHeader.SizeOfHeapCommit);
    printf("\tLoaderFlags: ...................... 0x%08X\n",NtPrint->OptionalHeader.LoaderFlags);
    printf("\tNumberOfRvaAndSizes: .............. 0x%08X\n\n",NtPrint->OptionalHeader.NumberOfRvaAndSizes);
    
    puts("\n========[0xD3struction]====[IMAGE_DATA_DIRECTORY]===========\n");
    
    unsigned short i;
    for(i=0;i<IMAGE_NUMBEROF_DIRECTORY_ENTRIES;++i)
    {
    	printf("\tDataDirectory[%d].VirtualAddress = . 0x%X\n",i,NtPrint->OptionalHeader.DataDirectory[i].VirtualAddress);
    	printf("\tDataDirectory[%d].Size = ........... 0x%X\n",i,NtPrint->OptionalHeader.DataDirectory[i].Size);
    }
    
}


void PrintSectionHeader(IMAGE_SECTION_HEADER *SecPrint)
{
	printf("========[0xD3struction]====[SECTION %s]===========\n",SecPrint->Name);
	printf("\tName[7]: .................... %s\n",SecPrint->Name);
    printf("\tPhysicalAddress: ............ 0x%08X\n",SecPrint->Misc.PhysicalAddress);
	printf("\tVirtualSize: ................ 0x%08X\n",SecPrint->Misc.VirtualSize);
    printf("\tVirtualAddress: ............. 0x%08X\n",SecPrint->VirtualAddress);
    printf("\tSizeOfRawData: .............. 0x%08X\n",SecPrint->SizeOfRawData);
    printf("\tPointerToRawData: ........... 0x%08X\n",SecPrint->PointerToRawData);
    printf("\tPointerToRelocations: ....... 0x%08X\n",SecPrint->PointerToRelocations);
    printf("\tPointerToLinenumbers: ....... 0x%08X\n",SecPrint->PointerToLinenumbers);
    printf("\tNumberOfRelocations:  ....... 0x%04X\n",SecPrint->NumberOfRelocations);
    printf("\tNumberOfLinenumbers: ........ 0x%04X\n",SecPrint->NumberOfLinenumbers);
    printf("\tCharacteristics: ............ 0x%08X\n",SecPrint->Characteristics);
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
	IMAGE_NT_HEADERS32 NTHeaders;
	IMAGE_SECTION_HEADER SectionHeader;
	
	printf("\t\t\t[0xD3struction] IMAGE NT HEADERS\n\n");

	
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
    printf("IMAGE NT HEADER size : %d \n",sizeof(NTHeaders));
   
	memcpy(&NTHeaders,FILE_BUFF+Pe_Offset,sizeof(NTHeaders));
	PrintNT(&NTHeaders);
	
	unsigned short i,j;
	printf("NumberOfSections:...... 0x%X\n",NTHeaders.FileHeader.NumberOfSections);
	
	for(i=0,j=0;i<NTHeaders.FileHeader.NumberOfSections;j=j+sizeof(SectionHeader),++i)
	{
		memcpy(&SectionHeader,FILE_BUFF+Pe_Offset+sizeof(NTHeaders)+j,sizeof(SectionHeader));
		PrintSectionHeader(&SectionHeader);
	}
    
    system("pause");
	return 0;
	
}
