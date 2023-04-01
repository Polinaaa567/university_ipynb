#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

using IID_ = int;
using CLSID_ = int;
using HRESULT_ = int;
using ULONG_ = int;


const int IID_IUnknown_ = 0;
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

class IClassFactory_: public IUnknown_
{
    public:	
     virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** ppv)=0;	 
};

#endif // COMMON_H_INCLUDED