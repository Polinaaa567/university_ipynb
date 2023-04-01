#include "manager.h"
#include "server.h"

#include <iostream>
using namespace std;

HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv)
{
  cout << "Function::GetClassObject" << endl;
  IUnknown_* s = NULL;
  if (clsid==CLSID_CServer) 
  {
    s = (IUnknown_*)(IClassFactory_*)new ServerFactory();
  }  
  else
  {
     *ppv = NULL;
     return E_NOCOMPONENT_;  
  }  
  
  s->AddRef();
  HRESULT_ res =  s->QueryInterface(iid,ppv);
  s->Release();  
  return res;
}



HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv)
{
  cout << "CreateInstance:" << clsid <<" - "<< iid << endl;

   IClassFactory_* pf = NULL;
   HRESULT_ res = GetClassObject(clsid,IID_IClassFactory_,(void**)&pf);
   if (res == S_OK_)
   {
      res = pf->CreateInstance(iid,ppv);
      pf->Release();
   } 
   return res;
}   
