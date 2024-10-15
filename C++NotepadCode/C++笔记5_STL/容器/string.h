#pragma once
#include <cstddef>
namespace emansis {
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

	private:
		char* m_pData;
		size_t m_uCapacity;
		size_t m_uSize;
	};
}