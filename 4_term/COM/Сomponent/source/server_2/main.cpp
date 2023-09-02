#include <stdio.h>
#include "Components.h"

extern "C" __declspec(dllexport) HRESULT __stdcall DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv) {
    println("Container::DllGetClassObject");
    return GetClassObject(clsid,iid,ppv);
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            println("Container_Super::DLL_PROCESS_ATTACH");
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            println("Container_Super::DLL_PROCESS_DETACH");
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
