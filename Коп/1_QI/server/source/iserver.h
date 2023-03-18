#ifndef ISERVER_H_INCLUDED
#define ISERVER_H_INCLUDED

using CLIID_ = int;
using IID_ = int;
using HRESULT_ = int;

const int CLSID_Server = 1;

const int IID_IUnknown_ = 0;
const int IID_IGet_Array = 1;
const int IID_ISample_Processing = 2;


const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;

class IUnknown_
{
    public:	
     virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv)=0;
}; 

class ISample_Processing: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall Sample_Average()=0;
	 virtual HRESULT_ __stdcall Sample_Variance()=0;
	 virtual HRESULT_ __stdcall Corrected_Sample_Variance()=0;
};

class IGet_Array : public IUnknown_ {
	public: 
	 virtual HRESULT_ __stdcall GetX() = 0;
	 virtual HRESULT_ __stdcall GetN() = 0;
};


 IUnknown_* __stdcall CreateServer(const CLIID_& clsid);


#endif // ISERVER_H_INCLUDED