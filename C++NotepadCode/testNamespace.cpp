#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//����һ�������ռ䣬namespace �����ռ��� {��Ա��}
namespace emansis {
	//�����ռ��пɶ���	����|����|����
	int iUserID = 10086;
	string tUserName;

	int Add(int _1, int _2) {
		return _1 + _2;
	}

	typedef struct rect {
		float left;
		float right;
		float top;
		float bottom;
	}rect;
}
//�����ռ��Ƕ�׶���
namespace emansis {
	namespace worllin {
		//...
	}
	//...
}
//���ͬ���������ռ������ͬһ��������ͬʱ���֣��������Ὣ����ͬ�������ռ�ϲ�Ϊһ��

//������ĳ������չ����ֱ��ʹ��
using emansis::tUserName;

//�������ռ�չ���������ռ������г�Ա����ֱ��ʹ��
using namespace emansis;
int main_namespace() {
	tUserName = "�Ε�";
	cout << Add(1, 2) << endl;

	//ʹ���������޶����ӱ�����
	emansis::iUserID = 10;

	//cout << "Hello! CPP!" << endl;
	return 0;
}