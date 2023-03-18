#include "lib/iserver.h"

#include <iostream>
using namespace std;

int main() {	    		
	cout << "Client::Main::Start" << endl;			
	
	
	IUnknown_* s = CreateServer(CLSID_Server);

	IX* pIX = NULL;
    HRESULT_ res = s->QueryInterface(IID_IX,(void**)&pIX);
    if (res==S_OK_)
	{
		cout << "Client::Main::Success IX: " << endl;			
		pIX->Fx1();
		pIX->Fx2();
	}	
	else
    {
	   cout << "Client::Main::Error IX: " << res << endl;			
	}
	
	
	return 0;
}