#ifndef SERVER_H_2_INCLUDED
#define SERVER_H_2_INCLUDED

#include "interfaces_2.h"


//компонент
class Server_2: public ISumm {
	private: 
	  int fRefCount;
	 
	 int a;
     int b;

	public:
	 Server_2();
	 ~Server_2();

    virtual void __stdcall summa();


	 virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();
};

class ServerFactory_2: public IClassFactory {
    int fRefCount;
	public:
	 ServerFactory_2();
	 ~ServerFactory_2();

     virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();
	 virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
	 virtual HRESULT __stdcall LockServer(BOOL bLock);
};



#endif // SERVER_H_INCLUDED