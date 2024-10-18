#define _CRT_SECURE_NO_WARNINGS

#include "./vector.h"
#include <iostream>
using namespace std;

//int vectorTest01() {
//	emansis::vector<int> v1;
//	v1.resize(5, 3);
//	for (auto e : v1) {
//		cout << e << ' ';
//	}
//	cout << endl;
//	return 0;
//}
//
//int vectorTest02() {
//	emansis::vector<int> v1(6);
//	v1 += 9;
//	for (auto e : v1) {
//		cout << e << ' ';
//	}
//	cout << endl;
//	cout << v1.front() << ' ' << v1.back() << endl;
//	v1.clear();
//	v1 += 32;
//	for (auto e : v1) {
//		cout << e << ' ';
//	}
//	cout << endl;
//	return 0;
//}
//
//int vectorTest03() {
//	emansis::vector<int> v1;
//	for (size_t i = 0; i < 5; ++i) {
//		v1 += i + 1;
//	}
//	v1.erase(v1.size() - 1);
//	v1.insert(0, 90);
//	for (auto e : v1) {
//		cout << e << ' ';
//	}
//	cout << endl;
//	return 0;
//}
//
//int vectorTest04() {
//	emansis::vector<int> v1;
//	for (size_t i = 0; i < 5; ++i) {
//		v1 += i + 1;
//	}
//	for (auto e : v1) {
//		cout << e << ' ';
//	}
//	cout << endl;
//	return 0;
//}
//
//int main_container_vector() {
//	//return vectorTest01();
//	//return vectorTest02();
//	//return vectorTest03();
//	//return vectorTest04();
//	return 0;
//}

int vectorTest01() {

	emansis::vector<int> v1;
	for (int i = 0; i < 5; ++i) {
		v1 += i + 1;
	}
	for (int i = 0; i < 5; ++i) {
		cout << v1[i] << ' ';
	}
	return 0;
}

int vectorTest02() { 
	emansis::vector<int> v1, v2;
	for (int i = 0; i < 5; ++i) {
		v1 += i + 1;
		v2 += (i + 1) * -1;
	}
	for (int i = 0; i < 5; ++i) {
		cout << v1[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		cout << v2[i] << ' ';
	}
	cout << endl;
	v1.swap(v2);
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		cout << v1[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		cout << v2[i] << ' ';
	}
	cout << endl;

	return 0;
}

int vectorTest03() {
	emansis::vector<int> v1;
	v1.resize(5, 999);
	for (size_t i = 0; i < v1.size(); ++i) {
		cout << v1[i] << ' ';
	}
	cout << "resize()" << endl;
	v1.insert(v1.size(), 333);
	v1.insert(v1.size() - 2, 333);
	v1.insert((size_t)0, 333);
	for (size_t i = 0; i < v1.size(); ++i) {
		cout << v1[i] << ' ';
	}
	cout << "insert()" << endl;
	v1.erase((size_t)0);
	v1.erase(v1.size() - 3);
	v1.erase(v1.size() - 1);
	for (size_t i = 0; i < v1.size(); ++i) {
		cout << v1[i] << ' ';
	}
	cout << "erase()" << endl;
	v1.pop_back();
	for (size_t i = 0; i < v1.size(); ++i) {
		cout << v1[i] << ' ';
	}
	cout << "pop_back()" << endl;
	v1.clear();
	for (size_t i = 0; i < v1.size(); ++i) {
		cout << v1[i] << ' ';
	}
	cout << "clear()" << endl;

	return 0;
}

int vectorTest04() {
	emansis::vector<int> v1(93);
	v1.resize(5, 999);
	for (size_t i = 0; i < v1.size(); ++i) {
		cout << v1[i] << ' ';
	}
	cout << "resize()" << endl;
	emansis::vector<int> v2(v1);
	for (size_t i = 0; i < v1.size(); ++i) {
		cout << v2[i] << ' ';
	}
	cout << "拷贝构造()" << endl;

	return 0;
}

int vectorTest05() {
	emansis::vector<int> v1;
	for (size_t i = 0; i < 5; ++i)
		//v1 += i + 1;
		v1.insert(v1.begin(), i + 1);
	for (size_t i = 0; i < 5; ++i)
		cout << v1[i] << ' ';
	cout << "iterator insert()" << endl;
	for (size_t i = 0; i < 5; ++i)
		v1.erase(v1.begin());
	for (size_t i = 0; i < v1.size(); ++i)
		cout << v1[i] << ' ';
	cout << "iterator erase()" << endl;

	return 0;
}

//迭代器失效相关测试
int vectorTest06() {
	emansis::vector<int> v1;
	auto v1It = v1.begin();
	for (int i = 0; i < 5; ++i)
		//防止迭代器失效，使用insert返回值更新现有迭代器
		v1It = v1.insert(v1It, i + 1);
	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << ' ';
	cout << "iterator insert()" << endl;
	v1It = find(v1.begin(), v1.end(), 5);
	for (int i = 0; i < 5; ++i)
		//防止迭代器失效，使用erase返回值-1更新现有迭代器
		v1It = v1.erase(v1It) - 1;
	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << ' ';
	cout << "iterator erase()" << endl;

	return 0;
}


int main_container_vector() {
	//return vectorTest01();
	//return vectorTest02();
	//return vectorTest03();
	//return vectorTest04();
	//return vectorTest05();
	return vectorTest06();
}