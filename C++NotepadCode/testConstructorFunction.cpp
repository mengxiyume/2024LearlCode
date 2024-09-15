#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//初始化列表: 以一个冒号开始，接着是一个以逗号分隔的数据成员列表
//每个"成员变量"后面跟一个放在括号中的初始值或表达式
class CL1 {
private:
	int m_iValue1;
	int m_iValue2;
public:
	CL1(int v1, int v2) : m_iValue1(v1), m_iValue2(v2) {};
};

//(explicit)关键字
class CL2 {
private:
	int m_iValue1;
	int m_iValue2;
public:
	explicit CL2(int v1)
		:m_iValue1(v1)
		, m_iValue2(20) {
		//explicit修饰的构造会禁用隐式类型转换
		//也就是强制调用构造的时候传入该类对象 
	}
	//explicit CL2(int v1, int v2 = 30)
	//:m_iValue1(v1)
	//, m_iValue2(v2) {
	//	//...
	//}
	CL2& operator=(const CL2& src) {
		this->m_iValue1 = src.m_iValue1;
		this->m_iValue2 = src.m_iValue2;
		return *this;
	}
};

int main_constructorFunction() {
	//CL2 cl(5);
	//cl = 30;

	cout << "Hello! constructor-function!!!" << endl;
	return 0;
}