#[0xD3struction] EXE to PY to EXE
from sys import argv

if len(argv) == 1:
    print("Usage : %s [EXE FILE]\n") % (argv[0],)
    exit

FileName = argv[1]

print("[0xD3struction EXE TO PY]\n")
print(('[+]File Name : %s') % (FileName,))

ExeFile = open(FileName,"rb")
FileBuff = ExeFile.read()
ExeFile.close()

ByteArrayFileName = "ByteArray_"+FileName.replace('.','_')
NewFileName = "Create_"+FileName.replace('.','_')+".py"

print(('[+]File Size : %d B') % (len(FileBuff),))
print(('[+]New File Name(WITH EXE): %s') % (NewFileName,))
print(('[+]Byte Array File Name : %s ') % (ByteArrayFileName,))

PyWithExe = open(NewFileName,"w")
PyWithExe.write("print(\"[0xD3struction PY TO EXE]\")\n")
PyWithExe.write(('# FILE \"%s\"\n') % (FileName,))
PyWithExe.write("%s = bytearray([" % ByteArrayFileName)

for i in range(len(FileBuff)):
    if i%16==0:
       PyWithExe.write("\n\t\t\t\t")
    PyWithExe.write(('0x%02X,') % (FileBuff[i],))

PyWithExe.write("])\n\n")
PyWithExe.write(("ExeFile = open(\"Py%s\",\"wb\")\n") % (FileName,))
PyWithExe.write(("ExeFile.write(%s)\n") % (ByteArrayFileName,))
PyWithExe.write("ExeFile.close()\n")
PyWithExe.write(("print(\"[+] EXE FILE : \\\"Py%s\\\" CREATED ! \")") % (FileName,))
PyWithExe.close()
