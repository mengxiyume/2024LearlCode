#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//const成员函数
class CL {
private:
	int m_iValue = 10;
public:
//const成员函数无法修改this指针指向的任何内容
	void print()const {
		cout << this->m_iValue << endl;
	}
	void setValue(int x) {
		this->m_iValue = x;
	}
};

int main_constMemberFunction() {

	cout << "Hello! const-member-function!!!" << endl;
	return 0;
}