#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//构造函数语法
class CL1 {
public: 
	CL1() {
		//初始化…
	}
};

//析构函数语法
class CL2 {
public:
	~CL2() {
		//清理…
	}
};

//拷贝构造语法
class CL3 {
public:
	CL3(const CL3& src) {
		//将src向this指针拷贝…
	}
};

//赋值运算符重载
class CL4 {
public:
	CL4& operator=(const CL4& src) {
		//确认左右参数不为同一个值时开始赋值
		if (this != &src) {
			//赋值操作…
		}
		//返回左操作数
		return *this;
	}
};

//自增运算符的重载
class CL5 {
public:
	//前置++;
	CL5& operator++() {
		//数值自增
		this->m_iValue++;
		//返回新值
		return *this;
	}
	//后置++;
	CL5& operator++(int) {
		//拿到旧值
		CL5 temp(*this);
		//自增
		this->m_iValue++;
		//返回旧值
		return temp;
	}
private:
	int m_iValue = 0;
};

//对象取地址及const对象取地址
class CL6 {
public:
	//对象取地址
	CL6* operator&() {
		return this;
	}
	//const对象取地址
	const CL6* operator&()const {
		return this;
	}
};

int main_defaultMemberFunction() {


	cout << "Hello! Default member function!!!" << endl;
	return 0;
}