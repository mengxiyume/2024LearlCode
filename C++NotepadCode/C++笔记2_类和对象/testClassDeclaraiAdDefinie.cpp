#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//声明与定义都在类体中
class ClassDeclaraiAdDefinie_1 {
public:
	void func() {
		value = 10;
	}
private:
	int value;
};

//声明与定义分离—定义部分
#include "./testClassDeclaraiAdDefinie.h"
//返回值类型 作用域::函数名() {…}
void ClassDeclaraiAdDefinie_2::func() {
	value = 20;
}

int main_testClassDeclaraiAdDefinie() {

	cout << "Hello Class!!!" << endl;
	return 0;
}