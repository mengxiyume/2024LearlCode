#pragma once
#include <cstddef>
namespace emansis {
	size_t npos = -1;

	class string {
	public:
#pragma region 构造相关
		string(const char* src = "");
		~string();
#pragma endregion
#pragma region 迭代器相关
		typedef char* iterator;
		iterator begin();
		iterator end();
#pragma endregion
#pragma region 操作符重载
		char& operator[](size_t index);
		string& operator+=(char ch);
		string& operator+=(string str);
#pragma endregion

		const char* c_str() const;
		size_t size() const;
		void reserve(size_t newCapacity);
		void push_back(char ch);
		void append(const string& src);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* src);
		void erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos);
		size_t find(const char* str, size_t pos);

	private:
		char* m_pData;
		size_t m_uCapacity;
		size_t m_uSize;
	};
}