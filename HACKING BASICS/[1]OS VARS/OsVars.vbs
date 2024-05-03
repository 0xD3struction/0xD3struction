'
'     VBS OS VARS EXAMPLE
'
'     FROM VIDEO:
'   https://www.youtube.com/watch?v=s4p41u60Zio
'
'     DO NOT USE THIS CODE !
'
'     0xD3struction
'
'    2o24

set Shell  = CreateObject("Wscript.Shell")
MsgBox "USERNAME = "&Shell.ExpandEnvironmentStrings("%USERNAME%"),vbOKCanacel+vbInformation,"0xD3struction[Env Vars]"
MsgBox "USERPROFILE = "&Shell.ExpandEnvironmentStrings("%USERPROFILE%"),vbOKCanacel+vbInformation,"0xD3struction[Env Vars]"
MsgBox "COMPUTERNAME = "&Shell.ExpandEnvironmentStrings("%COMPUTERNAME%"),vbOKCanacel+vbInformation,"0xD3struction[Env Vars]"
MsgBox "HOMEDRIVE = "&Shell.ExpandEnvironmentStrings("%HOMEDRIVE%"),vbOKCanacel+vbInformation,"0xD3struction[Env Vars]"
MsgBox "ProgramFiles = "&Shell.ExpandEnvironmentStrings("%ProgramFiles%"),vbOKCanacel+vbInformation,"0xD3struction[Env Vars]"
MsgBox "WinDir = "&Shell.ExpandEnvironmentStrings("%WinDir%"),vbOKCanacel+vbInformation,"0xD3struction[Env Vars]"



Wscript.Shell.ExpandEnvironmentStrings()
