#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//函数式宏
#define _Add(a, b) ((a) + (b))

//内联函数
//语法形式 - 在函数类型前添加inline标识
inline int Add(int a, int b) {
	return a + b;
}
//该语法为C语言中宏的尚未替代，书写方式为函数，展开方式与宏相同，但拥有类型检查会更加稳定
//且内联函数可以Debug，在禁用内联优化的debug模式下内联函数就是以函数形式出现，release模式将完全展开

void Test01() {
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

int main() {
	Test01();
	cout << "Hello inline!" << endl;
	return 0;
}