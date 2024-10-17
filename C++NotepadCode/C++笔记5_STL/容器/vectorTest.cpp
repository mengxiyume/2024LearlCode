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

int vectorTest03() {
	emansis::vector<int> v1;
	for (size_t i = 0; i < 5; ++i) {
		v1 += i + 1;
	}
	v1.erase(v1.size() - 1);
	v1.insert(0, 90);
	for (auto e : v1) {
		cout << e << ' ';
	}
	cout << endl;
	return 0;
}

int vectorTest04() {
	emansis::vector<int> v1;
	emansis::vector<int> v2;
	for (size_t i = 0; i < 5; ++i) {
		v1 += i + 1;
		//v2 += i + 1;
	}
	v2 = v1;
	for (auto e : v1) {
		cout << e << ' ';
	}
	cout << endl;
	for (auto e : v2) {
		cout << e << ' ';
	}
	cout << endl;
	//cout << (v1 > v2) << endl;
	//cout << (v1 < v2) << endl;
	//cout << (v1 == v2) << endl;
	return 0;
}

int main_container_vector() {
	//return vectorTest01();
	//return vectorTest02();
	//return vectorTest03();
	return vectorTest04();
}