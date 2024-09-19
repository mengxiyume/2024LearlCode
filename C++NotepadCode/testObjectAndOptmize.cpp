#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
public:
	CL(int value = 10) : m_iValue(value) {
		cout << "testCL(int):\t构造" << endl;
	}
	CL(const CL& dest) : m_iValue(dest.m_iValue) {
		cout
	<< "testCL(const testCL&):\t拷贝构造" << endl;
	}
	~CL() {
		cout << "~testCL()\t析构" << endl;
	}
	CL& operator=(const CL& dest) {
		if (this != &dest) {
			//判定是否赋值给自身
			this->m_iValue = dest.m_iValue;
			cout
<< "testCL& operator=(const CL&)\t 赋值重载" << endl;
		}
		return *this;
	}
private:
	int m_iValue;
};

void Fn1(CL cl) {
	//参数列表拷贝构造
}
CL Fn2() {
	CL cl;	//创建对象构造
	return cl;	//返回值临时对象拷贝构造
}

int main_objectAndOptmize() {

	//传值传参时
	CL cl1;	//构造
	Fn1(cl1);	//拷贝构造-析构
	cout << endl;	//…析构

	//隐式类型构造-拷贝构造-析构
	Fn1(1);	//…析构
	cout << endl;

	//构造-拷贝构造-析构-…析构
	Fn1(CL(30));
	cout << endl;

	//传值返回时
	Fn2();	//构造-析构
	cout << endl;

	//构造-赋值重载-拷贝构造-析构
	CL cl2 = Fn2();	//…析构
	cout << endl;

	//赋值重载-拷贝构造-构造-析构
	cl1 = Fn2();	//…析构
	cout << endl;


	//cout << "Hello! object and optmize!!!" << endl;
	return 0;
}