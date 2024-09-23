#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//类模板的定义
template<class T>
class Stack{
	//…
};

int main_classTemplate() {

	//类模板的实例化
	Stack<char> st1;	//Stack是类名
	Stack<int> st2;		//stack<>是类型
	//st1与st2为实例化后的不同类型对象

	cout << "Hello! class-template!!!" << endl;
	return 0;
}