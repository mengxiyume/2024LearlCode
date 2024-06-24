#define _CRT_S4ECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//CPP基础语法

//命名空间 namespace 域
//
namespace test_06_21 {
	//在这个空间内的变量不会与其它空间内的同名变量命名冲突
	int arr[10] = { 0 };
	//访问域空间内的变量使用操作符"::"
	float x;
	float y;

}
short arr[3] = { 0 };

////展开命名空间 - 让编译器查找符号时出了局部域和全局域查找之外，也在展开的域里查找符号
////展开命名空间会有符号冲突风险
////编译器符号查找顺序
////局部域 -> 全局域 -> 已展开域(命名空间)
//using namespace test_06_21;
//展开命名空间内的符号
using test_06_21::x;

/*		域	编译的默认查找规则
*	域可以做到符号的隔离
*	
* 局部域		{}内的都是，包括函数等
* 全局域		没有被{}包围的域
* 名命空间域	存在全局域中，namespace后的{}包围的那一部分局部域，namespace可嵌套
* 类域			属于类的域，可嵌套，与namespace的域范围一样
* ----不同的域访问方式不同
*/

//int main() {
//	long long arr[7] = { 0 };
//	//域访问操作符无左操作数时访问全局域，无域访问操作符时先查找局部域，再查找全局域，自定的域内默认不在查找范围
//	cout << sizeof(test_06_21::arr) << " " << sizeof(::arr) << " " << sizeof(arr) << endl;
//
//	//cout << "Hello CPP!" << endl;
//	return 0;
//}