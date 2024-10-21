#pragma once

#include <iostream>
using namespace std;
#include "./queue.h"

int queueTest01() {
	emansis::queue<int> qu1, qu2;
	for (int i = 0; i < 5; ++i)
		qu1.push(i + 1);
	cout
		<< qu1.size()	<< ' '
		<< qu1.front()	<< ' '
		<< qu1.back()	<< endl;
	qu1.swap(qu2);
	while (!qu1.empty()) {
		cout << qu1.front() << ' ';
		qu1.pop();
	}
	cout << "qu1" << endl;
	while (!qu2.empty()) {
		cout << qu2.front() << ' ';
		qu2.pop();
	}
	cout << "qu2" << endl;

	return 0;
}

int main_container_queue() {

	return queueTest01();
}