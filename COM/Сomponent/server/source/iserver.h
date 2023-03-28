#ifndef ISERVER_H_INCLUDED
#define ISERVER_H_INCLUDED

using CLSID_ = int;
using IID_ = int;
using HRESULT_ = int;
using ULONG_ = int;

const int CLSID_Server = 1;

const int IID_IUnknown_ = 0;
const int IID_IGet_Array = 1;
const int IID_ISample_Processing = 2;
const int IID_IClassFactory_ = 100;


const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;
const int E_NOCOMPONENT_ = 2;

class IUnknown_
{
    public:	
     virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv)=0;
	 virtual ULONG_ __stdcall AddRef()=0;
	 virtual ULONG_ __stdcall Release()=0;
}; 

class ISample_Processing: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall Sample_Average()=0;  //выборочное среднее
	 virtual HRESULT_ __stdcall Sample_Variance()=0; //выборочная дисперсия
	 virtual HRESULT_ __stdcall Corrected_Sample_Variance()=0; //исправленная выборочная дисперсия 
};

class IGet_Array : public IUnknown_ {
	public: 
	 virtual HRESULT_ __stdcall InputMas2() = 0;
	 virtual HRESULT_ __stdcall InputMas1() = 0;
};

class IClassFactory_: public IUnknown_ { //100
   public:
	virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** ppv) = 0;
	virtual ULONG_ __stdcall AddRef()=0;
	virtual ULONG_ __stdcall Release()=0;
};

 HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv);
 HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv);


#endif // ISERVER_H_INCLUDED