#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//static��Ա
class CL {
private:
	static int s_iCount;
public:
	CL() { s_iCount++; }
	CL(const int&) { s_iCount++; }
	~CL() { s_iCount--; }
	//���㵱ǰ���ڶ��ٸ�CL��
	int getCount() { return s_iCount; }
	//����ֵΪ�ɵ�count
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