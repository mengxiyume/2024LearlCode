#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//定义一个命名空间，namespace 命名空间名 {成员…}
namespace emansis {
	//命名空间中可定义	变量|函数|类型
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
//命名空间可嵌套定义
namespace emansis {
	namespace worllin {
		//...
	}
	//...
}
//多个同名的命名空间可以在同一个工程中同时出现，编译器会将所有同名命名空间合并为一个

//单独将某个变量展开后直接使用
using emansis::tUserName;

//将命名空间展开后，命名空间内所有成员都可直接使用
using namespace emansis;
int main_namespace() {
	tUserName = "梦晞";
	cout << Add(1, 2) << endl;

	//使用作用域限定符加变量名
	emansis::iUserID = 10;

	//cout << "Hello! CPP!" << endl;
	return 0;
}