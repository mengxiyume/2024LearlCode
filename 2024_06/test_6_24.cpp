#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/* ����ȱʡ����
* ��������ʱ������ȱʡ�������ò����ں������ô���ʱ���Բ�����д
* ����ʱδ����Ĳ�������ȱʡ������Ϊ��Ĭ��ֵ
* �������δ����ң�ȱʡ����Ҳ����ˣ�ȱʡ�������ܱ�ֱ������
*/

void testFunc1(int a = 7) {
	cout << a << endl;
}

void testFunc2(int a = 7, int b = 9, int c = 2) {
	cout << a << ' ' << b << ' ' << c << endl;
}

void testFunc3(int a, int b = 9, int c = 2) {
	cout << a << ' ' << b << ' ' << c << endl;
}

int main() {

	cout << "TestFunc1" << endl;
	//��ӡȱʡ����7
	testFunc1();
	//��ӡָ������93
	testFunc1(93);

	cout << "TestFunc2" << endl;
	//ֱ�Ӵ�ӡȱʡ����
	testFunc2();
	//������ָ��������δָ��������ȱʡ�
	testFunc2(1, 2);

	cout << "TestFunc3" << endl;
	//��һ����������ȱʡ�������ܱ��������������������ͻᱨ��
	//testFunc3();
	//�����ȱʡ������ʣ�µĲ������Բ�ָ��ʹ��Ĭ��ֵ
	testFunc3(21);
	testFunc3(22, 32);



	return 0;
}