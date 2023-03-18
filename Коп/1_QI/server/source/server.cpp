#include "server.h"

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


Server::Server() 
{
  volume = 0;
  Sample_average = 0;
  Sample_variance = 0;
	Corrected_Sample_variance = 0;

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
   else if (iid == IID_IPrintResult) {
    *ppv = (IPrintResult*)this;
    }
   
   else {
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
  Sample_variance = round(sum / volume * 100) / 100;
  cout << "Sample_Variance = " << Sample_variance << endl;

  return S_OK_;
}

HRESULT_ __stdcall Server::Corrected_Sample_Variance()
{
  float sum = 0;

  for(int i=0; i< 5; i++) {
    sum += pow((x[i]- Sample_average), 2) * n[i];
  }
  Corrected_Sample_variance = round(sum / (volume-1) * 100) / 100;
  cout << "Corrected_Sample_Variance = " << Corrected_Sample_variance << endl;

  return S_OK_;
}

HRESULT_ __stdcall Server::PrintResult() {
  ofstream out;

  out.open("C:\\Users\\ACER\\Desktop\\test.txt");
  
  if(out.is_open()) {
    out << "Sample_Average = " << Sample_average << endl;
    out << "Sample_Variance = " << Sample_variance << endl;
    out << "Corrected_Sample_Variance = " << Corrected_Sample_variance << endl;
    
  }

  cout << "End of program" << endl;

  out.close();

  return S_OK_;
}