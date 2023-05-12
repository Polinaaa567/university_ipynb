#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "interfaces.h"

//компонент
class Server: public ISample_Processing, IGet_Array {
	private: //обработка выборки
	  int fRefCount;
	 
	 int x[5];
	 int n[5];
	 float volume;
	 float Sample_average;
	
	public:
	 Server();
	 ~Server();

	 virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();

	 virtual void __stdcall Sample_Average();
	 virtual void __stdcall Sample_Variance();
	 virtual void __stdcall Corrected_Sample_Variance();

	 virtual void __stdcall InputMas1(); //n
	 virtual void __stdcall InputMas2(); //x
};

class ServerFactory: public IClassFactory {
    int fRefCount;
	public:
	 ServerFactory();
	 ~ServerFactory();

     virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	 virtual ULONG __stdcall AddRef();
	 virtual ULONG __stdcall Release();
	 
	 virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
	 virtual HRESULT __stdcall LockServer(BOOL bLock);
};

#endif // SERVER_H_INCLUDED