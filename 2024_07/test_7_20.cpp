#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//函数式宏
#define _Add(a, b) ((a) + (b))

//inline内联标识符只是对于编译器的建议，函数复杂时编译器不一定会照办

//内联函数
//语法形式 - 在函数类型前添加inline标识
inline int Add(int a, int b) {
	return a + b;
}
//该语法为C语言中宏的尚未替代，书写方式为函数，展开方式与宏相同，但拥有类型检查会更加稳定
//且内联函数可以Debug，在禁用内联优化的debug模式下内联函数就是以函数形式出现，release模式将完全展开

void Test03() {
	//内联函数使用方式与正常函数相同
	//区别在于内联函数在调用时不建立栈帧，所以资源消耗更小调用速度更快，优势与函数式宏类似
	//其优于函数式宏之处在于由于不用担心参数优先级混乱，所以代码书写形式可以更加简洁明了
	//	并且可以Debug
	int sum = Add(1, 2);
	//配置工程属性->C/C++/常规/调试信息格式 - 程序数据库
	//配置工程属性->C/C++/优化/内联函数拓展 - 只适用于inline
	//该环境即可在Debug模式下通过汇编代码看到内联函数的源码，此时的Add是没有Call指令的
	//这就意味着Add并没有消耗建立栈帧的资源
	cout << sum << endl;
}

#include "./InlineTest.h"
//内联不能声明和定义分离
void Test04() {
	_F(20);
	F(10);	//声明定义分离的内联函数会报链接错误
	//内联函数在调用时会直接展开，这导致内联函数不需要地址而没有地址
	//链接器找不到内联函数的地址所以报错无法解析的符号
	//内联函数不进入符号表---
	//如果有类似需要的场景可以直接在.h文件内书写内联函数
}

//auto类型 - 自动推导类型
//auto会自动推导出表达式结果的类型，在复杂场景下可以精炼代码，（奇奇怪怪的地方使用有未发挥的力量/划掉）
void Test05() {

	//auto类型 - 它自己就把自己的类型算出来了.jpg
	int a = 3;
	char c = 'a';
	auto sum = a + c;
	//使用typeid来查看sum的类型
	cout << typeid(sum).name() << endl;

	//auto指针要求右值必须是指针
	auto* pAuto = &c;
	//auto指针在初始化完成之后类型就固定不可更改了
	//pAuto = &a;
	
	//auto也有引用类型，使用方法与特性同auto指针，但具有引用的特性
	auto& rAuto = sum;

	//auto类型不能用来直接声明数组,也不能够作为函数题内的传递参数
	//void TestAutoValueFunc(auto a, auto b);	//C++规定auto不能用作函数的接收参数类型
	//auto autoArr[] = { 1, 2, 3 };	//C++规定auto不能直接用来声明数组

	//auto在早期C语言中也存在过，已废弃
	//C语言中的自动变量	/*auto int a = 0;*/
	//这样定义的变量会自动销毁，看起来就像是现在的局部变量一样，离开作用域自动销毁
}

//范围For
//语法来源于python，语法支持C++11及以上
//自动获取数组中的值赋值给变量e，循环自动++和自动结束循环
void Test06() {
	//基础语法
	int arry[] = { 1, 2, 3, 4 };
	//e的变量名和类型不影响范围for语法，可以自己定义
	for (auto e : arry) {
		cout << e << endl;
	}
	//上述方法无法改变arry内的变量，如果想要改变可以使用auto变量
	int i = 0;
	for (auto& x : arry) {
		x = ++i;
		cout << x << endl;
	}
	//这个arry只能对数组使用，数组传参给函数之后函数拿到的是一个数组的地址
	//也就是数组不支持传参，范围for的arry选项不支持数组的地址，所以得另寻他法
}

//void TestFor(int arr[]) {
//	//arr为数组地址，范围for不支持使用地址填入范围栏
//	for (int x : arr) {
//		cout << x << ' ';
//	}
//	cout << endl;
//}

//属于C++的NULL类型为int
//属于C语言的NULL类型为一个指针
// C:	#define NULL ((void*)0)
// C++:	#define NULL 0
//所以在C++中表示指针的部分应使用nullptr替代C语言中的NULL，否则可能会出现奇怪的错误

void TestNullType(int i) {
	cout << "int" << endl;
}
void TestNullType(int* i) {
	cout << "(void*)" << endl;
}

void Test07() {
	TestNullType(NULL);	//这里直接就调用了参数为整形的重载
	//在使用指针的环境下用NULL会导致在C++中的错误调用
	//请在C++中使用nullptr代替NULL用于表示空指针
	TestNullType(nullptr);
	//nullptr为C++11引入的关键字，所以不需要引用像cstddef这样的头文件才能使用
}

int main() {
	Test07();
	cout << "Hello inline!" << endl;
	return 0;
}