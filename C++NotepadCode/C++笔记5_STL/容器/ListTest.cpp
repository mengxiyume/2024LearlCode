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

int ListTest02() {

	return 0;
}

int main_container_list() {
	return ListTest01();
	//return ListTest02();
}