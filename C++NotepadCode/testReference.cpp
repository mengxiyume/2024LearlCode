#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//���õĶ���
//	������& ������ = ��ʼ������;
void testReference01() {
	int i = 0;
	int& ri = i;	//����ri��ʼ����i
	cout << i << ' ' << ri << endl;
}

//�����ã�ӵ�г����ԵĶ��������
void TestConstReference01() {
	const int a = 10;
	//int& ra = a;   // ��������ʱ�����
	//aΪ����	(const int&)
}

//��������
int Add(int& x, int& y) {
	return x + y;
}

//��������ֵ
const int& Count() {
	static int count = 0;
	return ++count;
}

int main_reference() {
	 
	cout << "Hello Reference" << endl;
	return 0;
}