#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//��ʼ���б�: ��һ��ð�ſ�ʼ��������һ���Զ��ŷָ������ݳ�Ա�б�
//ÿ��"��Ա����"�����һ�����������еĳ�ʼֵ����ʽ
class CL1 {
private:
	int m_iValue1;
	int m_iValue2;
public:
	CL1(int v1, int v2) : m_iValue1(v1), m_iValue2(v2) {};
};

//(explicit)�ؼ���
class CL2 {
private:
	int m_iValue1;
	int m_iValue2;
public:
	explicit CL2(int v1)
		:m_iValue1(v1)
		, m_iValue2(20) {
		//explicit���εĹ���������ʽ����ת��
		//Ҳ����ǿ�Ƶ��ù����ʱ���������� 
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