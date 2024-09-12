#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//引用的定义
//	类型名& 引用名 = 初始化对象;
void testReference01() {
	int i = 0;
	int& ri = i;	//引用ri初始化绑定i
	cout << i << ' ' << ri << endl;
}

//常引用，拥有常属性的对象的引用
void TestConstReference01() {
	const int a = 10;
	//int& ra = a;   // 该语句编译时会出错
	//a为常量	(const int&)
}

//函数传参
int Add(int& x, int& y) {
	return x + y;
}

//函数返回值
const int& Count() {
	static int count = 0;
	return ++count;
}

int main_reference() {
	 
	cout << "Hello Reference" << endl;
	return 0;
}