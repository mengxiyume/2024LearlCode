#define _CRT_SECURE_NO_WARNINGS

#include "./string.h"

#include <cstring>
#include <cassert>
#include <algorithm>
namespace emansis {
#pragma region 构造相关
	string::string(const char* src)
		: m_uSize(strlen(src)) {
		m_uCapacity = m_uSize;
		m_szData = new char[m_uSize + 1];
		strcpy(m_szData, src);
	}
	//传统写法
	//string::string(const string& src) 
	//: m_uSize(src.m_uSize)
	//, m_uCapacity(src.m_uCapacity){
	//	m_pData = new char[m_uCapacity + 1];
	//	strcpy(m_pData, src.c_str());
	//}
	//现代写法
	string::string(const string& src) {
		string temp(src.c_str());
		swap(temp);
	}
	string::~string() {
		delete m_szData;
		m_szData = nullptr;
		m_uCapacity = 0;
		m_uSize = 0;
	}
#pragma endregion
#pragma region 迭代器相关
	string::iterator string::begin() {
		return m_szData;
	}
	string::iterator string::end() {
		return m_szData + m_uSize + 1;
	}
#pragma endregion
#pragma region 操作符重载
	char& string::operator[](size_t index) {
		return m_szData[index];
	}
	string& string::operator+=(char ch) {
		push_back(ch);
		return *this;
	}
	string& string::operator+=(string str) {
		append(str);
		return *this;
	}
	//传统方式
	//string& string::operator=(const string& src) {
	//	if (&src == this)
	//		return *this;
	//	if (src.size() > m_uCapacity)
	//		reserve(src.size());
	//	m_uSize = src.m_uSize;
	//	strcpy(m_pData, src.c_str());
	//	return *this;
	//}
	//现代方式
	string& string::operator=(string str) {
		swap(str);
		return *this;
	}
	bool string::operator>(const string right) const {
		return strcmp(c_str(), right.c_str()) > 0;
	}
	bool string::operator>=(const string right) const {
		return strcmp(c_str(), right.c_str()) >= 0;
	}
	bool string::operator<(const string right) const {
		return strcmp(c_str(), right.c_str()) < 0;
	}
	bool string::operator<=(const string right) const {
		return strcmp(c_str(), right.c_str()) <= 0;
	}
	bool string::operator==(const string right) const {
		return strcmp(c_str(), right.c_str()) == 0;
	}
	bool string::operator!=(const string right) const {
		return strcmp(c_str(), right.c_str()) != 0;
	}
#pragma endregion
	void string::reserve(size_t newCapacity) {
		if (m_uCapacity == newCapacity)
			return;

		//申请新空间
		char* pNewData = new char[newCapacity + 1];

		//拷贝数据
		memmove(pNewData, m_szData, newCapacity);
		pNewData[newCapacity] = '\0';

		//释放原空间
		delete[] m_szData;

		//管理数据更新
		m_szData = pNewData;
		m_uCapacity = newCapacity;
	}
	void string::push_back(char ch) {
		//空间检测
		if (m_uSize + 1 >= m_uCapacity) {
			size_t newCapacity = m_uCapacity ? m_uCapacity * 2 : 4;
			reserve(newCapacity);
		}
		//尾插字符
		m_szData[m_uSize] = ch;
		m_szData[m_uSize + 1] = '\0';
		++m_uSize;
	}
	void string::append(const string& src) {
		//空间检测
		size_t len = src.size();
		if (m_uSize + len >= m_uCapacity)
			reserve(m_uSize + len);

		//追加字符串
		strcpy(m_szData + m_uSize, src.c_str());
		m_uSize += len;
	}
	void string::insert(size_t pos, char ch) {
		//在pos位置插入一个字符ch

		//空间检测
		if (m_uSize + 1 >= m_uCapacity) {
			size_t newCapacity = m_uCapacity ? m_uCapacity * 2 : 4;
			reserve(newCapacity);
		}
		//将pos之后的字符向后移动一位
		size_t end = m_uSize + 1;
		while (end > pos) {
			m_szData[end] = m_szData[end - 1];
			--end;
		}
		//插入字符
		m_szData[pos] = ch;
		++m_uSize;
	}
	void string::insert(size_t pos, const char* src) {
		//在pos位置插入一个字符串src
		
		size_t len = strlen(src);
		//空间检测
		if (m_uSize + len >= m_uCapacity) {
			reserve(m_uSize + len);
		}

		//数据移动
		size_t end = m_uSize + len;
		while (end > pos + len - 1) {
			m_szData[end] = m_szData[end - len];
			--end;
		}

		//字符串写入
		memcpy(m_szData + pos, src, len);
		m_uSize += len;
	}
	void string::erase(size_t pos, size_t len) {
		//从pos位置向后删除len个字符

		//越界处理
		assert(pos < m_uSize);

		//超量删除处理
		if (len == npos) {
			m_szData[pos] = '\0';
			m_uSize = pos;
		}
		//一般删除处理
		else {
			strcpy(m_szData + pos, m_szData + pos + len);
			m_uSize -= len;
		}
	}
	void string::swap(string& str) {
		std::swap(str.m_szData, m_szData);
		std::swap(str.m_uSize, m_uSize);
		std::swap(str.m_uCapacity, m_uCapacity);
	}
	void string::clear() {
		m_szData[0] = '\0';
		m_uSize = 0;
	}
	size_t string::size() const {
		return m_uSize;
	}
	size_t string::find(char ch, size_t pos) {
		assert(pos < m_uSize);
		//在范围内查找
		for (size_t i = pos; i < m_uSize; ++i)
			if (m_szData[i] == ch)
				return i;
		//找不到返回-1
		return -1;
	}
	size_t string::find(const char* str, size_t pos) {
		const char* sub = strstr(m_szData + pos, str);
		return sub ? sub - m_szData : -1;	//未查找到时返回-1
	}
	string string::substr(size_t pos, size_t len) {
		if (pos > m_uSize)
			return "";
		if (len > m_uSize - pos) {
			//有多少取多少
			return string(m_szData + pos);
		}
		else {
			//取中间部分
			string sub;
			sub.reserve(len);
			memmove(sub.m_szData, m_szData + pos, len);
			sub.m_uSize = len;
			sub.m_szData[len] = '\0';
			return sub;
		}
	}
	const char* string::c_str() const {
		return m_szData;
	}
	std::istream& operator>>(std::istream& is, string& str) {
		str.clear();
		char cbIndex = 0;
		char buffer[128];
		do {
			if (cbIndex == 127) {
				str[cbIndex] = '\0';
				str += buffer;
				cbIndex = 0;
			}
			buffer[cbIndex] = is.get();		//指针迭代
			++cbIndex;
		} while (buffer[cbIndex - 1] != ' ' && buffer[cbIndex - 1] != '\n');
		buffer[cbIndex] = '\0';
		str += buffer;
		return is;
	}
	std::ostream& operator<<(std::ostream& is, const string& str) {
		std::cout << str.c_str();
		return is;
	}
}

#include <iostream>
int main_container_string() {
	emansis::string str = "Hello world!!!";

	std::cout << str << std::endl;
	std::cin >> str;
	std::cout << str << std::endl;

	//std::cout << str.c_str() << std::endl;
	//std::cout << str.substr(6, 5).c_str() << std::endl;
	//std::cout << str.substr(11).c_str() << std::endl;

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