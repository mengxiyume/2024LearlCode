#include <iostream>
using namespace std;

#include "./stack.h"

int testStack01() {
	emansis::stack<int> st1;
	for (int i = 0; i < 5; ++i)
		st1.push(i + 1);
	cout << st1.size() << endl;
	emansis::stack<int> st2;
	st1.swap(st2);
	while (!st1.empty()) {
		cout << st1.top() << ' ';
		st1.pop();
	}
	cout << "st1" << endl;
	while (!st2.empty()) {
		cout << st2.top() << ' ';
		st2.pop();
	}
	cout << "st2" << endl;
	
	return 0;
}

int main_container_stack() {
	
	return testStack01();
}