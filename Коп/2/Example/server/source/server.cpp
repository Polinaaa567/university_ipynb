#include "server.h"

#include <iostream>
using namespace std;


Server::Server() 
{
  cout << "Server::Constructor" << endl;
  a = 10;
  b = 20;
}

Server::~Server() 
{
  cout << "Server::Destructor" << endl;  
}

HRESULT_ __stdcall Server::QueryInterface(const IID_& iid, void** ppv)
{
  if (iid == IID_IX)  {
    cout << "Server::QueryInterface:" << iid << endl;   
    *ppv = static_cast<IX*>(this);
  }
  else if (iid == IID_IY) {
    cout << "Server::QueryInterface:" << iid << endl;   
      *ppv = static_cast<IY*>(this);
  }
  else{
    cout << "Server::QueryInterface:" << iid << endl;   
    return E_NOINTERFACE_;
  }
  return S_OK_; 
}

	
HRESULT_ __stdcall Server::Fx1() 
{	 	    		
  cout << "Server::Fx1" << endl;
  a = a + 1;
  cout << "a=" << a << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::Fx2() 
{	 	    		
  cout << "Server::Fx2" << endl;
  a = a + 2;
  cout << "a=" << a << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::Fy1() 
{	 	    		
  cout << "Server::Fy1" << endl;
  b = b + 1;
  cout << "b=" << b << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server::Fy2()
{	 	    		
  cout << "Server::Fy2" << endl;
  b = b + 2;
  cout << "b=" << b << endl;
  return S_OK_;
}

//*****************************************

Server2::Server2() 
{
  cout << "Server2::Constructor" << endl;
  c = 100;
  d = 200;
  e = 300;
}

Server2::~Server2() 
{
  cout << "Server2::Destructor" << endl;  
}

HRESULT_ __stdcall Server2::QueryInterface(const IID_& iid, void** ppv)
{
  if (iid == IID_IX)  {
    cout << "Server2::QueryInterface:" << iid << endl;   
    *ppv = static_cast<IX*>(this);
  }
  else {
      cout << "Server2::QueryInterface:" << iid << endl;
      return E_NOINTERFACE_;
  }
  return S_OK_; 
}

	
HRESULT_ __stdcall Server2::Fx1() 
{	 	    		
  cout << "Server2::Fx1" << endl;
  c = c + 10;
  d = d + 20;
  e = e + 30;
  cout << "c+d+e=" << c+d+e << endl;
  return S_OK_;
}

HRESULT_ __stdcall Server2::Fx2() 
{	 	    		
  cout << "Server2::Fx2" << endl;
  c = c + 100;
  d = d + 200;
  e = e + 300;
  cout << "c+d+e=" << c+d+e << endl;
  return S_OK_;
}