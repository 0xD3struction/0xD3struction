;
;     FASM OS VARS EXAMPLE
;
;     FROM VIDEO:
;	   https://www.youtube.com/watch?v=s4p41u60Zio
;
;     DO NOT USE THIS CODE !
;
;     0xD3struction
;
;    2o23




format PE CONSOLE
entry Start
include 'win32a.inc'

section '.data' data readable writeable

        intro db '[0xD3struction] HACKING BASICS : OS VARS',10,10,0
        pr_usrnam db 'USER NAME = %s',10,0
        pr_usrpr db 'USER PROFILE = %s',10,0
        pr_compname db 'COMPUTER NAME = %s',10,0
        pr_homedrv db 'HOME DRIVE = %s',10,0
        pr_progfile db 'Program Files = %s',10,0
        pr_windir db 'Win Dir = %s',10,0
        ;sys_arg db 'pause',0
        allusr db 'ALLUSERSPROFILE',0
        usrnam db 'USERNAME',0
        usrpr db 'USERPROFILE',0
        compname db 'COMPUTERNAME',0
        homedrv db 'HOMEDRIVE',0
        progfile db 'ProgramFiles',0
        windir db 'WinDir',0
        sys_arg db 'pause',0

section '.code' code readable executable
       Start:

              push intro
              call [printf]             ;printf(intro);
              add esp,4


              push usrnam
              call [getenv]				;getenv(usrnam);
              add esp,4

              push eax
              push pr_usrnam			;printf(pr_usrnam,EAX);
              call [printf]
              add esp,8

                          
              push usrpr
              call [getenv]				;getenv(usrpr);
              add esp,4

              push eax
              push pr_usrpr			    ;printf(pr_usrnam,EAX);
              call [printf]
              add esp,8

                          
              push compname
              call [getenv]				;getenv(usrpr);
              add esp,4

              push eax
              push pr_compname			;printf(pr_usrnam,EAX);
              call [printf]
              add esp,8

                          
              push homedrv
              call [getenv]				;getenv(usrpr);
              add esp,4

              push eax
              push pr_homedrv			;printf(pr_usrnam,EAX);
              call [printf]
              add esp,8
                  
				  
              push progfile
              call [getenv]				;getenv(usrpr);
              add esp,4

              push eax
              push pr_progfile			;printf(pr_usrnam,EAX);
              call [printf]
              add esp,8
                  
				  
              push windir
              call [getenv]				;getenv(usrpr);
              add esp,4

              push eax
              push pr_windir			;printf(pr_usrnam,EAX);
              call [printf]
              add esp,8


              push sys_arg
              call [system]				;system(sys_arg);
              add esp,4

			  retn



section '.idata' import data readable writeable

   library msvcrt,'MSVCRT.DLL'
   import msvcrt,\
                  printf,'printf',\
                  getenv,'getenv',\
                  system,'system'
