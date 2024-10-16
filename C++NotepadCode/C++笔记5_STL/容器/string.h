#pragma once
#include <cstddef>
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
		string& operator+=(char ch);
		string& operator+=(string str);
		string& operator=(const string& src);

		bool operator>(const string right) const;
		bool operator>=(const string right) const;
		bool operator<(const string right) const;
		bool operator<=(const string right) const;
		bool operator==(const string right) const;
		bool operator!=(const string right) const;
#pragma endregion

		const char* c_str() const;
		size_t size() const;
		//���Ŀռ��С
		void reserve(size_t newCapacity);
		void push_back(char ch);
		void append(const string& src);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* src);
		void erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos);
		size_t find(const char* str, size_t pos);

		void swap(string& str);
		string substr(size_t pos, size_t len = npos);

	private:
		char* m_pData;
		size_t m_uCapacity;
		size_t m_uSize;
	};
}