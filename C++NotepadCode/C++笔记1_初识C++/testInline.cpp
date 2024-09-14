#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//内联函数语法
//inline (正常函数语法…)
inline void Swap(int& a, int& b) {
	int x = a;
	a = b;
	b = x;
}

//由于宏的实现式由预编译阶段的直接替换内容实现的
//所以需要使用括号层层堆叠确保稳定
//但由于宏没有类型检查，依然不如内联函数安全
#define SUM(X, Y) ((X) + (Y))
inline int Sum(int x, int y) {
	return x + y;
}

int main_inline() {

	cout << "Hello! Inline!" << endl;
	return 0;
}