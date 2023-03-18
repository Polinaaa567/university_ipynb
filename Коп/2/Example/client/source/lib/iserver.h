#ifndef ISERVER_H_INCLUDED
#define ISERVER_H_INCLUDED

using CLIID_ = int;
using IID_ = int;
using HRESULT_ = int;

const int CLSID_Server = 1;
const int CLSID_Server2 = 2;

const int IID_IUnknown_ = 0;
const int IID_IX = 1;
const int IID_IY = 2;

const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;

class IUnknown_
{
    public:	
     virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv)=0;
}; 

class IX: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall Fx1()=0;
	 virtual HRESULT_ __stdcall Fx2()=0;
};

class IY: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall Fy1()=0;
	 virtual HRESULT_ __stdcall Fy2()=0;
};

 IUnknown_* __stdcall CreateServer(const CLIID_& clsid);
#endif // ISERVER_H_INCLUDED