#pragma once

#include <iostream>
using namespace std;

class CL {
public:
	CL(int v1 = 10, int v2 = 20) 
	: m_iValue1(v1), m_iValue2(v2) {
		cout << "CL():{����}" << endl;
	}
	~CL() {
		cout << "~CL(){����}" << endl;
	}
private:
	int m_iValue1;
	int m_iValue2;
};

//�ؼ���new��delete��óɶ�ʹ��
int main_cppMemoryController() {
	//һ���÷�
	//int* aArr1 = (int*)malloc(sizeof(int)*10);��
	int* aArr1 = new int[10]{ 1,2,3 };
	//���ձ���	�ռ�����		��ʼ���б�
	//free(aArr1);
	delete[] aArr1;

	//ʵ��������
	CL* aArrCL1 = new CL[10]{ 1,2,{3,4} };
	delete[] aArrCL1;	//����������ö�Ӧ���������Ĺ���

	cout << "Hello! CPP Memory-Controller!!!" << endl;
	return 0;
}