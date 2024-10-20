#pragma once

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <cassert>
#include <initializer_list>
namespace emansis {

	//TODO:���������뷴���������ʵ��
	template<class T>
	/// <summary>
	/// ˳���
	/// </summary>
	class vector {
	#pragma region �������
	public:
		/// <summary>
		/// Ĭ�Ϲ���
		/// </summary>
		vector() = default;
		template<class InputIterator>
		/// <summary>
		/// �����������ʼ��
		/// </summary>
		/// <param name="start">��������ʼ��λ��</param>
		/// <param name="finish">��������������һ��λ��</param>
		explicit vector(InputIterator start, InputIterator finish) {
			vector<T> temp;
			InputIterator curIt = start;
			while (curIt < finish) {
				temp += *curIt;
				++curIt;
			}
			swap(temp);
		}
		/// <summary>
		/// ��ʼ���б���
		/// </summary>
		/// <param name="il">��ʼ���б�</param>
		vector(std::initializer_list<T> il) {
			reserve(il.size());
			for (auto e : il) {
				*this += e;
			}
		}
		/// <summary>
		/// N����ֵ����ʼ��
		/// </summary>
		/// <param name="n">��ʼ��������</param>
		/// <param name="value">��Ҫ�����ֵ</param>
		explicit vector(size_t n, const T& value = T()) {
			vector<T> temp;
			temp.resize(n, value);
			swap(temp);
		}
		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="src">��������˳������</param>
		explicit vector(const vector<T>& src) {
			reserve(src.capacity());
			for (const auto& e : src)
				*this += e;
		}
		/// <summary>
		/// ��������
		/// </summary>
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
		#pragma region ���������
		typedef			T* iterator;		//������
		typedef const	T* const_iterator;	//const������
		/// <summary>
		/// begin������
		/// </summary>
		/// <returns>��һ����ЧԪ��λ�õĵ�����</returns>
		iterator begin() {
			return m_pStart;
		}
		/// <summary>
		/// end������
		/// </summary>
		/// <returns>���һ����ЧԪ�ص���һ��λ�õĵ�����</returns>
		iterator end() {
			return m_pFinish;
		}
		/// <summary>
		/// begin������
		/// <para>*ֻ��������</para>
		/// </summary>
		/// <returns>��һ����ЧԪ��λ�õĵ�����</returns>
		iterator begin() const {
			return m_pStart;
		}
		/// <summary>
		/// end������
		/// <para>*ֻ��������</para>
		/// </summary>
		/// <returns>���һ����ЧԪ�ص���һ��λ�õĵ�����</returns>
		iterator end() const {
			return m_pFinish;
		}
		/// <summary>
		/// cbegin������
		/// <para>*const������</para>
		/// </summary>
		/// <returns>��һ����ЧԪ��λ�õĵ�����</returns>
		const_iterator cbegin() const {
			return m_pStart;
		}
		/// <summary>
		/// cend������
		/// <para>*const������</para>
		/// </summary>
		/// <returns>���һ����ЧԪ�ص���һ��λ�õĵ�����</returns>
		const_iterator cend() const {
			return m_pFinish;
		}
		#pragma endregion
		#pragma region ���������
		typedef			T* reverse_iterator;		//���������
		typedef const	T* const_reverse_iterator;	//const���������
		/// <summary>
		/// rbegin���������
		/// </summary>
		/// <returns>���һ����ЧԪ��λ�õķ��������</returns>
		reverse_iterator rbegin() {
			return m_pFinish - 1;
		}
		/// <summary>
		/// rend���������
		/// </summary>
		/// <returns>��һ����ЧԪ�ص���һ��λ�õķ��������</returns>
		reverse_iterator rend() {
			return m_pStart - 1;
		}
		/// <summary>
		/// rbegin���������
		/// <para>*ֻ��������</para>
		/// </summary>
		/// <returns>���һ����ЧԪ��λ�õķ��������</returns>
		reverse_iterator rbegin() const {
			return m_pFinish - 1;
		}
		/// <summary>
		/// rend���������
		/// <para>*ֻ��������</para>
		/// </summary>
		/// <returns>��һ����ЧԪ�ص���һ��λ�õķ��������</returns>
		reverse_iterator rend() const {
			return m_pStart - 1;
		}
		/// <summary>
		/// crbegin���������
		/// <para>*const������</para>
		/// </summary>
		/// <returns>���һ����ЧԪ��λ�õĵ�����</returns>
		const_reverse_iterator crbegin() const {
			return m_pFinish - 1;
		}
		/// <summary>
		/// crend������
		/// <para>*const������</para>
		/// </summary>
		/// <returns>��һ����ЧԪ�ص���һ��λ�õķ��������</returns>
		const_reverse_iterator crend() const {
			return m_pStart - 1;
		}
		#pragma endregion
	#pragma endregion
	#pragma region �ռ������
	public:
		/// <summary>
		/// ˳�������ЧԪ�ص�����
		/// </summary>
		/// <returns>��ЧԪ�ص�����</returns>
		size_t size() const {
			return m_pFinish - m_pStart;
		}
		/// <summary>
		/// ˳��������
		/// </summary>
		/// <returns>����</returns>
		size_t capacity() const {
			return m_pEndOfStorage - m_pStart;
		}
		/// <summary>
		/// ��ǰ˳����Ƿ�Ϊ�ձ�
		/// </summary>
		/// <returns>
		/// Ϊ�� : true
		/// <para>else : false</para>
		/// </returns>
		bool empty() const {
			return !(m_pFinish - m_pStart);
		}
		/// <summary>
		/// �趨��ǰ��ЧԪ�ص�����
		/// </summary>
		/// <param name="newSize">�����õ���ЧԪ������</param>
		/// <param name="value">������ЧԪ������ʱ����Ĭ��ֵ</param>
		void resize(size_t newSize, T value = T()) {
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
		/// <summary>
		/// ��������
		/// <para>*��������Ϊ0ʱ����*</para>
		/// </summary>
		/// <param name="newCapacity">�µ�����</param>
		void reserve(size_t newCapacity) {
			assert(newCapacity);
			//û�пռ�ʱֱ������ռ䲢��ʼ��
			T* temp = new T[newCapacity];
			if (m_aData != nullptr) {
				//���пռ�ʱ�����¿ռ䲢�ƶ����ݺ��ͷžɿռ�
				////�ƶ�����	//ǳ�������������
				////memmove(temp, m_aData, size() * sizeof(T));
				//���
				for (size_t i = 0; i < size(); ++i) {
					temp[i] = m_aData[i];
				}
				
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
		#pragma region ���ʳ�Ա
		/// <summary>
		/// []
		/// </summary>
		/// <param name="pos">Ҫ���ʵ�����</param>
		/// <returns>ָ������λ��Ԫ�ص�����</returns>
		T& operator[](size_t pos) {
			return at(pos);
		}
		/// <summary>
		/// ����ָ�������Ԫ��
		/// </summary>
		/// <param name="pos">����</param>
		/// <returns>ָ������Ԫ�ص�����</returns>
		T& at(size_t pos) {
			assert(pos < size());
			return m_aData[pos];
		}
		/// <summary>
		/// ˳����е�һ��Ԫ��
		/// </summary>
		/// <returns>��һ����ЧԪ�ص�����</returns>
		T& front() {
			return *m_pStart;
		}
		/// <summary>
		/// ˳��������һ��Ԫ��
		/// </summary>
		/// <returns>����һ����ЧԪ�ص�����</returns>
		T& back() {
			return *(m_pFinish - 1);
		}
		/// <summary>
		/// ˳����ŵ�����
		/// </summary>
		/// <returns>�������λ�õ�ָ��</returns>
		T* data() {
			return m_aData;
		}
		#pragma endregion
		#pragma region ����const��Ա
		/// <summary>
		/// []
		/// <para>*ֻ������*</para>
		/// </summary>
		/// <param name="pos">Ҫ���ʵ�����</param>
		/// <returns>ָ������λ��Ԫ�ص�����</returns>
		const T& operator[](size_t pos) const {
			return at(pos);
		}
		/// <summary>
		/// ����ָ�������Ԫ��
		/// <para>*ֻ������*</para>
		/// </summary>
		/// <param name="pos">����</param>
		/// <returns>ָ������Ԫ�ص�����</returns>
		const T& at(size_t pos) const {
			assert(pos < size());
			return m_aData[pos];
		}
		/// <summary>
		/// ˳����е�һ��Ԫ��
		/// <para>*ֻ������*</para>
		/// </summary>
		/// <returns>��һ����ЧԪ�ص�����</returns>
		const T& front() const {
			return *m_pStart;
		}
		/// <summary>
		/// ˳��������һ��Ԫ��
		/// <para>*ֻ������*</para>
		/// </summary>
		/// <returns>����һ����ЧԪ�ص�����</returns>
		const T& back() const {
			return *m_pFinish;
		}
		/// <summary>
		/// ˳����ŵ�����
		/// <para>*ֻ������*</para>
		/// </summary>
		/// <returns>�������λ�õ�ָ��</returns>
		const T* data() const {
			return m_aData;
		}
		#pragma endregion
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
			//�������汾insert
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
			//�������汾insert
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
				//��������ȣ���һ�Ƚ����е�����
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