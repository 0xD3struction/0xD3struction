format PE Console
include 'win32a.inc'
entry Start

section '.data' data readable writable
        Intro      db '[0xD3struction GET CURRENT PROCESS ID]',10,0
        ProcId_pr  db 'Current Process ID : 0x%08X',10,0
                
        sys_arg db 'Pause',0


section '.code' code readable executable

Start:
                                                      ;
                push Intro                            ;
                call [printf]                         ; [C] : printf("[0xD3struction GET CURRENT PROCESS ID]\n");
                add esp,0x04

                call [GetCurrentProcessId]            ; [C/ASM] {EAX} = GetCurrentProcessId();
                                
                push eax                              ;
                push ProcId_pr                        ;
                call [printf]                         ; [C/ASM] : printf("Current Process ID : 0x%08X\n",{EAX});
                add esp,0x08
                                
                push sys_arg
                call [system]                         ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                ret                                   ; return 0;
                                


section '.idata' import readable writable

library kernel,'KERNEL32.DLL',msvcrt,'MSVCRT.DLL'

   import msvcrt,\
                  printf,'printf',\
                  system,'system'

   import kernel,\
                  GetCurrentProcessId, 'GetCurrentProcessId'
                  
