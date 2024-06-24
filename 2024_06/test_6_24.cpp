#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


namespace defaultParams {

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

	void test() {
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

	}

}

namespace funcReload {

	/*
	* 函数重载
	* 允许同名但参数列表不同的函数在同一个域中定义声明
	* 函数不能以同一参数裂变多次重载
	* 函数的返回值不同不能够构成重载
	* 参数列表不包括参数名，参数的类型才是最重要的区分方式
	*/

	//这两个函数构成重载，其参数列表不同
	void swap(int* a, int* b) {
	}
	void swap(char* a, char* b) {
	}

	////这两个函数不构成重载，仅返回值无法区分调用的是哪个函数
	//int getMax(int a, int b) {
	//}
	//bool getMax(int a, int b) {
	//}

	namespace test_1 {
		void _test() {};
	}
	namespace test_2 {
		void _test() {};
	}

	using namespace test_1;
	using namespace test_2;

	void test() {
		//在不同域中的同名函数不构成重载，但是都可以单独进行使用
		test_1::_test();
		test_2::_test();

		////如果将两个域都展开，虽然也不会构成重载，但是调用时会发生调用歧义
		//_test();
	}
}

int main() {

	//defaultParams::test();

	

	return 0;
}