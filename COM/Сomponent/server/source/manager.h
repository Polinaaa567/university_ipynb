#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "common.h"


 HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv);

 HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv);

#endif // MANAGER_H_INCLUDED