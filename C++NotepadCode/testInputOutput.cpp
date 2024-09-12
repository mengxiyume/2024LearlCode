#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main_inputOutput() {

	//使用cin与流提取操作符从标准输入(Console)
	//获取三个数值依次放入abc三个变量中
	int a, b, c;
	cin >> a >> b >> c;

	//使用cout与流插入操作符向标准输出(Console)
	//输出三个数值
	cout << a << ' ' << ' ' << b << c << endl;

	return 0;
}