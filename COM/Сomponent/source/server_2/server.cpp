#include "server.h"

#include <objbase.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Server_2::Server_2() 
{
   a = 5;
   b = 8;
  println("Server_2::Server_2");
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
  
  const CLSID CLSID_Server = {0x91A42CAA,0x5777,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

  HRESULT resX = CreateInstance(CLSID_Server,NULL,IID_IGet_Array,(void**)&ig_Simple);
  if (!(SUCCEEDED(resX)))  
  {
    throw "";
  }    
  HRESULT resY = ig_Simple->QueryInterface(IID_ISample_Processing,(void**)&is_Simple);
  if (!(SUCCEEDED(resY)))  
  {
    throw "";
  }
  //Injecting component (End)
}

Server_2::~Server_2() 
{
  println( "Server_2::Destructor");  
  ig_Simple->Release();
  is_Simple->Release();
}

HRESULT __stdcall Server_2::QueryInterface(const IID& iid, void** ppv)
{
   println("Server_2::QueryInterface");

   if (iid==IID_IUnknown)
   {
    *ppv = (IUnknown*)(ISample_Processing*)this;
   }
   else if (iid == IID_ISample_Processing)
   {
    *ppv = static_cast<ISample_Processing*>(this);
   }
   else if (iid == IID_IGet_Array) {
    *ppv = (IGet_Array*)this;
   }
   else if (iid == IID_ISumma) {
      *ppv = (ISumma*)this;
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
   cout << "Server_2::Current references: " << fRefCount << endl;
   return fRefCount;
}

ULONG __stdcall Server_2::Release()
{
   println("Server_2::Release");
   fRefCount--;
   cout << "Server_2::Current references: " << fRefCount << endl;
   if (fRefCount==0) {delete this;}
   return fRefCount;
}

//методы компонента

void __stdcall Server_2::InputMas1() {
  println("InputMas1:Full delegating to the server component ");
  ig_Simple->InputMas1();
  
}

void __stdcall Server_2::InputMas2() {
  println("InputMas2:Full delegating to the server component");
  ig_Simple->InputMas2();
}

void __stdcall Server_2::Sample_Average() {
  println("Sample_Average:Full delegating to the server component");
  is_Simple->Sample_Average();
}

void __stdcall Server_2::Sample_Variance() {
  println("Sample_Variance:Full delegating to the server component");
  is_Simple->Sample_Variance();
}

void __stdcall Server_2::Corrected_Sample_Variance() {
  println("Corrected_Sample_Variance:Full delegating to the server component");
  is_Simple->Corrected_Sample_Variance();
}

void __stdcall Server_2::summ(){
   cout<< "Server_2::summ = " << a + b << endl;
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
    *ppv = (IUnknown*)(IClassFactory*)this;
   }
   else if (iid == IID_IClassFactory)
   {
    *ppv = (IClassFactory*)this;
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
   println("ServerFactory_2::Release");
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
   println("ServerFactory_2::CreateInstance");
   if (pUnknownOuter!=NULL)
   {
      return E_NOTIMPL;
   }
   
   Server_2* p = new Server_2();
   HRESULT res = p->QueryInterface(iid,ppv);
   return res;
}

HRESULT __stdcall ServerFactory_2::LockServer(BOOL bLock)
{
  println("ServerFactory_2::LockServer");
  return S_OK;
}

void println(const char* str)
{
    printf(str);
    printf("\n");
}

const CLSID CLSID_Server_2= {0x91A42CBA,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD7}};

HRESULT __stdcall GetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
   println("Component Server_2::GetClassObject");
   if (clsid==CLSID_Server_2)
   {
      try {
         ServerFactory_2* fa  = new ServerFactory_2();
         return fa->QueryInterface(iid,ppv);
      }
      catch(...){
         *ppv = NULL; 
         return E_UNEXPECTED;
      }
   }
   else
   {
     *ppv = NULL;
     return E_NOTIMPL;
   }
}