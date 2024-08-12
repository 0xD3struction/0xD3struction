;
;     SecondEntryPoint.asm  
;       
;     FROM VIDEO:
;	   https://www.youtube.com/watch?v=BKZ1MfQHC-c
;
;     DO NOT USE THIS CODE !
;
;     0xD3struction
;
;    2o24


format PE Console
include 'win32a.inc'
entry Start

section '.data' data readable writable
        First  db '[0xD3struction FIRST ENTRY POINT]',10,0
        Second db '[0xD3struction SECOND ENTRY POINT]',10,0

        MSGBOX_1 db '[0xD3struction SECOND ENTRY POINT]',0
        MSGBOX_2 DB '[ + ]  MESSAGE FROM SECOND ENTRY POINT [ + ]',0
        sys_arg db 'Pause',0


section '.code' code readable executable

Start:
                                                      ;
                push First                            ;
                call [printf]                         ; [C] : printf("[0xD3struction FIRST ENTRY POINT]\n");
                add esp,0x04

                push sys_arg
                call [system]                         ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                ret                                   ; return 0;
                                

section '.SCND' data readable writable


                push Second                           ;
                call [printf]                         ; [C] : printf("[0xD3struction SECOND ENTRY POINT]\n");
                add esp,0x04

                push 0x44                             ;
                push MSGBOX_2                         ;
                push MSGBOX_1                         ;
                push 0                                ;
                call [MessageBox]                     ;MessageBox(0,"[0xD3struction SECOND ENTRY POINT]","[0xD3struction HIDE CONSOLE WINDOW]\n",MB_ICONINFORMATION|MB_YESNO);


                push sys_arg
                call [system]                         ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                ret
section '.idata' import readable writable

library msvcrt,'MSVCRT.DLL',user32,'USER32.DLL'

   import msvcrt,\
                  printf,'printf',\
                  system,'system'

   import user32,\
                 MessageBox,'MessageBoxA'
