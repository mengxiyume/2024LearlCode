#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//const��Ա����
class CL {
private:
	int m_iValue = 10;
public:
//const��Ա�����޷��޸�thisָ��ָ����κ�����
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