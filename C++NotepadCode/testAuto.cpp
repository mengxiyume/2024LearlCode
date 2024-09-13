#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

void testAuto01() {
	int i = 10; float f = 3.5;
	auto sum = i + 3.5;
	cout << sum << endl;
}

int main_auto() {

	testAuto01();

	//cout << "Hello! auto!" << endl;
	return 0;
}