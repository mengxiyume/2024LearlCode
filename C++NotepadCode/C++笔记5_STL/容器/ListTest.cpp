#include <iostream>
using namespace std;

#include "./list.h"

template<class T>
void PrintList(emansis::list<T>& ls) {
	if (ls.empty()) {
		cout << "emptyList" << endl;
		return;
	}
	for (const auto& e : ls)
		cout << e << ' ';
	cout << endl;
}

int ListTest01() {
	emansis::list<int> ls1;
	for (int i = 0; i < 5; ++i)
		ls1.push_back(i + 1);
	PrintList<int>(ls1);
	cout << ls1.size() << endl;
	while (!ls1.empty())
		ls1.pop_back();
	PrintList<int>(ls1);

	return 0;
}

//初始化列表测试
int ListTest02() {
	emansis::list<int> ls1 = { 1, 2, 3, 4, 5 };
	PrintList<int>(ls1);
	return 0;
}

//关系运算符测试
int ListTest03() {
	emansis::list<int> ls1 = { 1, 2, 3, 4, 5 };
	emansis::list<int> ls2 = { 1, 2, 3, 4, 6 };
	emansis::list<int> ls3 = { 1, 2, 3, 4, 6 };

	cout << (ls1 >= ls2) << endl;
	cout << (ls1 <= ls2) << endl;
	cout << (ls3 != ls2) << endl;

	return 0;
}

//反向迭代器测试
int ListTest04() {
	emansis::list<int> ls1 = { 1, 2, 3, 4, 5 };
	emansis::list<int>::const_reverse_iterator it = ls1.crbegin();
	while (it != ls1.crend()) {
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	return 0;
}

int main_container_list() {
	//return ListTest01();
	//return ListTest02();
	//return ListTest03();
	return ListTest04();
}