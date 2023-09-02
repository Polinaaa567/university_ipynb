  set app = CreateObject("IKS.Application")
  
  app.summ
    
  app.Px1 = 11
  p = app.Px1()
  WScript.Echo(p)

  app.Px1 = 111
  p = app.Px1
  WScript.Echo(p)
