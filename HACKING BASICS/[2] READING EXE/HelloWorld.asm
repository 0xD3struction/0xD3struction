
;  [ASM] SIMPLE HELLO WORLD
;  
;    FROM VIDEO:
;	   https://www.youtube.com/watch?v=JNe7dQZ6K8A
;
;    DO NOT USE THIS CODE !
;
;    0xD3struction
;
;     2o24



format PE Console
include 'win32a.inc'
entry Start

section '.data' data readable writable
        intro db '[Hello World 0xD3struction]',10,0
        sys_arg db 'Pause',0


section '.code' code readable executable

Start:
                                    ;
                push intro                             ;
                call [printf]                         ; [C] : printf("[0xD3struction] \n File Path: %s \n\n",[ebp-4]);
                add esp,0x04

                push sys_arg
                call [system]                         ; [C] : system("pause");
                add esp,0x04

                xor eax,eax
                ret                                  ; return 0;
                                
section '.idata' import readable writable

library msvcrt,'MSVCRT.DLL'

   import msvcrt,\
                  printf,'printf',\
                  system,'system'

section '.exmple' data readable writable
        example_section_txt db 'Some Example text',0
