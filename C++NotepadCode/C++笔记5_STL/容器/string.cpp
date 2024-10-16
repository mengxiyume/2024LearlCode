#define _CRT_SECURE_NO_WARNINGS

#include "./string.h"

#include <cstring>
#include <cassert>
#include <algorithm>
namespace emansis {
#pragma region �������
	string::string(const char* src)
		: m_uSize(strlen(src)) {
		m_uCapacity = m_uSize;
		m_pData = new char[m_uSize + 1];
		strcpy(m_pData, src);
	}
	string::string(const string& src) 
	: m_uSize(src.m_uSize)
	, m_uCapacity(src.m_uCapacity){
		m_pData = new char[m_uCapacity + 1];
		strcpy(m_pData, src.c_str());
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
#pragma region ����������
	char& string::operator[](size_t index) {
		return m_pData[index];
	}
	string& string::operator+=(char ch) {
		push_back(ch);
		return *this;
	}
	string& string::operator+=(string str) {
		append(str);
		return *this;
	}
	string& string::operator=(const string& src) {
		if (&src == this)
			return *this;
		if (src.size() > m_uCapacity)
			reserve(src.size());
		m_uSize = src.m_uSize;
		strcpy(m_pData, src.c_str());
		return *this;
	}
#pragma endregion

	const char* string::c_str() const {
		return m_pData;
	}
	size_t string::size() const {
		return m_uSize;
	}
	void string::reserve(size_t newCapacity) {
		if (m_uCapacity == newCapacity)
			return;

		//�����¿ռ�
		char* pNewData = new char[newCapacity + 1];

		//��������
		memmove(pNewData, m_pData, newCapacity);
		pNewData[newCapacity] = '\0';

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
		strcpy(m_pData + m_uSize, src.c_str());
		m_uSize += len;
	}
	void string::insert(size_t pos, char ch) {
		//��posλ�ò���һ���ַ�ch

		//�ռ���
		if (m_uSize + 1 >= m_uCapacity) {
			size_t newCapacity = m_uCapacity ? m_uCapacity * 2 : 4;
			reserve(newCapacity);
		}
		//��pos֮����ַ�����ƶ�һλ
		size_t end = m_uSize + 1;
		while (end > pos) {
			m_pData[end] = m_pData[end - 1];
			--end;
		}
		//�����ַ�
		m_pData[pos] = ch;
		++m_uSize;
	}
	void string::insert(size_t pos, const char* src) {
		//��posλ�ò���һ���ַ���src
		
		size_t len = strlen(src);
		//�ռ���
		if (m_uSize + len >= m_uCapacity) {
			reserve(m_uSize + len);
		}

		//�����ƶ�
		size_t end = m_uSize + len;
		while (end > pos + len - 1) {
			m_pData[end] = m_pData[end - len];
			--end;
		}

		//�ַ���д��
		memcpy(m_pData + pos, src, len);
		m_uSize += len;
	}
	void string::erase(size_t pos, size_t len) {
		//��posλ�����ɾ��len���ַ�

		//Խ�紦��
		assert(pos < m_uSize);

		//����ɾ������
		if (len == npos) {
			m_pData[pos] = '\0';
			m_uSize = pos;
		}
		//һ��ɾ������
		else {
			strcpy(m_pData + pos, m_pData + pos + len);
			m_uSize -= len;
		}
	}
	size_t string::find(char ch, size_t pos) {
		assert(pos < m_uSize);
		//�ڷ�Χ�ڲ���
		for (size_t i = pos; i < m_uSize; ++i)
			if (m_pData[i] == ch)
				return i;
		//�Ҳ�������-1
		return -1;
	}
	size_t string::find(const char* str, size_t pos) {
		const char* sub = strstr(m_pData + pos, str);
		return sub ? sub - m_pData : -1;	//δ���ҵ�ʱ����-1
	}
	void string::swap(string& str) {
		std::swap(str.m_pData, m_pData);
		std::swap(str.m_uSize, m_uSize);
		std::swap(str.m_uCapacity, m_uCapacity);
	}
	string string::substr(size_t pos, size_t len) {
		if (pos > m_uSize)
			return "";
		if (len > m_uSize - pos) {
			//�ж���ȡ����
			return string(m_pData + pos);
		}
		else {
			//ȡ�м䲿��
			string sub;
			sub.reserve(len);
			memmove(sub.m_pData, m_pData + pos, len);
			sub.m_uSize = len;
			sub.m_pData[len] = '\0';
			return sub;
		}
	}
}

#include <iostream>
int main_container_string() {
	emansis::string str = "Hello world!!!";

	std::cout << str.c_str() << std::endl;

	std::cout << str.substr(6, 5).c_str() << std::endl;
	std::cout << str.substr(11).c_str() << std::endl;
	

	//std::cout << str.c_str() << str.size() << std::endl;
	//str = emansis::string("wow");
	//std::cout << str.c_str() << str.size() << std::endl;

	//auto str1(str);
	//str1 += "TAT";
	//std::cout << str.c_str() << std::endl;
	//std::cout << str1.c_str() << std::endl;

	//std::cout << str.c_str() << std::endl;
	//std::cout << str.find('!', 0) << ' ' << str.find("Hello", 0) << std::endl;
	//std::cout << str.find("abc", 0) << std::endl;

	//std::cout << str.c_str() << std::endl;
	//str.insert(6, "my ");
	//std::cout << str.c_str() << std::endl;
	//str.erase(6, 3);
	//std::cout << str.c_str() << std::endl;
	//str.erase(5);
	//std::cout << str.c_str() << std::endl;

	//std::cout << str.c_str() << std::endl;
	//str.insert(0, '*');
	//std::cout << str.c_str() << std::endl;

	//std::cout << str.c_str() << std::endl;
	//str += '(';
	//std::cout << str.c_str() << std::endl;
	//str += "TAT";
	//std::cout << str.c_str() << std::endl;

	//std::cout << str.c_str() << std::endl;
	//str.push_back('(');
	//std::cout << str.c_str() << std::endl;
	//str.append(emansis::string("TAT"));
	//std::cout << str.c_str() << std::endl;

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