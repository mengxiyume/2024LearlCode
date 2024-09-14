#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
	int m_iValue1 = 15;
	char m_aArr1[10] = "25";
	void testClassScope01();
};
void CL::testClassScope01() {
	//бн
}

int main_classScope() {

	
	cout << "Hello! Scope!!" << endl;
	return 0;
}