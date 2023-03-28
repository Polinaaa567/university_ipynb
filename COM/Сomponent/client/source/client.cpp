#include "lib/iserver.h"

#include <iostream>
using namespace std;

int main() {	    		
	cout << "Client::Main::Start" << endl;			
	
    IUnknown_* s = NULL;
    HRESULT_ resInit = CreateInstance(CLSID_Server,IID_IUnknown_,(void**)&s);
    if (resInit != S_OK_)
    {
       cout << "Client::Main::Error CreateInstance CLSID_Server - IID_IUnknown_" << resInit << endl;	
	   return 0;		
	}
	
	IGet_Array* pGA = NULL;
	HRESULT_ res = s->QueryInterface(IID_IGet_Array,(void**)&pGA);
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
	
	ISample_Processing* pSP = NULL;
	 res = pGA->QueryInterface(IID_ISample_Processing, (void **)&pSP);
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
	
	return 0;
}