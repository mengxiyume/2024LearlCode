#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//ʹ����Ԫ���� operator<< ����
class CL1 {
	//�����ڲ���������������ԭ��û�й�ϵ����
	friend ostream& operator<<(ostream& dest, const CL1& src);
private:
	int m_iValue = 10;
};
//�����ⶨ�壬ʵ�ֹ���
ostream& operator<<(ostream& dest, const CL1& src) {
	dest << src.m_iValue;
	return dest;
}	//operator>>����ͬ��

//��Ԫ��
class CL2 {
	//��CL2������CL3Ϊ����Ԫ��
	//CL3����ֱ�ӷ���CL2������Ԫ��
	//��CL2���ܷ���CL3��Ԫ��
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
	//���Գɹ�����
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