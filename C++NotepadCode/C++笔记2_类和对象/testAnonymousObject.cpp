#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
public:
	CL(int value = 10) : m_iValue(value) {
		cout << "CL(int):\t构造" << endl;
	}
	~CL() { 
		cout << "~CL()\t析构" << endl;
	}
	//获取存储的值
	int m_fnGetValue() {
		return this->m_iValue;
	}
private:
	int m_iValue;
};

int main_anonymousObject() {
	CL cl1();	//不能够这样定义对象
	//因为编译器不能够分辨这是函数声明还是对象定义
	//匿名对象
	CL();	//调用构造一个
	cout << endl;
	CL(15);	//匿名对象
	cout << endl; 
	cout << CL(13).m_fnGetValue() << endl;
	//通常使用匿名对象时是想要使用匿名对象中的函数

	cout << "Hello! Anonymous-Object!!!" << endl;
	return 0;
}