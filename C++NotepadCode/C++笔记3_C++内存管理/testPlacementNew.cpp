#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
public:
	CL(int v1 = 10) : m_iValue1(v1) {
		cout << "CL():{构造}" << endl;
	}
	~CL() {
		cout << "~CL(){析构}" << endl;
	}
private:
	int m_iValue1;
};

int main_placementNew() {

	CL* pcl1 = (CL*)malloc(sizeof(CL));
	//new(未初始化的指针)类型名{初始化列表}
	//
	new	(pcl1)	CL	{ 1 }; 

	cout << "Hello! placement-new!!!" << endl;
	return 0;
}