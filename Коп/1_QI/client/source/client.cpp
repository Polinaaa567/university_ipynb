#include "lib/iserver.h"

#include <iostream>
using namespace std;

int main() {	    		
	cout << "Client::Main::Start" << endl;			
	
	
	IUnknown_* s = CreateServer(CLSID_Server);

	ISample_Processing* pSP = NULL;
	HRESULT_ res = s->QueryInterface(IID_ISample_Processing, (void **)&pSP);
	
	if (res==S_OK_)
	{
		cout << "Client::Main::Success IX:" << endl;
		pSP->Sample_Average();
		pSP->Sample_Variance();
		pSP->Corrected_Sample_Variance();
	}	
	else
    {
	   cout << "Client::Main::Error" << res << endl;			
	}

	IPrintResult* pPR = NULL;
	res = pSP->QueryInterface(IID_IPrintResult,(void**)&pPR);
	if (res==S_OK_)
	{
		cout << "Client::Main::Success IY: " << endl;			
		pPR->PrintResult();
	}	
	else
    {
	   cout << "Client::Main::Error IY: " << res << endl;			
	}
	
	
	return 0;
}