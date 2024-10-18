#pragma once

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <cassert>
namespace emansis {

	template<class T>
	class vector {
#pragma region �������
	public:
		vector() = default;
		vector(const T& value) {
			vector<T> temp;
			temp += value;
			swap(temp);
		}
		vector(const vector<T>& src) {
			reserve(src.capacity());
			for (auto e : src) {
				*this += e;
			}
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
#pragma region ���������
		typedef			T* iterator;
		typedef const	T* const_iterator;
		iterator begin() {
			return m_pStart;
		}
		iterator end() {
			return m_pFinish;
		}
		const_iterator begin() const {
			return m_pStart;
		}
		const_iterator end() const {
			return m_pFinish;
		}
		const_iterator cbegin() const {
			return m_pStart;
		}
		const_iterator cend() const {
			return m_pFinish;
		}
#pragma endregion
#pragma region �ռ������
	public:
		size_t size() const {
			return m_pFinish - m_pStart;
		}
		size_t capacity() const {
			return m_pEndOfStorage - m_pStart;
		}
		bool empty() const {
			return !(m_pFinish - m_pStart);
		}
		void resize(size_t newSize, T value = 0) {
			//��С�ռ�
			if (newSize < size()) {
				m_pFinish -= (size() - newSize);
				return;
			}
			//������Ҫ����
			else if (newSize > capacity()) {
				reserve(newSize);
			}
			//ʣ��ռ�ʹ��value���
			T* cur = m_pFinish;
			while (cur < m_aData + newSize) {
				*cur = value;
				++cur;
			}
			m_pFinish = m_aData + newSize;
		}
		void reserve(size_t newCapacity) {
			//û�пռ�ʱֱ������ռ䲢��ʼ��
			T* temp = new T[newCapacity];
			if (m_aData != nullptr) {
				//���пռ�ʱ�����¿ռ䲢�ƶ����ݺ��ͷžɿռ�
				//�ƶ�����
				memmove(temp, m_aData, size() * sizeof(T));
				//�ͷžɿռ�
				delete[] m_aData;
			}
			//���������ƶ�
			m_pEndOfStorage = temp + newCapacity;
			m_pFinish = temp + size();
			m_pStart = temp;
			m_aData = temp;
		}
#pragma endregion
#pragma region ��Ա�������
	public:
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
#pragma region ��Ա�Ķ����
	public:
		void push_back(const T& value) {
			//�������
			if (size() + 1 > capacity()) {
				size_t newCapacity = m_aData == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			//β��
			*m_pFinish = value;
			//βԪ��ָ���ƶ�
			++m_pFinish;
		}
		void pop_back() {
			assert(!empty());
			//βԪ��ָ���ƶ�
			--m_pFinish;
		}
		void operator+=(const T& value) {
			push_back(value);
		}
		void swap(vector& right) {
			std::swap(m_aData, right.m_aData);
			std::swap(m_pStart, right.m_pStart);
			std::swap(m_pFinish, right.m_pFinish);
			std::swap(m_pEndOfStorage, right.m_pEndOfStorage);
		}
		void insert(size_t position, const T& value) {
			assert(position <= size());
			//�������
			if (size() + 1 >= capacity()) {
				size_t newCapacity = m_aData == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			//�����ƶ�
			for (size_t i = size(); i > position; --i) {
				m_aData[i] = m_aData[i - 1];
			}
			//����д��
			m_aData[position] = value;

			//βԪ��ָ���ƶ�
			++m_pFinish;
		}
		iterator insert(iterator position, const T& value) {
			//TODO:�������汾insert
			assert(position >= m_pStart && position <= m_pFinish);

			//iterator oldStart = m_pStart;
			////�������
			//if (size() + 1 >= capacity()) {
			//	size_t newCapacity = m_aData == nullptr ? 4 : capacity() * 2;
			//	reserve(newCapacity);	//������ָ�����
			//	position = m_pStart + (position - oldStart);
			//}
			////�����ƶ�
			//iterator curIt = m_pFinish;
			//while (curIt > position) {
			//	*curIt = *(curIt - 1);
			//	--curIt;
			//}
			////����Ԫ��
			//*position = value;
			////βָ�����
			//++m_pFinish;
			//return position + 1;

			size_t uOffsetPosition = position - begin();
			insert(uOffsetPosition, value);
			return begin() + uOffsetPosition + 1;
		}
		void erase(size_t position) {
			assert(position < size());
			assert(!empty());
			//�����ƶ�
			for (size_t i = position; i < size() - 1; ++i) {
				m_aData[i] = m_aData[i + 1];
			}
			//βԪ��ָ���ƶ�
			--m_pFinish;
		}
		iterator erase(iterator position) {
			//TODO:�������汾insert
			assert(position >= m_pStart && position < m_pFinish);

			//while (position < m_pFinish)
			//	*position = *++position;
			//--m_pFinish;
			//if (position > m_pFinish)
			//	--position;
			//return position;

			size_t uOffsetPosition = position - begin();
			erase(uOffsetPosition);
			return begin() + uOffsetPosition;
		}
		void clear() {
			m_pFinish = m_pStart;
		}
#pragma endregion
#pragma region ��ϵ����������
	public:
		bool operator>(const vector<T>right) const {
			int ret = compare(right);
			return ret > 0;
		}
		bool operator>=(const vector<T>right) const {
			int ret = compare(right);
			return ret >= 0;
		}
		bool operator<(const vector<T>right) const {
			int ret = compare(right);
			return ret < 0;
		}
		bool operator<=(const vector<T>right) const {
			int ret = compare(right);
			return ret <= 0;
		}
		bool operator==(const vector<T>right) const {
			int ret = compare(right);
			return ret == 0;
		}
		bool operator!=(const vector<T>right) const {
			int ret = compare(right);
			return ret != 0;
		}
	private:
		int compare(const vector<T>& right) const {
			int ret = (int)size() - (int)right.size();
			//��������������������ȣ�����һ�Ƚ����е����ݣ�������������Ķ����
			if (false == ret) {
				//todo:��������ȣ���һ�Ƚ����е�����
				iterator leftit = begin(), rightit = right.begin();
				while (leftit < end()) {
					ret = *leftit - *rightit;
					if (false == ret)
						return ret;
					++leftit, ++rightit;
				}
			}
			return ret;
		}
#pragma endregion
	private:
		T* m_aData;			//���ݴ�ŵ�λ��
		T* m_pStart;		//��Ч���ݿ�ʼ��λ��
		T* m_pFinish;		//��Ч���ݽ�����λ��
		T* m_pEndOfStorage;	//����Ŀռ������λ��
	};
}