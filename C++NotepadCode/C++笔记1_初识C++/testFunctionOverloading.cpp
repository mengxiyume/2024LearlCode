#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//������������ͬ�������б�ͬ�ĺ�����������
int Add(int a, int b) {
	return a + b;
}
float Add(float a, float b) {
	return a + b;
}
int main_functionOverloading() {
	cout << Add(1, 2) << endl;
	cout << Add(1.0f, 2.5f) << endl;

	return 0;
}