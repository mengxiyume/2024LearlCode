#pragma once
#include <cassert>
#include <initializer_list>
#include <algorithm>

namespace emansis {
	#pragma region ����ڵ㶨��

	/// <summary>
	/// ��������ڵ���
	/// </summary>
	/// <typeparam name="T">����ڵ��ŵ���������</typeparam>
	template<class T>
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

	#pragma region ���������������
	/// <summary>
	/// ���������������
	/// </summary>
	/// <typeparam name="T">������ָ���Ԫ������</typeparam>
	/// <typeparam name="Refrence">������ָ��Ԫ�����͵�����</typeparam>
	/// <typeparam name="Pointer">������ָ��Ԫ�����͵�ָ��</typeparam>
	template<class T, class Refrence, class Pointer>
	class listIterator {
	public:
		Node<T>* m_pNode;	//����ڵ�ָ��
		typedef listIterator<T, Refrence, Pointer> Self;
		/// <summary>
		/// �������������
		/// </summary>
		/// <param name="it">���ڹ��������������ڵ�</param>
		listIterator(Node<T>* it) : m_pNode(it) { ; }
		#pragma region ����������
		/// <summary>
		/// ǰ��++
		/// </summary>
		/// <returns>������ĵ�����</returns>
		Self operator++() {
			m_pNode = m_pNode->m_pNext;
			return *this;
		}
		/// <summary>
		/// ����++
		/// </summary>
		/// <returns>����ǰ�ĵ�����</returns>
		Self operator++(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pNext;
			return temp;
		}
		/// <summary>
		/// ǰ��--
		/// </summary>
		/// <returns>�Լ���ĵ�����</returns>
		Self operator--() {
			m_pNode = m_pNode->m_pPrev;
			return *this;
		}
		/// <summary>
		/// ����--
		/// </summary>
		/// <returns>�Լ�ǰ�ĵ�����</returns>
		Self operator--(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pPrev;
			return temp;
		}
		/// <summary>
		/// ������
		/// </summary>
		/// <returns>������ָ��������ݵ�����</returns>
		Refrence operator*() {
			return m_pNode->m_tData;
		}
		/// <summary>
		/// -&gt;
		/// </summary>
		/// <returns>������ָ��������ݵĵ�ַ</returns>
		Pointer operator->() {
			return &operator*();
		}
		/// <summary>
		/// ����������ȹ�ϵ������
		/// </summary>
		/// <param name="right">�Ҳ�����������</param>
		/// <returns>
		/// left iterator != right iterator : true
		/// <para>else : false </para>
		/// </returns>
		bool operator!=(const Self& right) const {
			return m_pNode != right.m_pNode;
		}
		/// <summary>
		/// ��������ȹ�ϵ������
		/// </summary>
		/// <param name="right">�Ҳ�����������</param>
		/// <returns>
		/// left iterator == right iterator : true
		/// <para>else : false </para>
		/// </returns>
		bool operator==(const Self& right) const {
			return m_pNode == right.m_pNode;
		}
		#pragma endregion
	};
	#pragma endregion
	#pragma region �������������
	/// <summary>
	/// �������������
	/// </summary>
	/// <typeparam name="T">������ָ���Ԫ������</typeparam>
	/// <typeparam name="Refrence">������ָ��Ԫ�����͵�����</typeparam>
	/// <typeparam name="Pointer">������ָ��Ԫ�����͵�ָ��</typeparam>
	template<class T, class Refrence, class Pointer>
	class listReverseIterator {
	public:
		Node<T>* m_pNode;
		typedef listReverseIterator<T, Refrence, Pointer> Self;
		listReverseIterator(Node<T>* it) : m_pNode(it) { ; }
		#pragma region ����������
		/// <summary>
		/// ����ǰ��++
		/// </summary>
		/// <returns>������ĵ�����</returns>
		Self operator++() {
			m_pNode = m_pNode->m_pPrev;
			return *this;
		}
		/// <summary>
		/// �������++
		/// </summary>
		/// <returns>����ǰ�ĵ�����</returns>
		Self operator++(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pPrev;
			return temp;
		}
		/// <summary>
		/// ����ǰ��--
		/// </summary>
		/// <returns>�Լ���ĵ�����</returns>
		Self operator--() {
			m_pNode = m_pNode->m_pNext;
			return *this;
		}
		/// <summary>
		/// �������--
		/// </summary>
		/// <returns>�Լ�ǰ�ĵ�����</returns>
		Self operator--(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pNext;
			return temp;
		}
		/// <summary>
		/// ������
		/// </summary>
		/// <returns>������ָ��������ݵ�����</returns>
		Refrence operator*() {
			return m_pNode->m_tData;
		}
		/// <summary>
		/// ��Ա����
		/// </summary>
		/// <returns>������ָ��������ݵĵ�ַ</returns>
		Pointer operator->() {
			return &operator*();
		}
		/// <summary>
		/// ����������ȹ�ϵ������
		/// </summary>
		/// <param name="right">�Ҳ�����������</param>
		/// <returns>
		/// left iterator != right iterator : true
		/// <para>else : false </para>
		/// </returns>
		bool operator!=(const Self& right) {
			return m_pNode != right.m_pNode;
		}
		/// <summary>
		/// ��������ȹ�ϵ������
		/// </summary>
		/// <param name="right">�Ҳ�����������</param>
		/// <returns>
		/// left iterator == right iterator : true
		/// <para>else : false </para>
		/// </returns>
		bool operator==(const Self& right) {
			return m_pNode == right.m_pNode;
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
		Node<T>* m_pHead;	//�����ڱ�λ
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
		/// ʹ�ó�ʼ���б�������
		/// </summary>
		/// <param name="src">��ʼ���б�</param>
		list(std::initializer_list<int> src) {
			initList();
			for (const auto& e : src) {
				push_back(e);
			}
		}
		list(const list<T>& src) {
			initList();
			for (const auto& e : src)
				push_back(e);
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
	public:
		/// <summary>
		/// ��ֵ����
		/// </summary>
		/// <param name="src">�����ƵĶ���</param>
		/// <returns>��ɸ��ƺ�õ��Ķ���</returns>
		list<T>& operator=(list<T> right) {
			swap(right);
			return *this;
		}
	#pragma region ���������
	public:
		#pragma region ���������
		typedef listIterator<T, T&, T*>				iterator;		//������
		typedef listIterator<T, const T&, const T*> const_iterator;	//const������
		/// <summary>
		/// begin������
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>���ص�һ��Ԫ��λ�õĵ�����</returns>
		iterator begin() {
			assert(m_pHead);
			return iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// end������
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>�������һ��Ԫ�ص���һ��Ԫ��λ�õĵ�����</returns>
		iterator end() {
			assert(m_pHead);
			return iterator(m_pHead);
		}
		/// <summary>
		/// begin������
		/// <para>*ֻ��������*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>���ص�һ��Ԫ��λ�õĵ�����</returns>
		iterator begin() const {
			assert(m_pHead);
			return iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// end������
		/// <para>*ֻ��������*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>�������һ��Ԫ�ص���һ��Ԫ��λ�õĵ�����</returns>
		iterator end() const {
			assert(m_pHead);
			return iterator(m_pHead);
		}
		/// <summary>
		/// const_begin������
		/// <para>*const������*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>���ص�һ��Ԫ�ص�const������</returns>
		const_iterator cbegin() const {
			assert(m_pHead);
			return const_iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// const_end������
		/// <para>*const������*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>�������һ��Ԫ�ص���һ��Ԫ��λ�õ�const������</returns>
		const_iterator cend() const {
			assert(m_pHead);
			return const_iterator(m_pHead);
		}
		#pragma endregion
		#pragma region ���������
		typedef listReverseIterator<T, T&, T*>				reverse_iterator;		//���������
		typedef listReverseIterator<T, const T&, const T*>	const_reverse_iterator;	//����const������
		/// <summary>
		/// reverse_begin������
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>�����������һ��Ԫ��λ�õķ��������</returns>
		reverse_iterator rbegin() {
			return m_pHead->m_pPrev;
		}
		/// <summary>
		/// reverse_begin������
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>���������һ��Ԫ�ص���һ��Ԫ��λ�õķ��������</returns>
		reverse_iterator rend() {
			return m_pHead;
		}
		/// <summary>
		/// reverse_begin������
		/// <para>*ָ�����ݲ��ɸ���*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>�����������һ��Ԫ��λ�õķ��������</returns>
		reverse_iterator rbegin() const {
			return m_pHead->m_pPrev;
		}
		/// <summary>
		/// reverse_begin������
		/// <para>*ָ�����ݲ��ɸ���*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>���������һ��Ԫ�ص���һ��Ԫ��λ�õķ��������</returns>
		reverse_iterator rend() const {
			return m_pHead;
		}
		/// <summary>
		/// reverse_begin������
		/// <para>*const������*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>�����������һ��Ԫ��λ�õķ��������</returns>
		const_reverse_iterator crbegin() const {
			return m_pHead->m_pPrev;
		}
		/// <summary>
		/// reverse_begin������
		/// <para>*const������*</para>
		/// <para>*δ��ʼ��������ô˺����ᱨ��*</para>
		/// </summary>
		/// <returns>���������һ��Ԫ�ص���һ��Ԫ��λ�õķ��������</returns>
		const_reverse_iterator crend() const {
			return m_pHead;
		}
		#pragma endregion
	#pragma endregion
	#pragma region �ռ������
	public:
		/// <summary>
		/// ����������Ԫ�ص�����
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <returns>������������ЧԪ�صĸ���</returns>
		size_t size() const  {
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
		bool empty() const  {
			assert(m_pHead);
			return (m_pHead->m_pNext == m_pHead);
		}
	#pragma endregion
	#pragma region ��Ա�������
	public:
		/// <summary>
		/// ��ȡ�����е�һ��Ԫ��
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <para>*��������øú����ᱨ��*</para>
		/// </summary>
		/// <returns>�����еĵ�һ��Ԫ�ص�����</returns>
		T& front() {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pNext->m_tData;
		}
		/// <summary>
		/// ��ȡ�����е�һ��Ԫ��
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <para>*��������øú����ᱨ��*</para>
		/// <para>*��ȡ�����ݲ��ɸ���*</para>
		/// </summary>
		/// <returns>�����еĵ�һ��Ԫ�ص�const����</returns>
		const T& front() const {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pNext->m_tData;
		}
		/// <summary>
		/// ��ȡ��������һ��Ԫ��
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <para>*��������øú����ᱨ��*</para>
		/// </summary>
		/// <returns>���������һ��Ԫ�ص�����</returns>
		T& back() {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pPrev->m_tData;
		}
		/// <summary>
		/// ��ȡ��������һ��Ԫ��
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <para>*��������øú����ᱨ��*</para>
		/// <para>*��ȡ�����ݲ��ɸ���*</para>
		/// </summary>
		/// <returns>���������һ��Ԫ�ص�����</returns>
		const T& back() const {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pPrev->m_tData;
		}
	#pragma endregion
	#pragma region ��Ա�Ķ����
	public:
		/// <summary>
		/// ���������������
		/// </summary>
		/// <param name="right">��һ������</param>
		void swap(list<T>& right) {
			std::swap(*this, right);
		}
		/// <summary>
		/// ��ָ��������ǰ����һ��Ԫ��
		/// </summary>
		/// <param name="position">ָ������ĵ�����</param>
		/// <param name="value">�²����ֵ</param>
		/// <returns>�²���Ԫ�ص���һ��Ԫ�صĵ�����</returns>
		iterator insert(iterator position, const T& value) {
			//��positionǰ������Ԫ��
			assert(m_pHead);
			//����������½ڵ�
			Node<T>* newNode = new Node<T>(value);
			//���ӽڵ�
			newNode->m_pPrev				= position.m_pNode->m_pPrev;
			newNode->m_pNext				= position.m_pNode;
			position.m_pNode->m_pPrev->m_pNext = newNode;
			position.m_pNode->m_pPrev			= newNode;

			return ++position;
		}
		/// <summary>
		/// ɾ��ָ��������λ�õ�Ԫ��
		/// <para>*���ڵ�����ʧЧ���⣬��ʹ�÷���ֵ���µ�����*</para>
		/// </summary>
		/// <param name="position">ָ������ĵ�����</param>
		/// <returns>��ɾ��Ԫ�ص���һ��Ԫ�صĵ�����</returns>
		iterator erase(iterator position) {
			//ɾ��positionλ�õ�Ԫ��
			assert(!empty());
			//�Ͽ�����
			Node<T>* next = position.m_pNode->m_pNext;
			Node<T>* prev = position.m_pNode->m_pPrev;
			next->m_pPrev = prev;
			prev->m_pNext = next;
			//ɾ���ڵ�
			delete position.m_pNode;

			return iterator(next);
		}
		/// <summary>
		/// β��һ������
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
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
	public:
		/// <summary>
		/// &gt;
		/// <para>���ȱȽ�Ԫ������������������αȽ�Ԫ�صĴ�С</para>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns>
		/// left &gt; right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator>	(const list<T>& right) const  {
			return compare(right) > 0;
		}
		/// <summary>
		/// &gt;=
		/// <para>���ȱȽ�Ԫ������������������αȽ�Ԫ�صĴ�С</para>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns>
		/// left &gt;= right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator>=	(const list<T>& right) const  {
			return compare(right) >= 0;
		}
		/// <summary>
		/// &lt;
		/// <para>���ȱȽ�Ԫ������������������αȽ�Ԫ�صĴ�С</para>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns>
		/// left &lt; right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator<	(const list<T>& right) const  {
			return compare(right) < 0;
		}
		/// <summary>
		/// &lt;=
		/// <para>���ȱȽ�Ԫ������������������αȽ�Ԫ�صĴ�С</para>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns>
		/// <para>left &lt;= right : true</para>
		/// <para>else : false</para>
		/// </returns>
		bool operator<=	(const list<T>& right) const  {
			return compare(right) <= 0;
		}
		/// <summary>
		/// ==
		/// <para>���ȱȽ�Ԫ������������������αȽ�Ԫ�صĴ�С</para>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns>
		/// left == right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator==	(const list<T>& right) const  {
			return compare(right) == 0;
		}
		/// <summary>
		/// !=
		/// <para>���ȱȽ�Ԫ������������������αȽ�Ԫ�صĴ�С</para>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns>
		/// left != right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator!=	(const list<T>& right) const {
			return compare(right) != 0;
		}
	private:
		/// <summary>
		/// �Ա���������
		/// <para>���ȱȽ�Ԫ������������������αȽ�Ԫ�صĴ�С</para>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		/// <returns>
		/// left &gt; right : ����
		/// <para>left &lt; right : ����</para>
		/// <para>left = right : 0</para>
		/// </returns>
		int compare		(const list<T>& right) const {
			assert(m_pHead);
			if (m_pHead == right.m_pHead)
				return 0;
			size_t leftSize = size(), rightSize = right.size();
			if (leftSize - rightSize == 0) {
				//��ʼ����Ƚ�
				const_iterator lIt = cbegin(), rIt = right.cbegin();
				while (lIt != cend()) {
					if (*lIt > *rIt) {
						return 1;
					}
					else if (*lIt < *rIt) {
						return -1;
					}
					//����������
					++lIt, ++rIt;
				}
				return 0;
			} 
			//size�����
			else
				return (int)leftSize - (int)rightSize;
		}
	#pragma endregion
	};
}