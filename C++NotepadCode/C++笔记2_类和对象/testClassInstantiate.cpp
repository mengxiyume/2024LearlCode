#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//��
class CL {
	//��
};
int main_classInstantiate() {
	//��ջ�ռ�ʵ����
	CL cl1;
	//�ڶѿռ�ʵ����
	CL* cl2 = new CL();

	cout << "Hello! Instantiate!!!" << endl;
	return 0;
}