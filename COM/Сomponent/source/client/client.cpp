#include <objbase.h>

#include <stdio.h>

#include "Interfaces.h"
#include <iostream>
using namespace std;

typedef HRESULT __stdcall (*GetClassObjectType) (const CLSID& clsid, const IID& iid, void** ppv);

const CLSID CLSID_Server = {0x91A42CAA,0x5777,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};


int main() { //IMyClassFactory_ = //IServerFactory
	printf("Client::Main::Start");	

	printf("Client::Main::GetClassObject CServer&IClassFactory_" );					
	try{
		GetClassObjectType GetClassObject;

		HINSTANCE h;

		h = LoadLibrary("./build/manager/main.dll");
		if (!h) {
			throw "No manager";
		}

		GetClassObject = (GetClassObjectType)GetProcAddress(h,"GetClassObject");
		
		if (!GetClassObject) {
        	throw "No manager method";
      	}
		
		IClassFactory* pCF = NULL;
      	
		HRESULT resFactory = GetClassObject(CLSID_Server,IID_IClassFactory,(void**)&pCF);
      
      	if (!(SUCCEEDED(resFactory))) {
         	throw "No factoty";
      	}

		IGet_Array* pGA = NULL;
		HRESULT resInstance = pCF->CreateInstance(NULL,IID_IGet_Array,(void**)&pGA);
     
      	if (!(SUCCEEDED(resInstance))) {
        	throw "No instance";
      	}

		printf("Client::Main::Success IGet_Array: ");			
		pGA->InputMas1();
		pGA->InputMas2();

		printf("Client::Main::QueryInterface IGet_Array->ISample_Processing");			
		ISample_Processing* pSP = NULL;
		HRESULT resQuery = pGA->QueryInterface(IID_ISample_Processing,(void**)&pSP);

		if (!(SUCCEEDED(resQuery))) {
          throw "No query";
      	}

		cout << "Client::Main::Success ISample_Processing:" << endl;
		pSP->Sample_Average();
		pSP->Sample_Variance();
		pSP->Corrected_Sample_Variance();

		ISample_Processing* pSP2 = pSP;
		pSP2->AddRef();
		pSP2->Sample_Average();
		pSP2->Sample_Variance();
		pSP2->Corrected_Sample_Variance();
      	pSP2->Release();

		pGA->Release();
		pSP->Release();
        pCF->Release();      
	}
	catch (const char* str) {
        printf("Main::Error: ");
        printf(str);
        printf("\n");
    }
    catch (...) {
        printf("Main::Error: Unknown\n");
    }
	
	printf("Main::Finish\n");
	
	return 0;
}