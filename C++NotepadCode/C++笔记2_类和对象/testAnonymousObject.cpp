#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
public:
	CL(int value = 10) : m_iValue(value) {
		cout << "CL(int):\t����" << endl;
	}
	~CL() { 
		cout << "~CL()\t����" << endl;
	}
	//��ȡ�洢��ֵ
	int m_fnGetValue() {
		return this->m_iValue;
	}
private:
	int m_iValue;
};

int main_anonymousObject() {
	CL cl1();	//���ܹ������������
	//��Ϊ���������ܹ��ֱ����Ǻ����������Ƕ�����
	//��������
	CL();	//���ù���һ��
	cout << endl;
	CL(15);	//��������
	cout << endl; 
	cout << CL(13).m_fnGetValue() << endl;
	//ͨ��ʹ����������ʱ����Ҫʹ�����������еĺ���

	cout << "Hello! Anonymous-Object!!!" << endl;
	return 0;
}