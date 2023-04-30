#include <windows.h>
#include <stdio.h>

extern "C" __declspec(dllexport) HRESULT GetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
    printf("Manager::GetClassObject\n");

    try
    {
      const CLSID CLSID_Server = {0x91A42CAA,0x5777,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};
        
      const CLSID CLSID_Server_2 = {0x91A42CBA,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD7}};

      const char* path = NULL;
      if (clsid == CLSID_Server)
      {
         path = "./build/server/simple.dll";         
      }  
      else if (clsid == CLSID_Server_2)
      {
         path = "./build/server/super.dll";         
      }
      else
      {
        printf("Error path checking\n");
        throw "";
      }
      HINSTANCE h;

      h=LoadLibrary(path); 

      if (!h)
      {
        printf("!\n");
        throw "";
      }
      
      typedef HRESULT __stdcall (*DllGetClassObjectType) (const CLSID& clsid, const IID& iid, void** ppv);
      DllGetClassObjectType DllGetClassObject = (DllGetClassObjectType) GetProcAddress(h,"DllGetClassObject");

      if (!DllGetClassObject)
      {
        printf("Error getting address\n");
        throw "";
      }
      return DllGetClassObject(clsid,iid,ppv);
    }
    catch (...)
    {
        return E_UNEXPECTED;
    }
}

extern "C" __declspec(dllexport) HRESULT CreateInstance(const CLSID& clsid, IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    printf("Manager::CreateInstance\n");

    try
    {
       const IID IID_IClassFactory = {0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
       IClassFactory* pCF = NULL;
       HRESULT resFactory = GetClassObject(clsid,IID_IClassFactory,(void**)&pCF);
       if (SUCCEEDED(resFactory))
       {
          HRESULT resInstance = pCF->CreateInstance(pUnknownOuter,iid,ppv);
          pCF->Release();
          return resInstance;
       }
       else
       {
          return resFactory;
       }
    }
    catch (...)
    {
        *ppv = NULL;  
        return E_UNEXPECTED;
    }                    
}  


BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
             printf("Manager::DLL_PROCESS_ATTACH\n");
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            printf("Manager::DLL_PROCESS_DETACH\n");
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
