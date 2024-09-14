#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

void testRangFor01() {
	int arr[] = { 1, 2, 3, 4 };
	for (auto n : arr) {
		cout << n << ' ';
	}
	cout << endl;
}

int main_rangeFor() {

	cout << "Hello!RangFor!" << endl;
	return 0;
}