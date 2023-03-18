#include "server.h"

#include <iostream>
using namespace std;


IUnknown_* __stdcall CreateServer(const CLIID_& clsid)
{
  cout << "Function::CreateServer:" << clsid << endl;
  if (clsid == 1) 
  {
    cout << "Creaiting Server..." << endl;
    Server* s = new Server();
    return (IUnknown_*)(ISample_Processing*)s;
  }
  else
  {
    return NULL;
  }   
}