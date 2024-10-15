#define _CRT_SECURE_NO_WARNINGS

#include "./string.h"

#include <cstring>
#include <cassert>
namespace emansis {
#pragma region �������
	string::string(const char* src)
		: m_uSize(strlen(src)) {
		m_uCapacity = m_uSize;
		m_pData = new char[m_uSize + 1];
		strcpy(m_pData, src);
	}
	string::~string() {
		delete m_pData;
		m_pData = nullptr;
		m_uCapacity = 0;
		m_uSize = 0;
	}
#pragma endregion
#pragma region ���������
	string::iterator string::begin() {
		return m_pData;
	}
	string::iterator string::end() {
		return m_pData + m_uSize + 1;
	}
#pragma endregion

	const char* string::c_str() const {
		return m_pData;
	}
	size_t string::size() const {
		return m_uSize;
	}
	char& string::operator[](size_t index) {
		return m_pData[index];
	}

	//���Ŀռ��С
	void string::reserve(size_t newCapacity) {
		if (m_uCapacity == newCapacity)
			return;

		//�����¿ռ�
		char* pNewData = new char[newCapacity + 1];

		//��������
		strcpy(pNewData, m_pData);

		//�ͷ�ԭ�ռ�
		delete[] m_pData;

		//�������ݸ���
		m_pData = pNewData;
		m_uCapacity = newCapacity;
	}

	void string::push_back(char ch) {
		//�ռ���
		if (m_uSize + 1 >= m_uCapacity) {
			size_t newCapacity = m_uCapacity ? m_uCapacity * 2 : 4;
			reserve(newCapacity);
		}
		//β���ַ�
		m_pData[m_uSize] = ch;
		m_pData[m_uSize + 1] = '\0';
		++m_uSize;
	}

	void string::append(const string& src) {
		//�ռ���
		size_t len = src.size();
		if (m_uSize + len >= m_uCapacity)
			reserve(m_uSize + len);

		//׷���ַ���
		strcat(m_pData, src.c_str());
	}
}

#include <iostream>
int main_container_string() {
	emansis::string str = "Hello world!!!";

	std::cout << str.c_str() << std::endl;
	str.push_back('(');
	std::cout << str.c_str() << std::endl;
	str.append(emansis::string("TAT"));
	std::cout << str.c_str() << std::endl;

	//for (auto e : str) {
	//	std::cout << e << ' ';
	//}
	//std::cout << std::endl;

	//std::cout << str.c_str() << std::endl;
	//for (int i = 0; i < str.size(); i++) {
	//	str[i] = '#';
	//}
	//std::cout << str.c_str() << std::endl;

	return 0;
}