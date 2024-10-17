#define _CRT_SECURE_NO_WARNINGS

#include "./vector.h"
#include <iostream>
using namespace std;

int vectorTest01() {
	emansis::vector<int> v1;
	v1.resize(5, 3);
	for (auto e : v1) {
		cout << e << ' ';
	}
	cout << endl;
	return 0;
}

int vectorTest02() {
	emansis::vector<int> v1(6);
	v1 += 9;
	for (auto e : v1) {
		cout << e << ' ';
	}
	cout << endl;
	cout << v1.front() << ' ' << v1.back() << endl;
	v1.clear();
	v1 += 32;
	for (auto e : v1) {
		cout << e << ' ';
	}
	cout << endl;
	return 0;
}

int main_container_vector() {
	//return vectorTest01();
	return vectorTest02();
}