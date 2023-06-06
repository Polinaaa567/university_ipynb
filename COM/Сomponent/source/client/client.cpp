#include <objbase.h>
#include <stdio.h>

#include "Interfaces.h"

// typedef HRESULT __stdcall (*GetClassObjectType) (const CLSID& clsid, const IID& iid, void** ppv);

int main() { 
	printf("Client::Main::Start\n");	
				
	try {
		// GetClassObjectType GetClassObject;

// сначала связь между сервером и клиентом происходила через менеджер
		// HINSTANCE h;

		// h = LoadLibrary("./build/manager/main.dll");
		// if (!h) {
		// 	throw "No manager";
		// }

		// GetClassObject = (GetClassObjectType)GetProcAddress(h,"GetClassObject");
		
		// if (!GetClassObject) 
		// {
        // 	throw "No manager method";
      	// }
// инициализация COM среды
		CoInitialize(NULL);
	// гуиды серверов
		// {91A42CAA-5777-4E80-934E-07DE64502FD6}
		//App.ApplicationЖ const CLSID CLSID_Server = {0x91A42CAA,0x5777,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};
		//IKS.Application: const CLSID CLSID_Server_2 = {0x91A42CBA,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD7}};

		CLSID CLSID_Server_2_ProgID;
		{
			const wchar_t* progID = L"IKS.Application";
			// mbstowcs;
			//wcstombs

			// CLSIDFromProgID - это метод в технологии COM, который используется для получения идентификатора класса (CLSID) 
			// объекта COM по его ProgID
			HRESULT resCLSID_ProgID = CLSIDFromProgID(progID,&CLSID_Server_2_ProgID);
			if (!(SUCCEEDED(resCLSID_ProgID))) {        
				throw "No CLSID form ProgID";         
			}
			else {
				printf("CLSID form ProgID OK!");
				printf("\n");
			}
      	}

		IClassFactory* pCF = NULL;
      	
		// HRESULT resFactory = CoGetClassObject(CLSID_Server2,CLSCTX_INPROC_SERVER,NULL,IID_IClassFactory,(void**)&pCF);
		// CoGetClassObject получает указатель на фабрику объекта по его идентификкатору
		
		// ppv: указатель на переменную, в которую будет записан указатель на созданный объект.
		
		// Фабрика классов отвечает за создание экземпляров объектов данного класса.
		
		// Функция принимает идентификатор класса объекта и идентификатор интерфейса, который должен быть реализован фабрикой классов, 
		// и возвращает указатель на объект, реализующий этот интерфейс.
      	HRESULT resFactory = CoGetClassObject(CLSID_Server_2_ProgID,CLSCTX_INPROC_SERVER,NULL,IID_IClassFactory,(void**)&pCF);
      	if (!(SUCCEEDED(resFactory))) {
         	throw "Client::Main::No factory";
      	}

		IGet_Array* pGA = NULL;
		// CreateInstance получает экземпляр класса 
		HRESULT resInstance = pCF->CreateInstance(NULL,IID_IGet_Array,(void**)&pGA);
     
      	if (!(SUCCEEDED(resInstance))) {
        	throw "Client::Main::No instance";
      	}

		printf("Client::Main::Success IGet_Array: \n");			
		pGA->InputMas1();
		pGA->InputMas2();
// QueryInterface получение указателя на другой объект 
//  Этот метод позволяет коду клиента проверять, 
// поддерживает ли объект определенный интерфейс,
//  и получать доступ к этому интерфейсу, если он, конечно, доступен
		printf("Client::Main::QueryInterface IGet_Array->ISample_Processing\n");			
		ISample_Processing* pSP = NULL;
		HRESULT resQuery = pGA->QueryInterface(IID_ISample_Processing,(void**)&pSP);

		if (!(SUCCEEDED(resQuery))) {
          throw "Client::Main::No query";
      	}

		ISumma* is = NULL;
		resQuery = pGA->QueryInterface(IID_ISumma,(void**)&is);
		if (!(SUCCEEDED(resQuery))) {
			throw "Client::Main::No query_2";
		}

		printf("Client::Main::Success ISample_Processing:\n");
		pSP->Sample_Average();
		pSP->Sample_Variance();
		pSP->Corrected_Sample_Variance();
		is->summ();   
		
		// как я поняла, (а я мало что понимаю))), но IDispatch позволяет другим приложениям использовать мой объект
		IDispatch* pDisp = NULL;
      
		HRESULT resQueryDisp = pGA->QueryInterface(IID_IDispatch,(void**)&pDisp);
		if (!(SUCCEEDED(resQueryDisp)))
		{
			throw "No query dispatch";
		}

		DISPID dispid;

		int namesCount = 1;
		OLECHAR** names = new OLECHAR*[namesCount];
		OLECHAR* name = const_cast<OLECHAR*>(L"summ");
		names[0] = name;
		HRESULT resID_Name = pDisp->GetIDsOfNames(
													IID_NULL_,
													names,
													namesCount,
													GetUserDefaultLCID(),
													&dispid
												);

		if (!(SUCCEEDED(resID_Name))) {
			printf("No ID of name\n");
		}
		else {
			DISPPARAMS dispparamsNoArgs = {
											NULL,
											NULL,
											0,
											0,
										};
// Invoke используется для вызова методов и чтения свойств объекта
			HRESULT resInvoke = pDisp->Invoke (
												dispid, // DISPID
												IID_NULL_,
												GetUserDefaultLCID(),
												DISPATCH_METHOD,
												&dispparamsNoArgs,
												NULL,
												NULL,
												NULL
											);
			if (!(SUCCEEDED(resInvoke))) {
				printf("Invoke error\n");
			}
		}

		pDisp->Release();
		pSP->Release();
		pGA->Release(); 
		is->Release(); 
		pCF->Release(); 
	}
	catch (const char* str) {
        printf("Main::Error: \n");
        printf(str);
        printf("\n");
    }
    catch (...) {
        printf("Main::Error::Unknown\n");
    }

	CoUninitialize();
	
	printf("Main::Finish\n");
	
	return 0;
}