#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//���������﷨
//inline (���������﷨��)
inline void Swap(int& a, int& b) {
	int x = a;
	a = b;
	b = x;
}

//���ں��ʵ��ʽ��Ԥ����׶ε�ֱ���滻����ʵ�ֵ�
//������Ҫʹ�����Ų��ѵ�ȷ���ȶ�
//�����ں�û�����ͼ�飬��Ȼ��������������ȫ
#define SUM(X, Y) ((X) + (Y))
inline int Sum(int x, int y) {
	return x + y;
}

int main_inline() {

	cout << "Hello! Inline!" << endl;
	return 0;
}