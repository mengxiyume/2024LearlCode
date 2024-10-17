#pragma once

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <cassert>
namespace emansis {

	template<class T>
	class vector {
	public:
#pragma region ��Ա����
#pragma region �����������
		vector()
		: m_aData(nullptr)
		, m_pStart(nullptr)
		, m_pFinish(nullptr)
		, m_pEndOfStorage(nullptr) {;}
		vector(T x) {

		}
		vector(const vector<T>& src) {
			vector<T> temp(src);
			swap(*this, temp);
		}
		~vector() {
			if (m_aData)
				delete[] m_aData;
		}
#pragma endregion
		vector<T>& operator=(vector<T> v) {
			swap(*this, v);
			return *this;
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
			return m_pFinish;
		}
#pragma endregion
#pragma region �ռ����
		size_t size() {
			return m_pFinish - m_pStart;
		}
		size_t capacity() {
			return m_pEndOfStorage - m_pStart;
		}
		bool empty() {
			return !(m_pFinish - m_pStart);
		}
		void resize(size_t size, T value = 0) {
			//TODO:resizeʵ��

		}
		void reserve(size_t newCapacity) {
			//û�пռ�ʱֱ������ռ䲢��ʼ��
			T* temp = new T[newCapacity];
			if (m_aData != nullptr) {
				//���пռ�ʱ�����¿ռ䲢�ƶ����ݺ��ͷžɿռ�
				//�ƶ�����
				memmove(temp, m_aData, size());
				//�ͷžɿռ�
				delete[] m_aData;
			}
			//���������ƶ�
			m_pEndOfStorage	= temp + capacity();
			m_pFinish		= temp + size();
			m_pStart		= temp;
			m_aData			= temp;
		}
#pragma endregion
#pragma region ��Ա����
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
			return *m_pFinish;
		}
		T* data() {
			return m_aData;
		}
		//����const��Ա����
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