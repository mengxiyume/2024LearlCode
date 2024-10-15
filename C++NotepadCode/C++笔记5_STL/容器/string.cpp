#define _CRT_SECURE_NO_WARNINGS

#include "./string.h"
#include <cstring>
namespace emansis {
#pragma region 构造相关
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
#pragma region 迭代器相关
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
}

#include <iostream>
int main_container_string() {
	emansis::string str = "Hello world!!!";

	for (auto e : str) {
		std::cout << e << ' ';
	}
	std::cout << std::endl;

	//std::cout << str.c_str() << std::endl;
	//for (int i = 0; i < str.size(); i++) {
	//	str[i] = '#';
	//}
	//std::cout << str.c_str() << std::endl;

	return 0;
}