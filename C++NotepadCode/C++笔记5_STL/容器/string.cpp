#define _CRT_SECURE_NO_WARNINGS

#include "./string.h"

#include <cstring>
#include <cassert>
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

	//更改空间大小
	void string::reserve(size_t newCapacity) {
		if (m_uCapacity == newCapacity)
			return;

		//申请新空间
		char* pNewData = new char[newCapacity + 1];

		//拷贝数据
		strcpy(pNewData, m_pData);

		//释放原空间
		delete[] m_pData;

		//管理数据更新
		m_pData = pNewData;
		m_uCapacity = newCapacity;
	}

	void string::push_back(char ch) {
		//空间检测
		if (m_uSize + 1 >= m_uCapacity) {
			size_t newCapacity = m_uCapacity ? m_uCapacity * 2 : 4;
			reserve(newCapacity);
		}
		//尾插字符
		m_pData[m_uSize] = ch;
		m_pData[m_uSize + 1] = '\0';
		++m_uSize;
	}

	void string::append(const string& src) {
		//空间检测
		size_t len = src.size();
		if (m_uSize + len >= m_uCapacity)
			reserve(m_uSize + len);

		//追加字符串
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