// MyDLL.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "MyDLL.h"

MYDLL_API void fnMyDLLWithDllExport(ostream & os) {
	os << "this is my dll with dllexport." << endl;
}

MYDLL_API void fnMyDLLWithExternC(ostream & os){
	os << "this is my dll with extern C." << endl;
}

void fnMyDLLWithDefFile(ostream & os) {
	os << "this is my dll with def file." << endl;
}
