#ifndef Interfaces_H_INCLUDED
#define Interfaces_H_INCLUDED

#include <windows.h>


const IID IID_IUnknown = {0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_IClassFactory = {0x00000002,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

const IID IID_IGet_Array = {0x00000101,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
const IID IID_ISample_Processing = {0x00000102,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
// const IID IID_ISumma = {0x00000103,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

class ISample_Processing: public IUnknown
{
	public:
	 virtual HRESULT __stdcall Sample_Average()=0;  //выборочное среднее
	 virtual HRESULT __stdcall Sample_Variance()=0; //выборочная дисперсия
	 virtual HRESULT __stdcall Corrected_Sample_Variance()=0; //исправленная выборочная дисперсия 
};

//интерфейс с методами для считывания из файла
class IGet_Array: public IUnknown {
	public: 
	 virtual HRESULT __stdcall InputMas2() = 0;
	 virtual HRESULT __stdcall InputMas1() = 0;
};

// class ISumma: public IUnknown {
// 	public: 
// 	 virtual void __stdcall summ() = 0;
// };


#endif // Interfaces_H_INCLUDED