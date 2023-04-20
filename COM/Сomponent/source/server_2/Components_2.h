#ifndef COMPONENTS_H_INCLUDED
#define COMPONENTS_H_INCLUDED

#include <windows.h>

const CLSID CLSID_CA = {0x91A42CBB,0x2572,0x4E80,{0x91,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

void println(const char* str);

HRESULT __stdcall GetClassObject(const CLSID& clsid, const IID& iid, void** ppv);

#endif // COMPONENTS_H_INCLUDED
