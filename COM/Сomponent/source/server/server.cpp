#include "server.h"

#include <iostream>
#include <fstream>
#include <math.h>

#include "Components.h"

using namespace std;


Server::Server() 
{
  fRefCount = 0;

  volume = 0;
  Sample_average = 0;

  println("Server::Constructor");
}

Server::~Server() 
{
  println( "Server::Destructor");  
}

Server::Server(int n, int x) 
{
  println("Server::Constructor(a,b)");
  this->n[5] = n;
  this->x[5] = x;
  fRefCount = 0;
}

HRESULT __stdcall Server::QueryInterface(const IID& iid, void** ppv)
{
   println("Server::QueryInterface");

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
   
   else {
     *ppv = NULL;
     return E_NOINTERFACE;
   }
   this->AddRef();
   return S_OK;
}

ULONG __stdcall Server::AddRef()
{
   println("Server::AddRef");
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}


ULONG __stdcall Server::Release()
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

void __stdcall Server::InputMas2() {
  println("Server::InputMas2");
  
  fstream f;

  f.open("GetX.txt");

  if(f.is_open()) {
    for (int i = 0; i < 5; i++) { 
      f >> x[i];
    }
  }
   else {
    println("No file opened");
  }

  f.close();

}
 
void __stdcall Server::InputMas1() {
  println("Server::InputMas1");
  
  fstream f;

  f.open("GetN.txt");

  if(f.is_open()) {
    for (int i = 0; i < 5; i++) { 
      f >> n[i];
    }
  }
  else {
    println("No file opened");
  }

  f.close();

}


void __stdcall Server::Sample_Average() 
{
  println("Server::Sample_Average");
  float sum = 0;
  for(int i = 0; i < 5; i++) {
    volume += n[i];
    sum += x[i] * n[i];
  }
  Sample_average = round(sum / volume * 100) / 100;
  cout<< "Sample_Average = " << Sample_average << endl << endl;

}

void __stdcall Server::Sample_Variance()
{
  println("Server::Sample_Variance");
  float sum = 0;
  
  for(int i=0; i< 5; i++) {
    sum += pow((x[i]- Sample_average), 2) * n[i];
  }
  cout << "Sample_Variance = " <<  round(sum / volume * 100) / 100 << endl;

}

void __stdcall Server::Corrected_Sample_Variance()
{
  println("Server::Corrected_Sample_Variance");
  float sum = 0;

  for(int i=0; i< 5; i++) {
    sum += pow((x[i]- Sample_average), 2) * n[i];
  }
  cout << "Corrected_Sample_Variance = " << round(sum / (volume-1) * 100) / 100 << endl << endl;

}


//******************************************************************************************


ServerFactory::ServerFactory() 
{
   println("ServerFactory::Constructor"); 
   
   fRefCount = 0;
}

ServerFactory::~ServerFactory() 
{
  println("ServerFactory::Destructor");  
}


HRESULT __stdcall ServerFactory::QueryInterface(const IID& iid, void** ppv)
{
   println("ServerFactory::QueryInterface");

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



ULONG __stdcall ServerFactory::AddRef()
{
   println("ServerFactory::AddRef");
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}

ULONG __stdcall ServerFactory::Release()
{
   println("ServerFactory::Relese");
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

HRESULT  __stdcall ServerFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
   println("ServerFactory::CreateInstance");
   if (pUnknownOuter!=NULL)
   {
      return E_NOTIMPL;
   }
   
   Server* p = new Server();
   p->AddRef();
   HRESULT res = p->QueryInterface(iid,ppv);
   p->Release();
   return res;
}

HRESULT __stdcall ServerFactory::LockServer(BOOL bLock)
{
  println("ServerFactory::LockServer");
  return S_OK;
}


void println(const char* str)
{
    printf(str);
    printf("\n");
}

const CLSID CLSID_Server = {0x91A42CAA,0x5777,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

HRESULT __stdcall GetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
   println("Component::GetClassObject");
   if (clsid==CLSID_Server)
   {
      ServerFactory* fa  = new ServerFactory();
      return fa->QueryInterface(iid,ppv);
   }
   else
   {
     *ppv = NULL;
     return E_NOTIMPL;
   }

}