#include "server.h"
#include <objbase.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Server_2::Server_2() {
   a = 5;
   b = 8;
   px1=123;

   println("Server_2::Server_2");
   fRefCount = 0;

   // CoInitialize(NULL);

//   HINSTANCE h;
//   h=LoadLibrary("./build/manager/main.dll");
//   if (!h) {
//      throw "No manager";
//   }
   
//   CreateInstanceType CreateInstance = (CreateInstanceType) GetProcAddress(h,"CreateInstance");
//   if (!CreateInstance) {
//      throw "No manager method";
//   }
  //Getting manager method (End)

  CLSID CLSID_Server_ProgID;
  {
      const wchar_t* progID = L"App.Application";
      //mbstowcs;
      //wcstombs
      HRESULT resCLSID_ProgID = CLSIDFromProgID(progID,&CLSID_Server_ProgID);
      if (!(SUCCEEDED(resCLSID_ProgID))) {        
         throw "No CLSID form ProgID";         
      }
      else {
         printf("CLSID form ProgID2 OK!");
         printf("\n");
      }
   }
       
   // const CLSID CLSID_Server = {0x91A42CAA,0x5777,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};
        
   // HRESULT resFactory = CoGetClassObject(,CLSCTX_INPROC_SERVER,NULL,IID_IClassFactory,(void**)&pCF);
   // println("Server_2::LYYYYYYYYY DA SCOLKO MOSHNO");

   // if (!(SUCCEEDED(resFactory))) {
   //    throw "Server_2::No factory";
   // }

   HRESULT resInstance = CoCreateInstance(CLSID_Server_ProgID,NULL,CLSCTX_INPROC_SERVER,IID_IGet_Array,(void**)&ig_Simple);
   if (!(SUCCEEDED(resInstance))) {
      throw "Server_2::No instance";
   }

   HRESULT resY = ig_Simple->QueryInterface(IID_ISample_Processing,(void**)&is_Simple);
   if (!(SUCCEEDED(resY))) {
      throw "Server_2::No query";
   }
      
  //Injecting component (End)
}

Server_2::~Server_2() {
   println( "Server_2::Destructor");  
   
   ig_Simple->Release();
   is_Simple->Release();
   // pCF->Release();
   
   // CoUninitialize();
}

HRESULT __stdcall Server_2::QueryInterface(const IID& iid, void** ppv) {
   println("Server_2::QueryInterface");

   if (iid == IID_IUnknown) {
      *ppv = (IUnknown*)(IGet_Array*)this;
   }
   else if (iid == IID_IGet_Array) {
      *ppv = (IGet_Array*)this;
   }
   else if (iid == IID_ISample_Processing) {
      *ppv = (ISample_Processing*)this;
   }
   else if (iid == IID_ISumma) {
      *ppv = (ISumma*)this;
   }
   else if (iid == IID_IDispatch){
      *ppv = (IDispatch*)this;
   }
   else {
      *ppv = NULL;
      return E_NOINTERFACE;
   }
   this->AddRef();
   return S_OK;
}

ULONG __stdcall Server_2::AddRef() {
   println("Server_2::AddRef");
   fRefCount++;
   cout << "Server_2::Current references: " << fRefCount << endl;
   return fRefCount;
}

ULONG __stdcall Server_2::Release() {
   println("Server_2::Release");
   fRefCount--;
   cout << "Server_2::Current references: " << fRefCount << endl;
   if (fRefCount==0) {delete this;}
   return fRefCount;
}

//методы компонента

void __stdcall Server_2::InputMas1() {
   println("Server_2::InputMas1:Full delegating to the server component ");
   ig_Simple->InputMas1();
}

void __stdcall Server_2::InputMas2() {
   println("Server_2::InputMas2:Full delegating to the server component");
   ig_Simple->InputMas2();
}

void __stdcall Server_2::Sample_Average() {
   println("Server_2::Sample_Average:Full delegating to the server component");
   is_Simple->Sample_Average();
}

void __stdcall Server_2::Sample_Variance() {
   println("Server_2::Sample_Variance:Full delegating to the server component");
   is_Simple->Sample_Variance();
}

void __stdcall Server_2::Corrected_Sample_Variance() {
   println("Server_2::Corrected_Sample_Variance:Full delegating to the server component");
   is_Simple->Corrected_Sample_Variance();
}

void __stdcall Server_2::summ(){
   cout<< "Server_2::summ = " << a + b << endl;
}

//-------------------------------------------------

HRESULT __stdcall Server_2::GetTypeInfoCount(UINT* pctinfo)
{
   println("Server_2:GetTypeInfoCount");
   return S_OK;
}

HRESULT __stdcall Server_2::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
{
   println("Server_2:GetTypeInfo");
   return S_OK;
}

HRESULT __stdcall Server_2::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                                    LCID lcid, DISPID* rgDispId)
{
   println("Server_2:GetIDsOfNames");
   if (cNames!=1) {return E_NOTIMPL;}

   if (wcscmp(rgszNames[0], L"summ") == 0) {
      rgDispId[0] = 1;
   }
   else if (wcscmp(rgszNames[0], L"Px1") == 0) {
      rgDispId[0] = 2;
   }
   else if (wcscmp(rgszNames[0], L"InputMas1") == 0) {
      rgDispId[0] = 3;
   }
   else if (wcscmp(rgszNames[0], L"InputMas2") == 0) {
      rgDispId[0] = 4;
   }
   else if (wcscmp(rgszNames[0], L"Sample_Average") == 0) {
      rgDispId[0] = 5;
   }
   else if (wcscmp(rgszNames[0], L"Sample_Variance") == 0) {
      rgDispId[0] = 6;
   }
   else if (wcscmp(rgszNames[0], L"Corrected_Sample_Variance") == 0) {
      rgDispId[0] = 7;
   }
   else {
      return E_NOTIMPL;
   }
   
   return S_OK;
}

HRESULT __stdcall Server_2::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult,
                             EXCEPINFO* pExcepInfo, UINT* puArgErr) {
   println("Server_2:Invoke");
   if (dispIdMember==1) {
      summ();
   }
   else if(dispIdMember==2) {
      if((wFlags==DISPATCH_PROPERTYGET) || (wFlags == 1) || (wFlags == 3)) {
         if(pVarResult!=NULL) {
            pVarResult->vt = VT_INT;
            pVarResult->intVal = px1;
         }
      }
      else if (wFlags==DISPATCH_PROPERTYPUT) {
         DISPPARAMS param = *pDispParams;
         VARIANT arg = (param.rgvarg)[0];
         VariantChangeType(&arg,&arg,0,VT_INT);
         px1 = arg.intVal;
      }
      else {
         return E_NOTIMPL;
      }
   } 
   else if(dispIdMember==3){
      InputMas1();
   }
   else if(dispIdMember==4){
      InputMas2();
   }
    else if(dispIdMember==5){
      Sample_Average();
   }
    else if(dispIdMember==6){
      Sample_Variance();
   }
    else if(dispIdMember==7){
      Corrected_Sample_Variance();
   }
   else {
      return E_NOTIMPL;
   }
   return S_OK;
}
//******************************************************************************************

ServerFactory_2::ServerFactory_2() {
   println("ServerFactory_2::Constructor"); 
   
   fRefCount = 0;
}

ServerFactory_2::~ServerFactory_2() {
   println("ServerFactory_2::Destructor");  
}

HRESULT __stdcall ServerFactory_2::QueryInterface(const IID& iid, void** ppv) {
   println("ServerFactory_2::QueryInterface");

   if (iid==IID_IUnknown) {
      *ppv = (IUnknown*)(IClassFactory*)this;
   }
   else if (iid == IID_IClassFactory) {
      *ppv = (IClassFactory*)this;
   }
   else {
      *ppv = NULL;
      return E_NOINTERFACE;
   }
   
   this->AddRef();
   return S_OK;
}

ULONG __stdcall ServerFactory_2::AddRef() {
   println("ServerFactory_2::AddRef");
   fRefCount++;
   cout << "ServerFactory_2::Current references: " << fRefCount << endl;
   return fRefCount;
}

ULONG __stdcall ServerFactory_2::Release() {
   println("ServerFactory_2::Release");
   fRefCount--;
   cout << "ServerFactory_2::Current references: " << fRefCount << endl;
   if (fRefCount==0) {delete this;}
   return fRefCount;
}

HRESULT  __stdcall ServerFactory_2::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv) {
   println("ServerFactory_2::CreateInstance");
   
   if (pUnknownOuter!=NULL) {
      return E_NOTIMPL;
   }
   
   Server_2* p = new Server_2();
   return p->QueryInterface(iid,ppv);
}

HRESULT __stdcall ServerFactory_2::LockServer(BOOL bLock) {
   println("ServerFactory_2::LockServer");
   return S_OK;
}

void println(const char* str) {
   printf(str);
   printf("\n");
}

// 91A42CBA-2577-4E80-934E-07DE64502FD7
// const CLSID CLSID_Server_2= {0x91A42CBA,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD7}};

HRESULT __stdcall GetClassObject(const CLSID& clsid, const IID& iid, void** ppv) {
   println("Component Server_2::GetClassObject");
   CLSID CLSID_Server_2_ProgID;
		{
			const wchar_t* progID = L"IKS.Application";
			HRESULT resCLSID_ProgID = CLSIDFromProgID(progID,&CLSID_Server_2_ProgID);
			if (!(SUCCEEDED(resCLSID_ProgID))) {        
				throw "No CLSID form ProgID";         
			}
			else {
				printf("CLSID form ProgID OK!");
				printf("\n");
			}
      }
   if (clsid==/*CLSID_Server_2*/CLSID_Server_2_ProgID) {
      // try {
         ServerFactory_2* fa  = new ServerFactory_2();
         return fa->QueryInterface(iid, ppv);
      // }
      // catch(...) {
      //    *ppv = NULL; 
      //    return E_UNEXPECTED;
      // }
   }
   else {
      *ppv = NULL;
      return E_NOTIMPL;
   }
}
