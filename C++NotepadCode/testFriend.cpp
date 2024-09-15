#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//使用友元重载 operator<< 函数
class CL1 {
	//在类内部声明，连结两个原本没有关系的类
	friend ostream& operator<<(ostream& dest, const CL1& src);
private:
	int m_iValue = 10;
};
//在类外定义，实现功能
ostream& operator<<(ostream& dest, const CL1& src) {
	dest << src.m_iValue;
	return dest;
}	//operator>>函数同理

//友元类
class CL2 {
	//在CL2中声明CL3为其友元类
	//CL3即可直接访问CL2中所有元素
	//但CL2不能访问CL3中元素
	friend class CL3;
public:
	int m_iValue1 = 1;
protected:
	int m_iValue2 = 2;
private:
	int m_iValue3 = 3;
};
class CL3 {
private:
	CL2 cl2;
public:
	//可以成功编译
	void printCL2() {
		cout << cl2.m_iValue1 << endl;
		cout << cl2.m_iValue2 << endl;
		cout << cl2.m_iValue3 << endl;
	}
};

int main_friend() {

	cout << "Hello! CPP friend!!!" << endl;
	return 0;
}