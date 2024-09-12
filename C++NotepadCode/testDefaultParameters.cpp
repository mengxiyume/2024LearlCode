#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//当调用拥有缺省参数的函数时，如果没有填入参数
//则函数自动使用缺省参数
void funcDefParamTest01(int n = 10) {
	cout << n << endl;
}

//全缺省——函数的参数列表全部为缺省
//只填入一部分参数时剩余的参数由缺省参数填补
void funcDefParamTest02(int n1 = 10, int n2 = 15) {
	cout << n1 << ' ' << n2 << endl;
}
//半缺省——函数的参数列表只有部分为缺省参数
//参数只能从左向右依次填入，剩余部分为缺省时可不填入
void funcDefParamTest03(int n1, int n2 = 15) {
	cout << n1 << ' ' << n2 << endl;
}

int main_defaultParameters() {

	return 0;
}