#pragma once

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <cassert>
namespace emansis {

	template<class T>
	class vector {
	public:
#pragma region 成员函数
#pragma region 构造相关重载
		vector()
		: m_aData(nullptr)
		, m_pStart(nullptr)
		, m_pFinish(nullptr)
		, m_pEndOfStorage(nullptr) {;}
		vector(const T& value) {
			vector temp;
			temp += value;
			swap(temp);
		}
		vector(const vector<T>& src) {
			vector<T> temp(src);
			swap(temp);
		}
		~vector() {
			if (m_aData)
				delete[] m_aData;
		}
#pragma endregion
		vector<T>& operator=(vector<T> right) {
			swap(right);
			return *this;
		}
#pragma endregion
#pragma region 迭代器相关
		typedef			T* iterator;
		typedef const	T* const_iterator;
		iterator begin() {
			return m_pStart;
		}
		iterator end() {
			return m_pFinish;
		}
		const_iterator cbegin() const {
			return m_pStart;
		}
		const_iterator cend() const {
			return m_pFinish;
		}
#pragma endregion
#pragma region 空间管理
		size_t size() {
			return m_pFinish - m_pStart;
		}
		size_t capacity() {
			return m_pEndOfStorage - m_pStart;
		}
		bool empty() {
			return !(m_pFinish - m_pStart);
		}
		void resize(size_t newSize, T value = 0) {
			//缩小空间
			if (newSize < size()) {
				m_pFinish -= (size() - newSize);
				return;
			}
			//容器需要扩容
			else if (newSize > capacity()) {
				reserve(newSize);
			}
			//剩余空间使用value填充
			T* cur = m_pFinish;
			while (cur < m_aData + newSize) {
				*cur = value;
				++cur;
			}
			m_pFinish = m_aData + newSize;
		}
		void reserve(size_t newCapacity) {
			//没有空间时直接申请空间并初始化
			T* temp = new T[newCapacity];
			if (m_aData != nullptr) {
				//已有空间时创建新空间并移动数据和释放旧空间
				//移动数据
				memmove(temp, m_aData, size());
				//释放旧空间
				delete[] m_aData;
			}
			//管理数据移动
			m_pEndOfStorage	= temp + newCapacity;
			m_pFinish		= temp + size();
			m_pStart		= temp;
			m_aData			= temp;
		}
#pragma endregion
#pragma region 成员访问
		T& operator[](size_t pos) {
			return at(pos);
		}
		T& at(size_t pos) {
			assert(pos < size());
			return m_aData[pos];
		}
		T& front() {
			return *m_pStart;
		}
		T& back() {
			return *(m_pFinish - 1);
		}
		T* data() {
			return m_aData;
		}
		//访问const成员变量
		const T& operator[](size_t pos) const {
			return at(pos);
		}
		const T& at(size_t pos) const {
			assert(pos < size());
			return m_aData[pos];
		}
		const T& front() const {
			return *m_pStart;
		}
		const T& back() const {
			return *m_pFinish;
		}
		const T* data() const {
			return m_aData;
		}
#pragma endregion
#pragma region 成员改动
		void push_back(const T& value) {
			if (size() + 1 > capacity()) {
				size_t newCapacity = m_aData == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			*m_pFinish = value;
			++m_pFinish;
		}
		void pop_back() {
			assert(!empty());
			--m_pFinish;
		}
		void swap(vector& right) {
			std::swap(m_aData,			right.m_aData);
			std::swap(m_pStart,			right.m_pStart);
			std::swap(m_pFinish,		right.m_pFinish);
			std::swap(m_pEndOfStorage,	right.m_pEndOfStorage);
		}
		void operator+=(const T& value) {
			push_back(value);
		}
		void clear() {
			m_pFinish = m_pStart;
		}
#pragma endregion
	private:
		T* m_aData;			//数据存放的位置
		T* m_pStart;		//有效数据开始的位置
		T* m_pFinish;		//有效数据结束的位置
		T* m_pEndOfStorage;	//申请的空间结束的位置
	};
	template<class T>
	void swap(vector<T>& x, vector<T>& y) {
		x.swap(y);
	}
}