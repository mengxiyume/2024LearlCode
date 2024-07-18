#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//引用
//引用的语法 
//	引用是一种变量的别名，声明方法为在变量类型的后面加上&
//	引用变量的使用与指针类似，但使用时不需要解引用操作符，且引用变量与原变量相比，不会产生权限的变化
//	int x = 10;
//	int& a = x;
//	指针没有指定const之前指向的内容不能更换，引用则永远不能更换，这是引用的指向性，也就是引用是绑定某一个变量的意思

int main() {

	cout << "Hello & !" << endl;
	return 0;
}