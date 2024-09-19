#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//static成员
class CL {
private:
	static int s_iCount;
public:
	CL() { s_iCount++; }
	CL(const int&) { s_iCount++; }
	~CL() { s_iCount--; }
	//计算当前存在多少个CL类
	int getCount() { return s_iCount; }
	//返回值为旧的count
	//static int setCount(int x) {
	//	int temp = getCount();
	//	s_iCount = x;
	//	return temp;
	//}
};

int main_staticMember() {


	cout << "Hello! static-member!!!" << endl;
	return 0;
}