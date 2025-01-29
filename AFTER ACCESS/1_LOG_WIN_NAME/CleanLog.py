from sys import argv
if len(argv) == 1:
    print("Usage : %s [LogFile]\n") % (sys.argv[0],)
    exit

LogFileName = argv[1]
print(('[+]Log File Name : %s \n') % (LogFileName,))

LogFile = open(LogFileName,"r")

ClearLogFileName = "PY-Clear_"+LogFileName
ClearLogFile = open(ClearLogFileName,"w")
PrevLine = "Null"
i=0
for Line in LogFile:
    if(Line!=PrevLine):
       ClearLogFile.write(Line)
       PrevLine = Line
       i=i+1
print(('File %s created!\n%d lines.\n') % (ClearLogFileName,i))
