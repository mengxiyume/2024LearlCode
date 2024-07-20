#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//引用
//引用的语法 
//	引用是一种变量的别名，声明方法为在变量类型的后面加上&
//	引用变量的使用与指针类似，但使用时不需要解引用操作符，且引用变量与原变量相比，不会产生权限的变化
//	int x = 10;
//	int& a = x;
//	指针没有指定const之前指向的内容不能更换，引用则永远不能更换，这是引用的指向性，也就是引用是绑定某一个变量的意思
//	引用做参数效果与指针做参数效果差不多

//模拟传入极大参数的情形，引用显然比指针的方式更加简洁方便
int Add(int* a, int* b) {
	return *a + *b;
}
int add(int& a, int& b) {
	return a + b;
}
//两个函数的作用相同，调用时引用也相比指针的方式更加简介

//引用基础用法
void Test01() {
	//引用及指针的权限可以平移与缩小，但是不能放大

	int x = 10;
	int y = 15;
	//声明引用
	int& a = x;
	//声明指针
	int* pA = &a;

	//都指向a
	cout << a << " " << *pA << endl;

	//改变a相当于改变x
	a = 12;
	cout << a << " " << *pA << endl;
	
	//指针指向的对象可以更改，引用不知道怎么更改指向的对象
	pA = &y;
	cout << a << " " << *pA << endl;

	//权限的收缩
	const int& b = a;
	const int* pB = &b;
	//int* pC = pB;		//权限只能平移或收缩，不能够放大
	//int& c = b;

	//引用进行sizeof操作时得出的结果为被引用的数据的大小
	cout << sizeof(a) <<endl;
	//多次引用嵌套依旧能直接得到最原始的初始化值
	int ad = 0;
	int& r1 = ad;
	int& r2 = r1;
	int& r3 = r2;
	cout << ad << "\n" << &ad << "\n" << &r1 << "\n" << &r2 << "\n" << &r3 << endl;
}

void Test02() {
	double d = 1.12;
	//int& i = d;		//涉及类型转换时会有临时变量，而临时变量具有常属性
	//					//i所指向的数据为临时变量而非d，所以会报错
	const int& i = d;

	//表达式中的临时变量
	int a = 1, b = 2;
	(a + b);		//结果存放在一个临时变量中
	//int& sum = (a + b);		//临时变量具有常属性，此处存在权限放大
	const int& sum = (a + b);	//现在sum就是一个既不能被更改又可以使用的表达式结果的引用了


	//指针在语法上需要开辟内存空间
	//引用在语法上不需要开辟内存空间，但底层汇编与指针相同，都又占用空间
	//正常情况下讨论的都是语法层面
	//引用必须初始化而指针不必要
	//int* pInt = nullptr;
	//int& r = *pInt;		//该处的引用初始化时 pInt并未解引用，在使用时才会进行解引用操作
	//cout << r << endl;	//在使用时发生解引用操作时程序崩溃
}
int main() {

	Test01();
	Test02();

	cout << "Hello & !" << endl;
	return 0;
}