#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

template<typename T>
void Swap(T& x, T& y) {
	//...
}

template<typename T>
T Add(T x, T y) {
	return x + y;
}

int main_templateFunction() {
	cout << Add((int)3, (int)5) << endl;
	cout << Add((float)3, (float)5) << endl;

	cout << Add<char>(4, 9) << endl;

	cout << "Hello! template-fucntion!" << endl;
	return 0;
}