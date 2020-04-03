// MyEXE.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <MyLIB.h>
#include <MyDLL.h>
#include <Windows.h>

void dllLinkImplicitly() {
	fnMyDLLWithDllExport(std::cout);
	fnMyDLLWithExternC(std::cout);
	fnMyDLLWithDefFile(std::cout);
}

void dllLinkExplicitly() {
	typedef void(*LPFNDLLFUNC)(std::ostream &); 
	// equal to
	// using LPFNDLLFUNC = void(*)(std::ostream &);
	
	HINSTANCE hDLL;                     // Handle to DLL
	LPFNDLLFUNC lpfnMyDLLWithDllExport; // Function pointer
	LPFNDLLFUNC lpfnMyDLLWithExternC;   // Function pointer
	LPFNDLLFUNC lpfnMyDLLWithDefFile;   // Function pointer

	hDLL = LoadLibrary("MyDLL.dll");
	if (hDLL != NULL)
	{
		lpfnMyDLLWithDllExport = (LPFNDLLFUNC)GetProcAddress(hDLL, "fnMyDLLWithDllExport");
		lpfnMyDLLWithExternC = (LPFNDLLFUNC)GetProcAddress(hDLL, "fnMyDLLWithExternC");
		lpfnMyDLLWithDefFile = (LPFNDLLFUNC)GetProcAddress(hDLL, "fnMyDLLWithDefFile");

		if (!lpfnMyDLLWithDllExport) { // handle the error
			std::cout << "fnMyDLLWithDllExport load error.\n";
		}
		else { // call the function
			lpfnMyDLLWithDllExport(std::cout);
		}

		if (!lpfnMyDLLWithExternC) {
			std::cout << "lpfnMyDLLWithExternC load error.\n";
		}
		else {
			lpfnMyDLLWithExternC(std::cout);
		}

		if (!lpfnMyDLLWithDefFile) {
			std::cout << "lpfnMyDLLWithDefFile load error.\n";
		}
		else {
			lpfnMyDLLWithDefFile(std::cout);
		}
	}
	FreeLibrary(hDLL);
}

int main() {
	
	fnMyLIB(std::cout);

	dllLinkImplicitly();

	dllLinkExplicitly();

	std::cout << "this is my exe.\n";

	system("PAUSE");
}
