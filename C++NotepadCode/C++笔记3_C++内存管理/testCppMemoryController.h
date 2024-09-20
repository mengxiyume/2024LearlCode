#pragma once

#include <iostream>
using namespace std;

class CL {
public:
	CL(int v1 = 10, int v2 = 20) 
	: m_iValue1(v1), m_iValue2(v2) {
		cout << "CL():{构造}" << endl;
	}
	~CL() {
		cout << "~CL(){析构}" << endl;
	}
private:
	int m_iValue1;
	int m_iValue2;
};

//关键字new与delete最好成对使用
int main_cppMemoryController() {
	//一般用法
	//int* aArr1 = (int*)malloc(sizeof(int)*10);…
	int* aArr1 = new int[10]{ 1,2,3 };
	//接收变量	空间申请		初始化列表
	//free(aArr1);
	delete[] aArr1;

	//实例化对象
	CL* aArrCL1 = new CL[10]{ 1,2,{3,4} };
	delete[] aArrCL1;	//编译器会调用对应参数数量的构造

	cout << "Hello! CPP Memory-Controller!!!" << endl;
	return 0;
}