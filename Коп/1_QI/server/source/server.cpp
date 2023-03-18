#include "server.h"

#include <iostream>
#include <math.h>
using namespace std;


Server::Server() 
{
  volume = 0;
  Sample_average = 0;

  cout << "Server::Constructor" << endl;
}

Server::~Server() 
{
  cout << "Server::Destructor" << endl;  
}

HRESULT_ __stdcall Server::QueryInterface(const IID_& iid, void** ppv)
{
   cout << "Server::QueryInterface:" << iid << endl;

   if (iid==IID_IUnknown_)
   {
     *ppv = (IUnknown_*)(ISample_Processing*)this;
   }
   else if (iid == IID_ISample_Processing)
   {
     *ppv = static_cast<ISample_Processing*>(this);
   }
   
   else
   {
     *ppv = NULL;
     return E_NOINTERFACE_;
   }
   return S_OK_;
}

	
HRESULT_ __stdcall Server::Sample_Average() 
{
  float sum = 0;
  for(int i = 0; i < 5; i++) {
    volume += n[i];
    sum += x[i] * n[i];
  }
  Sample_average = round(sum / volume * 100) / 100;
  cout<< "Sample_Average = " << Sample_average << endl;

  return S_OK_;
}

HRESULT_ __stdcall Server::Sample_Variance()
{
  float sum = 0;
  
  for(int i=0; i< 5; i++) {
    sum += pow((x[i]- Sample_average), 2) * n[i];
  }

  cout << "Sample_Variance: " << round(sum / volume * 100) / 100 << endl;

  return S_OK_;
}

HRESULT_ __stdcall Server::Corrected_Sample_Variance()
{
  float sum = 0;

  for(int i=0; i< 5; i++) {
    sum += pow((x[i]- Sample_average), 2) * n[i];
  }

  cout << "Corrected_Sample_Variance: " << round(sum / (volume-1) * 100) / 100 << endl;

  return S_OK_;
}
