#include "lib/iserver.h"
#include "lib/common.h"
#include "lib/manager.h"

#include <iostream>
using namespace std;

int main() { //IMyClassFactory_ = //IServerFactory
	cout << "Client::Main::Start" << endl;	

	cout << "Client::Main::GetClassObject CServer&IClassFactory_" << endl;					
	
	IMyClassFactory_* pFactory = NULL;
	HRESULT_ res = GetClassObject(CLSID_CServer, IID_IMyClassFactory_, (void**)&pFactory);

    if (res != S_OK_)
    {
       cout << "Client::Main::Error CreateInstance CLSID_Server - IID_IUnknown_" << res << endl;	
	   return 0;		
	}
	
	IGet_Array* pGA = NULL;
	//HRESULT_ res = s->QueryInterface(IID_IGet_Array,(void**)&pGA);
	pFactory->CreateServer(IID_IGet_Array, (void**)&pGA,0,0);
	if (res==S_OK_)
	{
		cout << "Client::Main::Success IGet_Array: " << endl;			
		pGA->InputMas1();
		pGA->InputMas2();
	}	
	else
    {
	   cout << "Client::Main::Error query IID_IGet_Array: " << res << endl;	
	   return 0;		
	}
	cout << "Client::Main::QueryInterface IGet_Array->ISample_Processing" << endl;			
	ISample_Processing* pSP = NULL;
	res = pGA->QueryInterface(IID_ISample_Processing, (void **)&pSP);
	cout << "Client::Main::IGet_Array->Release" << endl;
	pGA->Release();
	if (res==S_OK_)
	{
		cout << "Client::Main::Success ISample_Processing:" << endl;
		pSP->Sample_Average();
		pSP->Sample_Variance();
		pSP->Corrected_Sample_Variance();
	}	
	else
    {
	   cout << "Client::Main::Error query IID_ISample_Processing" << res << endl;	
	   return 0;		
	}
	pSP->Release();

	pFactory->Release();
	
	return 0;
}