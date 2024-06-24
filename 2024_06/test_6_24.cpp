#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/* 函数缺省参数
* 函数声明时可以有缺省参数，该参数在函数调用传参时可以不用填写
* 传参时未传入的参数将由缺省参数成为其默认值
* 函数传参从左到右，缺省参数也是如此，缺省参数不能被直接跳过
*/

void testFunc1(int a = 7) {
	cout << a << endl;
}

void testFunc2(int a = 7, int b = 9, int c = 2) {
	cout << a << ' ' << b << ' ' << c << endl;
}

void testFunc3(int a, int b = 9, int c = 2) {
	cout << a << ' ' << b << ' ' << c << endl;
}

int main() {

	cout << "TestFunc1" << endl;
	//打印缺省参数7
	testFunc1();
	//打印指定参数93
	testFunc1(93);

	cout << "TestFunc2" << endl;
	//直接打印缺省参数
	testFunc2();
	//从左到右指定参数，未指定参数由缺省填补
	testFunc2(1, 2);

	cout << "TestFunc3" << endl;
	//第一个参数不是缺省参数不能被跳过，如果不填入参数就会报错
	//testFunc3();
	//填入非缺省参数后剩下的参数可以不指定使用默认值
	testFunc3(21);
	testFunc3(22, 32);



	return 0;
}