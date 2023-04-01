#ifndef ISERVER_H_INCLUDED
#define ISERVER_H_INCLUDED

#include "common.h"


const int CLSID_CServer = 1;

const int IID_IGet_Array = 1;
const int IID_ISample_Processing = 2;
const int IID_IMyClassFactory_ = 101;

//интерфейс с методами для вычисления
class ISample_Processing: public IUnknown_
{
	public:
	 virtual HRESULT_ __stdcall Sample_Average()=0;  //выборочное среднее
	 virtual HRESULT_ __stdcall Sample_Variance()=0; //выборочная дисперсия
	 virtual HRESULT_ __stdcall Corrected_Sample_Variance()=0; //исправленная выборочная дисперсия 
};


//интерфейс с методами для считывания из файла
class IGet_Array: public IUnknown_ {
	public: 
	 virtual HRESULT_ __stdcall InputMas2() = 0;
	 virtual HRESULT_ __stdcall InputMas1() = 0;
};

class IMyClassFactory_: public IUnknown_ { //101
   public:
	virtual HRESULT_ __stdcall CreateServer(const IID_& iid, void** ppv, int n, int x) = 0;
};

#endif // ISERVER_H_INCLUDED