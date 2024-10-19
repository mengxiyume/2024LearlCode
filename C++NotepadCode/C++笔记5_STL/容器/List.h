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
	class listIterator {
	private:
		Node<T>* data;
	public:
		typedef listIterator<T, Refrence, Pointer> Self;
		listIterator(Node<T>* it) : data(it) { ; }
		/// <summary>
		/// ǰ��++
		/// </summary>
		/// <returns>������ĵ�������ŵı���������</returns>
		Refrence operator++() {
			data = data->m_pNext;
			return data->m_tData;
		}
		/// <summary>
		/// ����++
		/// </summary>
		/// <returns>����ǰ�ĵ�������ŵı���������</returns>
		Refrence operator++(int) {
			Self temp(data);
			data = data->m_pNext;
			return temp;
		}
		/// <summary>
		/// ǰ��--
		/// </summary>
		/// <returns>�Լ���ĵ�������ŵı���������</returns>
		Refrence operator--() {
			data = data->m_pPrev;
			return data;
		}
		/// <summary>
		/// ����--
		/// </summary>
		/// <returns>�Լ�ǰ�ĵ�������ŵı���������</returns>
		Refrence operator--(int) {
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
			return &data->m_tData;
		}
		bool operator!=(const Self& it) {
			return data != it.data;
		}
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
			return m_pHead->m_pNext;
		}
		/// <summary>
		/// end������
		/// </summary>
		/// <returns>�������һ��Ԫ�ص���һ��λ�õĵ�����</returns>
		iterator end() {
			assert(!empty());
			return m_pHead;
		}
		/// <summary>
		/// begin������
		/// <para>*ֻ��������*</para>
		/// </summary>
		/// <returns>���ص�һ��Ԫ�صĵ�����</returns>
		iterator begin() const {
			assert(!empty());
			return m_pHead->m_pNext;
		}
		/// <summary>
		/// end������
		/// </summary>
		/// <para>*ֻ��������*</para>
		/// <returns>�������һ��Ԫ�ص���һ��λ�õĵ�����</returns>
		iterator end() const {
			assert(!empty());
			return m_pHead;
		}
		/// <summary>
		/// const_begin������
		/// <para>*const������*</para>
		/// </summary>
		/// <returns>���ص�һ��Ԫ�ص�const������</returns>
		const_iterator cbegin() const {
			assert(!empty());
			return m_pHead->m_pNext;
		}
		/// <summary>
		/// const_end������
		/// </summary>
		/// <para>*const������*</para>
		/// <returns>�������һ��Ԫ�ص���һ��λ�õ�const������</returns>
		const_iterator cend() const {
			assert(!empty());
			return m_pHead;
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
			//TODO:��������������size
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
		/// <summary>
		/// β��һ������
		/// </summary>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <param name="value">Ҫ���������</param>
		void push_back(const T& value) {
			assert(m_pHead);
			//��ȡһ���½ڵ㲢���ֵ
			Node<T>* newNode = new Node<T>(value);
			//�����½ڵ�
			newNode->m_pPrev			= m_pHead->m_pPrev;
			newNode->m_pNext			= m_pHead;
			m_pHead->m_pPrev->m_pNext	= newNode;
			m_pHead->m_pPrev			= newNode;
		}
		/// <summary>
		/// βɾһ���ڵ�
		/// <para>*��������øú����ᱨ��*</para>
		/// </summary>
		void pop_back() {
			assert(!empty());
			//��ȡβ�ڵ�
			Node<T>* popNode = m_pHead->m_pPrev;
			//β�ڵ�Ͽ�����
			popNode->m_pPrev->m_pNext	= popNode->m_pNext;
			popNode->m_pNext->m_pPrev	= popNode->m_pPrev;
			delete popNode;
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