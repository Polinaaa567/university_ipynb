#include "lib/iserver.h"

#include <iostream>
using namespace std;

int main() {	    		
	cout << "Client::Main::Start" << endl;			
	
	
	IUnknown_* s = CreateServer(CLSID_Server);

	
	
	IGet_Array* pGA = NULL;
	HRESULT_ res = s->QueryInterface(IID_IGet_Array,(void**)&pGA);
	if (res==S_OK_)
	{
		cout << "Client::Main::Success IGet_Array: " << endl;			
		pGA->GetN();
		pGA->GetX();
	}	
	else
    {
	   cout << "Client::Main::Error IY: " << res << endl;			
	}
	
	ISample_Processing* pSP = NULL;
	 res = pGA->QueryInterface(IID_ISample_Processing, (void **)&pSP);
	if (res==S_OK_)
	{
		cout << "Client::Main::Success ISample_Processing:" << endl;
		pSP->Sample_Average();
		pSP->Sample_Variance();
		pSP->Corrected_Sample_Variance();
	}	
	else
    {
	   cout << "Client::Main::Error" << res << endl;			
	}

	
	return 0;
}