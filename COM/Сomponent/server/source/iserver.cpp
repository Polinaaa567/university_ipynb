#include "server.h"

#include <iostream>
using namespace std;


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
 

HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv)
{
  cout << "GetClassObject:" << clsid <<" - " << iid << endl;

  if (clsid==1) 
  {
     ServerFactory* pf = new ServerFactory();
     return pf->QueryInterface(iid,ppv);
  }  
  else
  {
     *ppv = NULL;
     return E_NOCOMPONENT_;
  }  
}