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
    return (IUnknown_*)(IX*)s;
  }
  else if (clsid == 2)
  {
    cout << "Creaiting Server2..." << endl;
    Server2* s = new Server2();
    return (IUnknown_*)(IX*)s; 
  } 
  else
  {
    return NULL;
  }   
}