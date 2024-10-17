#pragma once

#include <algorithm>
#include <cstddef>
namespace emansis {

	template<class T>
	class vector {
	public:
#pragma region 构造相关重载
		vector(size_t size = 0)
		: m_aData(nullptr)
		, m_pStart(nullptr)
		, m_pFinish(nullptr)
		, m_pEndOfStorage(nullptr) { }
		~vector() {
			if (m_aData)
				delete[] m_aData;
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
			return m_pFinish
		}
#pragma endregion
#pragma region 空间管理

#pragma endregion
	private:
		T* m_aData;			//数据存放的位置
		T* m_pStart;		//有效数据开始的位置
		T* m_pFinish;		//有效数据结束的位置
		T* m_pEndOfStorage;	//申请的空间结束的位置
	};
	template<class T>
	void swap(vector<T>& x, vector<T>& y) {
		std::swap(x.m_aData,			y.m_aData);
		std::swap(x.m_pStart,			y.m_pStart);
		std::swap(x.m_pFinish,			y.m_pFinish);
		std::swap(x.m_pEndOfStorage,	y.m_pEndOfStorage);
	}
}