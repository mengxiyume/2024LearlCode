#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//���캯���﷨
class CL1 {
public: 
	CL1() {
		//��ʼ����
	}
};

//���������﷨
class CL2 {
public:
	~CL2() {
		//����
	}
};

//���������﷨
class CL3 {
public:
	CL3(const CL3& src) {
		//��src��thisָ�뿽����
	}
};

//��ֵ���������
class CL4 {
public:
	CL4& operator=(const CL4& src) {
		//ȷ�����Ҳ�����Ϊͬһ��ֵʱ��ʼ��ֵ
		if (this != &src) {
			//��ֵ������
		}
		//�����������
		return *this;
	}
};

//���������������
class CL5 {
public:
	//ǰ��++;
	CL5& operator++() {
		//��ֵ����
		this->m_iValue++;
		//������ֵ
		return *this;
	}
	//����++;
	CL5& operator++(int) {
		//�õ���ֵ
		CL5 temp(*this);
		//����
		this->m_iValue++;
		//���ؾ�ֵ
		return temp;
	}
private:
	int m_iValue = 0;
};

//����ȡ��ַ��const����ȡ��ַ
class CL6 {
public:
	//����ȡ��ַ
	CL6* operator&() {
		return this;
	}
	//const����ȡ��ַ
	const CL6* operator&()const {
		return this;
	}
};

int main_defaultMemberFunction() {


	cout << "Hello! Default member function!!!" << endl;
	return 0;
}