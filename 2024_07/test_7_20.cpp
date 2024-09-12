#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//����ʽ��
#define _Add(a, b) ((a) + (b))

//inline������ʶ��ֻ�Ƕ��ڱ������Ľ��飬��������ʱ��������һ�����հ�

//��������
//�﷨��ʽ - �ں�������ǰ����inline��ʶ
inline int Add(int a, int b) {
	return a + b;
}
//���﷨ΪC�����к����δ�������д��ʽΪ������չ����ʽ�����ͬ����ӵ�����ͼ�������ȶ�
//��������������Debug���ڽ��������Ż���debugģʽ���������������Ժ�����ʽ���֣�releaseģʽ����ȫչ��

void Test03() {
	//��������ʹ�÷�ʽ������������ͬ
	//�����������������ڵ���ʱ������ջ֡��������Դ���ĸ�С�����ٶȸ��죬�����뺯��ʽ������
	//�����ں���ʽ��֮���������ڲ��õ��Ĳ������ȼ����ң����Դ�����д��ʽ���Ը��Ӽ������
	//	���ҿ���Debug
	int sum = Add(1, 2);
	//���ù�������->C/C++/����/������Ϣ��ʽ - �������ݿ�
	//���ù�������->C/C++/�Ż�/����������չ - ֻ������inline
	//�û���������Debugģʽ��ͨ�������뿴������������Դ�룬��ʱ��Add��û��Callָ���
	//�����ζ��Add��û�����Ľ���ջ֡����Դ
	cout << sum << endl;
}

#include "./InlineTest.h"
//�������������Ͷ������
void Test04() {
	_F(20);
	F(10);	//���������������������ᱨ���Ӵ���
	//���������ڵ���ʱ��ֱ��չ�����⵼��������������Ҫ��ַ��û�е�ַ
	//�������Ҳ������������ĵ�ַ���Ա����޷������ķ���
	//����������������ű�---
	//�����������Ҫ�ĳ�������ֱ����.h�ļ�����д��������
}

//auto���� - �Զ��Ƶ�����
//auto���Զ��Ƶ�������ʽ��������ͣ��ڸ��ӳ����¿��Ծ������룬������ֵֹĵط�ʹ����δ���ӵ�����/������
void Test05() {

	//auto���� - ���Լ��Ͱ��Լ��������������.jpg
	int a = 3;
	char c = 'a';
	auto sum = a + c;
	//ʹ��typeid���鿴sum������
	cout << typeid(sum).name() << endl;

	//autoָ��Ҫ����ֵ������ָ��
	auto* pAuto = &c;
	//autoָ���ڳ�ʼ�����֮�����;͹̶����ɸ�����
	//pAuto = &a;
	
	//autoҲ���������ͣ�ʹ�÷���������ͬautoָ�룬���������õ�����
	auto& rAuto = sum;

	//auto���Ͳ�������ֱ����������,Ҳ���ܹ���Ϊ�������ڵĴ��ݲ���
	//void TestAutoValueFunc(auto a, auto b);	//C++�涨auto�������������Ľ��ղ�������
	//auto autoArr[] = { 1, 2, 3 };	//C++�涨auto����ֱ��������������

	//auto������C������Ҳ���ڹ����ѷ���
	//C�����е��Զ�����	/*auto int a = 0;*/
	//��������ı������Զ����٣����������������ڵľֲ�����һ�����뿪�������Զ�����
}

//��ΧFor
//�﷨��Դ��python���﷨֧��C++11������
//�Զ���ȡ�����е�ֵ��ֵ������e��ѭ���Զ�++���Զ�����ѭ��
void Test06() {
	//�����﷨
	int arry[] = { 1, 2, 3, 4 };
	//e�ı����������Ͳ�Ӱ�췶Χfor�﷨�������Լ�����
	for (auto e : arry) {
		cout << e << endl;
	}
	//���������޷��ı�arry�ڵı����������Ҫ�ı����ʹ��auto����
	int i = 0;
	for (auto& x : arry) {
		x = ++i;
		cout << x << endl;
	}
	//���arryֻ�ܶ�����ʹ�ã����鴫�θ�����֮�����õ�����һ������ĵ�ַ
	//Ҳ�������鲻֧�ִ��Σ���Χfor��arryѡ�֧������ĵ�ַ�����Ե���Ѱ����
}

//void TestFor(int arr[]) {
//	//arrΪ�����ַ����Χfor��֧��ʹ�õ�ַ���뷶Χ��
//	for (int x : arr) {
//		cout << x << ' ';
//	}
//	cout << endl;
//}

//����C++��NULL����Ϊint
//����C���Ե�NULL����Ϊһ��ָ��
// C:	#define NULL ((void*)0)
// C++:	#define NULL 0
//������C++�б�ʾָ��Ĳ���Ӧʹ��nullptr���C�����е�NULL��������ܻ������ֵĴ���

void TestNullType(int i) {
	cout << "int" << endl;
}
void TestNullType(int* i) {
	cout << "(void*)" << endl;
}

void Test07() {
	TestNullType(NULL);	//����ֱ�Ӿ͵����˲���Ϊ���ε�����
	//��ʹ��ָ��Ļ�������NULL�ᵼ����C++�еĴ������
	//����C++��ʹ��nullptr����NULL���ڱ�ʾ��ָ��
	TestNullType(nullptr);
	//nullptrΪC++11����Ĺؼ��֣����Բ���Ҫ������cstddef������ͷ�ļ�����ʹ��
}

//int main() {
//	//Test07();
//	cout << "Hello inline!" << endl;
//	return 0;
//}