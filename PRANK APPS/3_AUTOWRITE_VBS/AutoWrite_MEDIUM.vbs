Set Shell = Wscript.CreateObject("Wscript.Shell")

for i=0 to 32
	Wscript.Sleep(1000)
	Shell.SendKeys("0xD3struction")
next

