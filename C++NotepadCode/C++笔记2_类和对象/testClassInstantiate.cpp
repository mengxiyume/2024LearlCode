#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//类
class CL {
	//…
};
int main_classInstantiate() {
	//在栈空间实例化
	CL cl1;
	//在堆空间实例化
	CL* cl2 = new CL();

	cout << "Hello! Instantiate!!!" << endl;
	return 0;
}