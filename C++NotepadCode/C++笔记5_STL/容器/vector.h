#pragma once

#include <algorithm>
#include <cstddef>
namespace emansis {

	template<class T>
	class vector {
	public:
#pragma region �����������
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
#pragma region ���������
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
#pragma region �ռ����

#pragma endregion
	private:
		T* m_aData;			//���ݴ�ŵ�λ��
		T* m_pStart;		//��Ч���ݿ�ʼ��λ��
		T* m_pFinish;		//��Ч���ݽ�����λ��
		T* m_pEndOfStorage;	//����Ŀռ������λ��
	};
	template<class T>
	void swap(vector<T>& x, vector<T>& y) {
		std::swap(x.m_aData,			y.m_aData);
		std::swap(x.m_pStart,			y.m_pStart);
		std::swap(x.m_pFinish,			y.m_pFinish);
		std::swap(x.m_pEndOfStorage,	y.m_pEndOfStorage);
	}
}