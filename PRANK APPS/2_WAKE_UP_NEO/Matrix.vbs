Set Shell = Wscript.CreateObject("Wscript.Shell")

Txt = "Wake up, Neo..."
Txt1 = "The Matrix has you..." 
Txt2 = "Follow the white rabbit."
Txt3 = "Knock, knock, Neo."


Shell.Exec("notepad.exe")
Wscript.Sleep(3000)

'Wake Up
For i = 1 To Len(Txt)
    Shell.SendKeys(Mid(Txt,i,1))
	Wscript.Sleep(250)
  Next
 
Wscript.Sleep(2000)
Shell.SendKeys("^(a)")


'Matrix has you 
For i = 1 To Len(Txt1)
    Shell.SendKeys(Mid(Txt1,i,1))
	Wscript.Sleep(250)
  Next

Wscript.Sleep(1000)
Shell.SendKeys("^(a)")


 'Follow the White Rabbit
For i = 1 To Len(Txt2)
    Shell.SendKeys(Mid(Txt2,i,1))
	Wscript.Sleep(250)
  Next

Wscript.Sleep(3000)
Shell.SendKeys("^(a)")

Shell.SendKeys(Txt3)
