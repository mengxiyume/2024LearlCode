#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
public:
	CL(int value = 10) : m_iValue(value) {
		cout << "testCL(int):\t����" << endl;
	}
	CL(const CL& dest) : m_iValue(dest.m_iValue) {
		cout
	<< "testCL(const testCL&):\t��������" << endl;
	}
	~CL() {
		cout << "~testCL()\t����" << endl;
	}
	CL& operator=(const CL& dest) {
		if (this != &dest) {
			//�ж��Ƿ�ֵ������
			this->m_iValue = dest.m_iValue;
			cout
<< "testCL& operator=(const CL&)\t ��ֵ����" << endl;
		}
		return *this;
	}
private:
	int m_iValue;
};

void Fn1(CL cl) {
	//�����б�������
}
CL Fn2() {
	CL cl;	//����������
	return cl;	//����ֵ��ʱ���󿽱�����
}

int main_objectAndOptmize() {

	//��ֵ����ʱ
	CL cl1;	//����
	Fn1(cl1);	//��������-����
	cout << endl;	//������

	//��ʽ���͹���-��������-����
	Fn1(1);	//������
	cout << endl;

	//����-��������-����-������
	Fn1(CL(30));
	cout << endl;

	//��ֵ����ʱ
	Fn2();	//����-����
	cout << endl;

	//����-��ֵ����-��������-����
	CL cl2 = Fn2();	//������
	cout << endl;

	//��ֵ����-��������-����-����
	cl1 = Fn2();	//������
	cout << endl;


	//cout << "Hello! object and optmize!!!" << endl;
	return 0;
}