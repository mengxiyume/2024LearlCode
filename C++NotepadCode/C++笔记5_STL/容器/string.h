#pragma once
#include <cstddef>
#include <iostream>
namespace emansis {
	size_t npos = -1;
	class string {
	public:
#pragma region �������
		string(const char* src = "");
		string(const string& src);
		~string();
#pragma endregion
#pragma region ���������
		typedef char* iterator;
		iterator begin();
		iterator end();
#pragma endregion
#pragma region ����������
		char& operator[](size_t index);
		bool operator>(const string right) const;
		bool operator>=(const string right) const;
		bool operator<(const string right) const;
		bool operator<=(const string right) const;
		bool operator==(const string right) const;
		bool operator!=(const string right) const;
		string& operator+=(char ch);
		string& operator+=(string str);
		string& operator=(const string& src);
#pragma endregion
		//���Ŀռ��С
		void reserve(size_t newCapacity);
		void push_back(char ch);
		void append(const string& src);
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* src);
		void erase(size_t pos, size_t len = npos);
		void swap(string& str);
		void clear();
		size_t size() const;
		size_t find(char ch, size_t pos);
		size_t find(const char* str, size_t pos);
		string substr(size_t pos, size_t len = npos);
		const char* c_str() const;
	private:
		char* m_pData = nullptr;
		size_t m_uCapacity;
		size_t m_uSize;
	};
	std::istream& operator>>(std::istream& is, string& str);
	std::ostream& operator<<(std::ostream& is, const string& str);
}