#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//������ӵ��ȱʡ�����ĺ���ʱ�����û���������
//�����Զ�ʹ��ȱʡ����
void funcDefParamTest01(int n = 10) {
	cout << n << endl;
}

//ȫȱʡ���������Ĳ����б�ȫ��Ϊȱʡ
//ֻ����һ���ֲ���ʱʣ��Ĳ�����ȱʡ�����
void funcDefParamTest02(int n1 = 10, int n2 = 15) {
	cout << n1 << ' ' << n2 << endl;
}
//��ȱʡ���������Ĳ����б�ֻ�в���Ϊȱʡ����
//����ֻ�ܴ��������������룬ʣ�ಿ��Ϊȱʡʱ�ɲ�����
void funcDefParamTest03(int n1, int n2 = 15) {
	cout << n1 << ' ' << n2 << endl;
}

int main_defaultParameters() {

	return 0;
}