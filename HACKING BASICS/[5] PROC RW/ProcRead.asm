format PE Console
include 'win32a.inc'
entry Start

section '.data' data readable writable
        Intro      db '[0xD3struction WRITE SECTION TO FILE]',10,0
        WrOk       db '[+] SECTION .SCND written to file !',10,0
        WrFail     db '[-] Cant write file ! ',10,0
        FileName   db 'SCND_Dump.sec',0
        Hello_pr   db 'Hello World!',10,0
        sys_arg    db 'Pause',0
                
        sec_size      dd 0x0000001F
        BytesReaded   dd ?
        BytesWritten   dd ?


section '.code' code readable executable

        SaveFile:
                  push ebp
                  mov ebp,esp
                  sub esp,0x04


                  push 0x00                         ;
                  push FILE_ATTRIBUTE_NORMAL        ;
                  push CREATE_ALWAYS                ;
                  push 0x00                         ;
                  push FILE_SHARE_WRITE             ;
                  push GENERIC_WRITE                ;
                  push dword FileName               ;
                  call [CreateFileA]                ; [C/ASM] CreateFileA(EBX,GENERIC_WRITE,...)

                  test eax,eax
                  je EndSave

                  mov dword [ebp-4],eax             ; saving handle to file

                  push 0x00                         ;
                  push dword BytesWritten           ;
                  push 0x1F                         ; SIZE OF .SCND SECTION
                  push 0x00403000                   ; ADDRESS OF .SCND SECTION
                  push eax                          ;
                  call [WriteFile]                  ; [C] : WriteFile({EAX},{SECTION ADDR},{SECTION SIZE},&BytesWritten,0)

                  cmp eax,eax
                  jne WFail

                  push WrOk
                  call [printf]
                  add esp,0x04
                  jmp CloseFile

    WFail:
                  push WrFail
                  call [printf]
                  add esp,0x04

    CloseFile:
                  push dword[ebp-4]               ;
                  call [CloseHandle]              ; [C] : CloseHandle(InfectHandle);

    EndSave:
                  xor eax,eax
                  add esp,0x04
                  pop ebp
                  ret


Start:
                push ebp                                                  ; STACK FRAME : for local vars
                mov ebp,esp                                               ;
                sub esp,0x0F                                              ;
                                                      
                push Intro                                                ;
                call [printf]                                             ; [C] printf("[0xD3struction GET CURRENT PROCESS ID]\n");
                add esp,0x04 


                call SaveFile
      
                push sys_arg
                call [system]                                            ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                add esp,0x0F
                pop ebp
                ret                                   ; return 0;
                                
section '.SCND' data readable writable

                push Hello_pr                                           ;
                call [printf]                                           ; [C] : printf("Hello World!\n");
                add esp,0x04

                push sys_arg
                call [system]                                            ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                ret

section '.idata' import readable writable

library kernel,'KERNEL32.DLL',msvcrt,'MSVCRT.DLL'

   import msvcrt,\
                  printf,'printf',\
                  system,'system',\
                  malloc,'malloc'

   import kernel,\
                  CloseHandle, 'CloseHandle',\
                  CreateFileA,'CreateFileA',\
                  WriteFile,'WriteFile'
