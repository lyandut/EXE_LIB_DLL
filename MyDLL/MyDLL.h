// 下列 ifdef 块是创建使从 DLL 导出更简单的宏的标准方法。
// 此 DLL 中的所有文件都是用命令行上定义的 MYDLL_EXPORTS符号编译的。
// 在使用此 DLL 的任何项目上不应定义此符号。
// 这样，源文件中包含此文件的任何其他项目都会将 MYDLL_API 函数视为是从 DLL 导入的，
// 而此 DLL 则将用此宏定义的符号视为是被导出的。
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

#include <iostream>

using namespace std;

// 导出函数（使用dllexport）
MYDLL_API void fnMyDLLWithDllExport(ostream &os);

// 导出函数（以C的方式声明）
extern "C" {
	MYDLL_API void fnMyDLLWithExternC(ostream &os);
}

// 导出函数（使用def文件）
void fnMyDLLWithDefFile(ostream &os);
