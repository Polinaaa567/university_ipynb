#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "interfaces.h"
#include "Components.h"
#include <stdio.h>

#include <objbase.h>

//компонент
class Server_2: public ISample_Processing, IGet_Array, ISumma, IDispatch  {
	private: 
	 int a;
	 int b;
 	 int fRefCount;
	 int px1;

	 
	 IGet_Array* ig_Simple = NULL;
	 ISample_Processing* is_Simple = NULL;
     IClassFactory* pCF = NULL;

	public:
	 Server_2();
	 virtual ~Server_2();

	 virtual void __stdcall InputMas2();
	 virtual void __stdcall InputMas1();
	 virtual void __stdcall Sample_Average();  //выборочное среднее
	 virtual void __stdcall Sample_Variance(); //выборочная дисперсия
	 virtual void __stdcall Corrected_Sample_Variance(); //исправленная выборочная дисперсия 
	 virtual void __stdcall summ();

	 virtual HRESULT __stdcall GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId);
	 virtual HRESULT __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams,VARIANT* pVarResult,
                                    EXCEPINFO* pExcepInfo, UINT* puArgErr);

     virtual HRESULT __stdcall GetTypeInfoCount(UINT* pctinfo);
	 virtual HRESULT __stdcall GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo);
	
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