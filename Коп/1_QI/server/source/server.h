#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "iserver.h"

class Server: public ISample_Processing, public IGet_Array {
	private: //обработка выборки
	 int x[5];
	 int n[5];
	 float volume;
	 float Sample_average;
	
	public:
	 Server();
	 ~Server();


	 virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);

	 virtual HRESULT_ __stdcall Sample_Average();
	 virtual HRESULT_ __stdcall Sample_Variance();
	 virtual HRESULT_ __stdcall Corrected_Sample_Variance();

	 virtual HRESULT_ __stdcall GetN();
	 virtual HRESULT_ __stdcall GetX();
};

#endif // SERVER_H_INCLUDED