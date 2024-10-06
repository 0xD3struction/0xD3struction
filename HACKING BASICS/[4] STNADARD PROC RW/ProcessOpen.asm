format PE Console
include 'win32a.inc'
entry Start

section '.data' data readable writable
        Intro      db '[0xD3struction OPEN PROCESS]',10,0
        ProcId_pr  db '[+] Current Process ID : [0x%08X]',10,0
        ProcOp_pr  db '[+] Process PID[0x%08X] opened !',10,0
        ProcEr_pr  db '[-] Cant open process[0x%08X] !',10,0
        sys_arg    db 'Pause',0


section '.code' code readable executable

Start:
                push ebp                          ; STACK FRAME : for local vars
                mov ebp,esp                       ;
                sub esp,0x4                       ;
                                                      
                push Intro                        ;
                call [printf]                     ; [C] printf("[0xD3struction GET CURRENT PROCESS ID]\n");
                add esp,0x04

                call [GetCurrentProcessId]        ; [C/ASM] {EAX} = GetCurrentProcessId();
                               
                test eax,0
                jne The_End                       ; [C/ASM] if(EAX==0) goto The_End;
                                
                mov[ebp-4],eax                    ; Saving return of GetProcId as local var
                                
                push eax                          ;
                push ProcId_pr                    ;
                call [printf]                     ; [C] printf("[+]Current Process ID : [0x%08X]\n",{EAX});
                add esp,0x08
                                
                push dword[ebp-4]                 ;
                push 1                            ;
                push PROCESS_VM_OPERATION         ;
                call [OpenProcess]                ; OpenProcess(PROCESS_VM_OPERATION,1,{ProcessId});
                                
                test eax,0                                                ;
                jne ProcEr                        ; if(EAX==0) goto The_End
                                
                push dword[ebp-4]                 ;
                push ProcOp_pr                    ;
                call [printf]                     ; [C] printf("[+] Process PID[0x%08X] opened !\n",{ProcessId});
                add esp,0x08
                                
                push dword [ebp-4]                ;
                call [CloseHandle]                ; [C/ASM] CloseHandle({ProcessId});
                                
                jmp The_End
                                

ProcEr:
                push dword [ebp-4]                ;
                push ProcEr_pr                    ;
                call [printf]                     ; [C/ASM] printf("[-] Cant open process[0x%08X] !\n",{ProcessId});
                add esp,0x08
         
The_End:
                 
                push sys_arg
                call [system]                     ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                add esp,0x04
                pop ebp
                ret                               ; return 0;
                                


section '.idata' import readable writable

library kernel,'KERNEL32.DLL',msvcrt,'MSVCRT.DLL'

   import msvcrt,\
                  printf,'printf',\
                  system,'system'

   import kernel,\
                  GetCurrentProcessId, 'GetCurrentProcessId',\
                  OpenProcess, 'OpenProcess',\
                  CloseHandle, 'CloseHandle'
