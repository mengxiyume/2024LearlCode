#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
	int m_iValue1;
	void m_fnSetValue1(int n) {
		this->m_iValue1 = n;
	}
};

int main_classThisPointer() {


	cout << "Hello! thisPointer!!!" << endl;
	return 0;
}