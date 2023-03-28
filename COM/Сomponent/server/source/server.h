#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "iserver.h"

class Server: public ISample_Processing, public IGet_Array {
	private: //обработка выборки
	  int fRefCount;
	 
	 int x[5];
	 int n[5];
	 float volume;
	 float Sample_average;
	
	public:
	 Server();
	 ~Server();


	 virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);
	 virtual ULONG_ __stdcall AddRef();
	 virtual ULONG_ __stdcall Release();


	 virtual HRESULT_ __stdcall Sample_Average();
	 virtual HRESULT_ __stdcall Sample_Variance();
	 virtual HRESULT_ __stdcall Corrected_Sample_Variance();

	 virtual HRESULT_ __stdcall InputMas1(); //n
	 virtual HRESULT_ __stdcall InputMas2(); //x
};

class ServerFactory: public IClassFactory_ {
    int fRefCount;
	public:
	 ServerFactory();
	 ~ServerFactory();

	 virtual ULONG_ __stdcall AddRef();
	 virtual ULONG_ __stdcall Release();
	 virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);

	 virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** ppv);
};

#endif // SERVER_H_INCLUDED