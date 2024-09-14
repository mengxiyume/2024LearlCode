#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class cl1 {
	long long l1;
	int i1;
	double lf1;
	char c1;
};
class cl2 {
	long long l1;
	double lf1;
	int i1;
	char c1;
};
class clNull {
};
class clFunc {
	void testFunc1() {
		//бн
	}
};

int main_classSizeof() {
	cout << "cl1: " << sizeof(cl1) << endl;
	cout << "cl2: " << sizeof(cl2) << endl;
	cout << "clNULL: " << sizeof(clNull) << endl;
	cout << "clFunc: " << sizeof(clFunc) << endl;

	//cout << "Hello! Class!!!" << endl;
	return 0;
}