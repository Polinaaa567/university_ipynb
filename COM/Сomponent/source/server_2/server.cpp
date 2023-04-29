#include "server.h"

#include <objbase.h>
#include <iostream>
#include <fstream>
#include <math.h>

#include "Components.h"

using namespace std;


Server_2::Server_2() 
{
  fRefCount = 0;

  println("Server_2::Constructor");

  HINSTANCE h;
  h=LoadLibrary("./build/manager/main.dll");
  if (!h)
  {
     throw "No manager";
  }
  typedef HRESULT __stdcall (*CreateInstanceType) (const CLSID& clsid, IUnknown* pUnknownOuter, const IID& iid, void** ppv);
  CreateInstanceType CreateInstance = (CreateInstanceType) GetProcAddress(h,"CreateInstance");
  if (!CreateInstance)
  {
     throw "No manager method";
  }
  //Getting manager method (End)
  
  //{91A42CAA-2577-4E80-934E-07DE64502FD6}
  const CLSID CLSID_Simple = {0x91A42CAA,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

  HRESULT resX = CreateInstance(CLSID_Simple,NULL,IID_Summ,(void**)&isum);
  if (!(SUCCEEDED(resX)))  
  {
    throw "";
  }    
  //Injecting component (End)
}

Server_2::~Server_2() 
{
  println( "Server_2::Destructor");  
  isum->Release();

}

HRESULT __stdcall Server_2::QueryInterface(const IID& iid, void** ppv)
{
   println("Server_2::QueryInterface");

   if (iid==IID_IUnknown)
   {
    *ppv = (IUnknown*)(ISumm*)this;
   }
   else if (iid==IID_Summ)
   {
      *ppv = (ISumm*)this;
   }
   else {
     *ppv = NULL;
     return E_NOINTERFACE;
   }
   this->AddRef();
   return S_OK;
}

ULONG __stdcall Server_2::AddRef()
{
   println("Server_2::AddRef");
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}


ULONG __stdcall Server_2::Release()
{
   println("Server::Relese");
   fRefCount--;
   cout << "Current references: " << fRefCount << endl;
   if (fRefCount==0)
   {
     println("Self-destructing...");
     delete this;
     println("Self-destructing...OK");
   }
   return fRefCount;
}

//методы компонента

void __stdcall Server_2::summa() {
  println(":Full delegating to the simple component");
  isum->Corrected_Sample_Variance();
}

//******************************************************************************************


ServerFactory_2::ServerFactory_2() 
{
   println("ServerFactory_2::Constructor"); 
   
   fRefCount = 0;
}

ServerFactory_2::~ServerFactory_2() 
{
  println("ServerFactory_2::Destructor");  
}


HRESULT __stdcall ServerFactory_2::QueryInterface(const IID& iid, void** ppv)
{
   println("ServerFactory_2::QueryInterface");

   if (iid==IID_IUnknown)
   {
    *ppv = (IUnknown*)(IClassFactory*)(this);
   }
   else if (iid == IID_IClassFactory)
   {
    *ppv = (void**)(IClassFactory*)(this);
   }
   else {
     *ppv = NULL;
     return E_NOINTERFACE;
   }
   this->AddRef();
   return S_OK;
}



ULONG __stdcall ServerFactory_2::AddRef()
{
   println("ServerFactory_2::AddRef");
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}

ULONG __stdcall ServerFactory_2::Release()
{
   println("ServerFactory_2::Relese");
   fRefCount--;
   cout << "Current references: " << fRefCount << endl;
   if (fRefCount==0)
   {
     println("Self-destructing...");
     delete this;
     println("Self-destructing...OK");
   }
   return fRefCount;
}

HRESULT  __stdcall ServerFactory_2::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
   println("ServerFactory::CreateInstance");
   if (pUnknownOuter!=NULL)
   {
      return E_NOTIMPL;
   }
   
   Server_2* p = new Server_2();
   p->AddRef();
   HRESULT res = p->QueryInterface(iid,ppv);
   p->Release();
   return res;
}

HRESULT __stdcall ServerFactory_2::LockServer(BOOL bLock)
{
  println("ServerFactory::LockServer");
  return S_OK;
}


void println(const char* str)
{
    printf(str);
    printf("\n");
}

const CLSID CLSID_Server_2= {0x91A42CBB,0x2572,0x4E80,{0x91,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

HRESULT __stdcall GetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
   println("Component::GetClassObject");
   if (clsid==CLSID_Server_2)
   {
      ServerFactory_2* fa  = new ServerFactory_2();
      return fa->QueryInterface(iid,ppv);
   }
   else
   {
     *ppv = NULL;
     return E_NOTIMPL;
   }

}