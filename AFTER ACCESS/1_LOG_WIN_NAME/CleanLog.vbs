Set System = CreateObject("Scripting.FileSystemObject")
 
FileName =InputBox("ENTER LOG FILE NAME: :","0xD3struction CleanLog VBS ")

MsgBox "FILE NAME: "&FileName,vbOKCanacel+vbInformation,"0xD3struction: VBS LOG FILTR"		

Set Log_Handle = System.OpenTextFile(FileName,1)

PrevLine = "Null"
ClearFile = "Clear_"&FileName
i=0

Set CleanLog = System.CreateTextFile(ClearFile,true)
	
do until Log_Handle.AtEndOfStream
	LogLine = Log_Handle.ReadLine
	 if (StrComp(PrevLine,LogLine)<>0) Then
		PrevLine=LogLine
		CleanLog.Write LogLine&vbCrLf
		i=i+1
	 end if
loop

MsgBox ClearFile&" created!"&vbCrLf&i&" lines.",vbOKCanacel+vbInformation,"0xD3struction: VBS LOG FILTR"
CleanLog.Close
