#pragma once
#include <cassert>

namespace emansis {
	#pragma region ����ڵ㶨��
	template<class T>
	/// <summary>
	/// ��������ڵ�
	/// </summary>
	struct Node {
		#pragma region �������
		/// <summary>
		/// ����һ������ڵ�
		/// </summary>
		/// <param name="value">��ʼ��ʱ�����ֵ ȱʡ����ΪT��Ĭ�Ϲ���</param>
		Node(const T& value = T())
			: m_tData(value)
			, m_pPrev(nullptr)
			, m_pNext(nullptr) {
			;
		}
		#pragma endregion
		#pragma region ��Ա����
		T			m_tData;	//���ݴ�Ŵ�
		Node<T>*	m_pPrev;	//ָ����һ���ڵ��ָ��
		Node<T>*	m_pNext;	//ָ����һ���ڵ��ָ��
		#pragma endregion
	};
	#pragma endregion

	#pragma region �����������
	template<class T, class Refrence, class Pointer>
	/// <summary>
	/// ���������
	/// </summary>
	class listIterator {
	public:
		Node<T>* data;	//����ڵ�ָ��
		typedef listIterator<T, Refrence, Pointer> Self;
		/// <summary>
		/// �������������
		/// </summary>
		/// <param name="it">���ڹ��������������ڵ�</param>
		listIterator(Node<T>* it) : data(it) { ; }
		#pragma region ����������
		/// <summary>
		/// ǰ��++
		/// </summary>
		/// <returns>������ĵ�������ŵı���������</returns>
		Self operator++() {
			data = data->m_pNext;
			return *this;
		}
		/// <summary>
		/// ����++
		/// </summary>
		/// <returns>����ǰ�ĵ�������ŵı���������</returns>
		Self operator++(int) {
			Self temp(data);
			data = data->m_pNext;
			return temp;
		}
		/// <summary>
		/// ǰ��--
		/// </summary>
		/// <returns>�Լ���ĵ�������ŵı���������</returns>
		Self operator--() {
			data = data->m_pPrev;
			return *this;
		}
		/// <summary>
		/// ����--
		/// </summary>
		/// <returns>�Լ�ǰ�ĵ�������ŵı���������</returns>
		Self operator--(int) {
			Self temp(data);
			data = data->m_pPrev;
			return temp;
		}
		/// <summary>
		/// ������
		/// </summary>
		/// <returns>������ָ����������</returns>
		Refrence operator*() {
			return data->m_tData;
		}
		/// <summary>
		/// ��Ա����
		/// </summary>
		/// <returns>������ָ�����ĵ�ַ</returns>
		Pointer operator->() {
			return &operator*();
		}
		/// <summary>
		/// ����������ȹ�ϵ������
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns></returns>
		bool operator!=(const Self& right) {
			return data != right.data;
		}
		#pragma endregion
	};
	#pragma endregion

	template<class T>
	/// <summary>
	/// ˫���ͷѭ������
	/// </summary>
	class list {
	#pragma region �ṹ��Ա
	private:
		Node<T>* m_pHead;
	#pragma endregion
	#pragma region �������
	public:
		/// <summary>
		/// ����һ��������
		/// </summary>
		list() {
			initList();
		}
		/// <summary>
		/// ��������
		/// </summary>
		~list() {
			clear();
			delete m_pHead;
		}
	private:
		/// <summary>
		/// �����ʼ��
		/// <para>����ͷ�ڵ�ռ䲢����</para>
		/// </summary>
		void initList() {
			m_pHead = new Node<T>;
			m_pHead->m_pNext = m_pHead->m_pPrev = m_pHead;
		}
	#pragma endregion
	#pragma region ���������
	public:
		typedef listIterator<T, T&, T*>				iterator;
		typedef listIterator<T, const T&, const T*> const_iterator;
		/// <summary>
		/// begin������
		/// </summary>
		/// <returns>���ص�һ��Ԫ�صĵ�����</returns>
		iterator begin() {
			assert(!empty());
			return iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// end������
		/// </summary>
		/// <returns>�������һ��Ԫ�ص���һ��λ�õĵ�����</returns>
		iterator end() {
			return iterator(m_pHead);
		}
		/// <summary>
		/// begin������
		/// <para>*ֻ��������*</para>
		/// </summary>
		/// <returns>���ص�һ��Ԫ�صĵ�����</returns>
		iterator begin() const {
			assert(!empty());
			return iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// end������
		/// </summary>
		/// <para>*ֻ��������*</para>
		/// <returns>�������һ��Ԫ�ص���һ��λ�õĵ�����</returns>
		iterator end() const {
			return iterator(m_pHead);
		}
		/// <summary>
		/// const_begin������
		/// <para>*const������*</para>
		/// </summary>
		/// <returns>���ص�һ��Ԫ�ص�const������</returns>
		const_iterator cbegin() const {
			assert(!empty());
			return const_iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// const_end������
		/// </summary>
		/// <para>*const������*</para>
		/// <returns>�������һ��Ԫ�ص���һ��λ�õ�const������</returns>
		const_iterator cend() const {
			return const_iterator(m_pHead);
		}
	#pragma endregion
	#pragma region �ռ������
	public:
		/// <summary>
		/// ����������Ԫ�ص�����
		/// </summary>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <returns>������������ЧԪ�صĸ���</returns>
		size_t size() {
			assert(m_pHead);
			//��������������size
			size_t count = 0;
			for (const auto& e : *this)
				++count;
			return count;
		}
		/// <summary>
		/// �п�
		/// </summary>
		/// <returns>���ظ������Ƿ�Ϊ������</returns>
		bool empty() {
			assert(m_pHead);
			return (m_pHead->m_pNext == m_pHead);
		}
	#pragma endregion
	#pragma region ��Ա�������
	public:
	#pragma endregion
	#pragma region ��Ա�Ķ����
	public:
		iterator insert(iterator position, const T& value) {
			//��positionǰ������Ԫ��
			assert(m_pHead);
			//����������½ڵ�
			Node<T>* newNode = new Node<T>(value);
			//���ӽڵ�
			newNode->m_pPrev				= position.data->m_pPrev;
			newNode->m_pNext				= position.data;
			position.data->m_pPrev->m_pNext = newNode;
			position.data->m_pPrev			= newNode;

			return ++position;
		}
		iterator erase(iterator position) {
			//ɾ��positionλ�õ�Ԫ��
			assert(!empty());
			//�Ͽ�����
			Node<T>* next = position.data->m_pNext;
			Node<T>* prev = position.data->m_pPrev;
			next->m_pPrev = prev;
			prev->m_pNext = next;
			//ɾ���ڵ�
			delete position.data;

			return iterator(next);
		}
		/// <summary>
		/// β��һ������
		/// </summary>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <param name="value">Ҫ���������</param>
		void push_back(const T& value) {
			assert(m_pHead);
			////��ȡһ���½ڵ㲢���ֵ
			//Node<T>* newNode = new Node<T>(value);
			////�����½ڵ�
			//newNode->m_pPrev			= m_pHead->m_pPrev;
			//newNode->m_pNext			= m_pHead;
			//m_pHead->m_pPrev->m_pNext	= newNode;
			//m_pHead->m_pPrev			= newNode;

			insert(end(), value);
		}
		/// <summary>
		/// βɾһ���ڵ�
		/// <para>*��������øú����ᱨ��*</para>
		/// </summary>
		void pop_back() {
			assert(!empty());
			////��ȡβ�ڵ�
			//Node<T>* popNode = m_pHead->m_pPrev;
			////β�ڵ�Ͽ�����
			//popNode->m_pPrev->m_pNext	= popNode->m_pNext;
			//popNode->m_pNext->m_pPrev	= popNode->m_pPrev;
			//delete popNode;

			erase(--end());
		}
		/// <summary>
		/// ��������е�����Ԫ��
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		void clear() {
			assert(m_pHead);
			while (!empty()) {
				pop_back();
			}
		}
	#pragma endregion
	#pragma region ��ϵ���������

	#pragma endregion


	};
}