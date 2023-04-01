#include "server.h"

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


Server::Server() 
{
  fRefCount = 0;

  volume = 0;
  Sample_average = 0;

  cout << "Server::Constructor" << endl;
}

Server::~Server() 
{
  cout << "Server::Destructor" << endl;  
}

Server::Server(int n, int x) 
{
  cout << "Server::Constructor(a,b)" << endl;
  this->n[5] = n;
  this->x[5] = x;
  fRefCount = 0;
}

HRESULT_ __stdcall Server::QueryInterface(const IID_& iid, void** ppv)
{
   cout << "Server::QueryInterface:" << iid << endl;

   if (iid==IID_IUnknown_)
   {
    *ppv = (IUnknown_*)(ISample_Processing*)this;
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
     return E_NOINTERFACE_;
   }
   this->AddRef();
   return S_OK_;
}

ULONG_ __stdcall Server::AddRef()
{
   cout << "Server::AddRef" << endl;
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}


ULONG_ __stdcall Server::Release()
{
   cout << "Server::Relese" << endl;
   fRefCount--;
   cout << "Current references: " << fRefCount << endl;
   if (fRefCount==0)
   {
     cout << "Self-destructing..." << endl;
     delete this;
     cout << "Self-destructing...OK" << endl;
   }
   return fRefCount;
}

//--------------------------------------------

HRESULT_ __stdcall Server::InputMas2() {
  cout << "Server::InputMas2" << endl;
  
  fstream f;

  f.open("GetX.txt");

  if(f.is_open()) {
    for (int i = 0; i < 5; i++) { 
      f >> x[i];
    }
  }
   else {
    cout << "No file opened" << endl;
  }

  f.close();

  return S_OK_;
}

HRESULT_ __stdcall Server::InputMas1() {
  cout << "Server::InputMas1" << endl;
  
  fstream f;

  f.open("GetN.txt");

  if(f.is_open()) {
    for (int i = 0; i < 5; i++) { 
      f >> n[i];
    }
  }
  else {
    cout << "No file opened" << endl;
  }

  f.close();

  return S_OK_;
}


HRESULT_ __stdcall Server::Sample_Average() 
{
  cout << "Server::Sample_Average" << endl;
  float sum = 0;
  for(int i = 0; i < 5; i++) {
    volume += n[i];
    sum += x[i] * n[i];
  }
  Sample_average = round(sum / volume * 100) / 100;
  cout<< "Sample_Average = " << Sample_average << endl << endl;

  return S_OK_;
}

HRESULT_ __stdcall Server::Sample_Variance()
{
  cout << "Server::Sample_Variance" << endl;
  float sum = 0;
  
  for(int i=0; i< 5; i++) {
    sum += pow((x[i]- Sample_average), 2) * n[i];
  }
  cout << "Sample_Variance = " <<  round(sum / volume * 100) / 100 << endl << endl;

  return S_OK_;
}

HRESULT_ __stdcall Server::Corrected_Sample_Variance()
{
  cout << "Server::Corrected_Sample_Variance" << endl;
  float sum = 0;

  for(int i=0; i< 5; i++) {
    sum += pow((x[i]- Sample_average), 2) * n[i];
  }
  cout << "Corrected_Sample_Variance = " << round(sum / (volume-1) * 100) / 100 << endl << endl;

  return S_OK_;
}


//******************************************************************************************


ServerFactory::ServerFactory() 
{
   cout << "ServerFactory::Constructor" << endl; 
   
   fRefCount = 0;
}

ServerFactory::~ServerFactory() 
{
  cout << "ServerFactory::Destructor" << endl;  
}


HRESULT_ __stdcall ServerFactory::QueryInterface(const IID_& iid, void** ppv)
{
   cout << "ServerFactory::QueryInterface:" << iid << endl;

   if (iid==IID_IUnknown_)
   {
    *ppv = (IUnknown_*)(IClassFactory_*)(this);
   }
   else if (iid == IID_IClassFactory_)
   {
    *ppv = (void**)(IClassFactory_*)(this);
   }
   else if (iid==IID_IMyClassFactory_)
   {
     *ppv = static_cast<IMyClassFactory_*>(this);
   } 
   else {
     *ppv = NULL;
     return E_NOINTERFACE_;
   }
   this->AddRef();
   return S_OK_;
}



ULONG_ __stdcall ServerFactory::AddRef()
{
   cout << "ServerFactory::AddRef" << endl;
   fRefCount++;
   cout << "Current references: " << fRefCount << endl;
   return fRefCount;
}

ULONG_ __stdcall ServerFactory::Release()
{
   cout << "ServerFactory::Relese" << endl;
   fRefCount--;
   cout << "Current references: " << fRefCount << endl;
   if (fRefCount==0)
   {
     cout << "Self-destructing..." << endl;
     delete this;
     cout << "Self-destructing...OK" << endl;
   }
   return fRefCount;
}

HRESULT_  __stdcall ServerFactory::CreateInstance(const IID_& iid, void** ppv)
{
   cout << "ServerFactory::CreateInstance" << endl;
   Server* p = new Server();
   p->AddRef();
   HRESULT_ res = p->QueryInterface(iid,ppv);
   p->Release();
   return res;
}

HRESULT_ __stdcall ServerFactory::CreateServer(const IID_& iid, void** ppv, int n, int x)
{	 	    		
  cout << "ServerFactory::CreateServer" << endl;
  Server* s = new Server(n, x); 
  s->AddRef();
  HRESULT_ res =  s->QueryInterface(iid,ppv);
  s->Release();  
  return res;  
}