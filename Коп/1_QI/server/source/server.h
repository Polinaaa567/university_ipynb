#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include "iserver.h"

class Server: public ISample_Processing {
	private:
	 int x[5] = {-3, -2, -1, 0, 1};
	 int n[5] = {5, 3, 2, 1, 1};
	 float volume;
	 float Sample_average;
	
	public:
	 Server();
	 ~Server();


	 virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);

	 virtual HRESULT_ __stdcall Sample_Average();
	 virtual HRESULT_ __stdcall Sample_Variance();
	 virtual HRESULT_ __stdcall Corrected_Sample_Variance();
};

#endif // SERVER_H_INCLUDED