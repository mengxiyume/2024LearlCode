#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//�����붨�嶼��������
class ClassDeclaraiAdDefinie_1 {
public:
	void func() {
		value = 10;
	}
private:
	int value;
};

//�����붨����롪���岿��
#include "./testClassDeclaraiAdDefinie.h"
//����ֵ���� ������::������() {��}
void ClassDeclaraiAdDefinie_2::func() {
	value = 20;
}

int main_testClassDeclaraiAdDefinie() {

	cout << "Hello Class!!!" << endl;
	return 0;
}