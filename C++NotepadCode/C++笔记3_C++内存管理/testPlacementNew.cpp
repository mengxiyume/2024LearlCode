#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CL {
public:
	CL(int v1 = 10) : m_iValue1(v1) {
		cout << "CL():{����}" << endl;
	}
	~CL() {
		cout << "~CL(){����}" << endl;
	}
private:
	int m_iValue1;
};

int main_placementNew() {

	CL* pcl1 = (CL*)malloc(sizeof(CL));
	//new(δ��ʼ����ָ��)������{��ʼ���б�}
	//
	new	(pcl1)	CL	{ 1 }; 

	cout << "Hello! placement-new!!!" << endl;
	return 0;
}