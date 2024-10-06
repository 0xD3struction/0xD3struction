                                                  format PE Console
include 'win32a.inc'
entry Start

section '.data' data readable writable
        Intro      db '[0xD3struction READ SECTION FROM FILE]',10,0
        ProcId_pr  db '[+]Current Process ID : [0x%08X]',10,0
        ProcOp_pr  db '[+] Process PID[0x%08X] (WRITE MODE) opened !',10,0
        ProcEr_pr  db '[-] Cant open process[0x%08X] !',10,0
        ROk        db '[+] NOP File READED!',10,0
        RFail      db '[-] Cant READ NOP file ! ',10,0
        FileName   db 'nop_file.nop',0
        Hello_pr   db 'Hello World!',10,0
        sys_arg    db 'Pause',0
                
                sec_size      dd 0x0000001F
                BytesReaded   dd ?
                BytesWritten   dd ?


section '.code' code readable executable

        ReadNOPFile:
                  push ebp
                  mov ebp,esp
                  sub esp,0x04

                  ;mov edx,dword [ebp+0x08]    ;Arg to Edx(Buffer with readed section)

                  push 0x00                                               ;/
                  push FILE_ATTRIBUTE_NORMAL                              ;|
                  push OPEN_EXISTING                                      ;|
                  push 0x00                                               ;|
                  push FILE_SHARE_READ                                    ;|
                  push GENERIC_READ                                       ;|
                  push FileName                                                ;|
                  call [CreateFileA]                                      ;|

                  test eax,eax
                  je EndSave

                  mov dword [ebp-4],eax            ;saving handle to file

                  push 0x00                         ;
                  push dword BytesReaded           ;
                  push dword [sec_size]            ;
                  push dword [ebp+0x08]          ;
                  push eax                          ;
                  call [ReadFile]

                  cmp eax,eax
                  jne RFail

                  push ROk
                  call [printf]
                  add esp,0x04
                  jmp CloseFile

    WFail:
                  push RFail
                  call [printf]
                  add esp,0x04

    CloseFile:
                  push dword[ebp-4]
                  call [CloseHandle]

    EndSave:
                  xor eax,eax
                  add esp,0x04
                  pop ebp
                  ret


Start:
                push ebp                          ; STACK FRAME : for local vars
                mov ebp,esp                       ;
                sub esp,0x0F                                               ;
                                                      
                push Intro                        ;
                call [printf]                     ; [C] printf("[0xD3struction GET CURRENT PROCESS ID]\n");
                add esp,0x04

                push dword[sec_size]              ;
                call [malloc]                                     ;{EAX} = malloc(sec_size);
                add esp,0x04

                mov [ebp-0x0C],eax                                ;Saving Handle to allocated memory as local var
                                
                push eax
                call ReadNOPFile
                add esp,0x04
                                
                                
                                push dword[sec_size]
                                push dword[ebp-0x0C]
                                push 0x00403000
                                call [memcpy]
                                add  esp,0x0C
                                

                 
                push sys_arg
                call [system]                         ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                add esp,0x0F
                pop ebp
                ret                                   ; return 0;
                                
section '.SCND' data readable writable

                push Hello_pr                           ;
                call [printf]                         ; [C] : printf("[0xD3struction SECOND ENTRY POINT]\n");
                add esp,0x04

                push sys_arg
                call [system]                         ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                ret

section '.idata' import readable writable

library kernel,'KERNEL32.DLL',msvcrt,'MSVCRT.DLL'

   import msvcrt,\
                  printf,'printf',\
                  system,'system',\
                  malloc,'malloc',\
                                  memcpy,'memcpy'

   import kernel,\
                  CloseHandle, 'CloseHandle',\
                  CreateFileA,'CreateFileA',\
                  ReadFile,'ReadFile'