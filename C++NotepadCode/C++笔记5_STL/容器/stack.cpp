#include <iostream>
using namespace std;

#include "./stack.h"

int testStack01() {
	emansis::stack<int> st1;
	for (int i = 0; i < 5; ++i)
		st1.push(i + 1);
	while (!st1.empty()) {
		cout << st1.top() << ' ';
		st1.pop();
	}
	return 0;
}

int main_container_stack() {
	
	return testStack01();
}