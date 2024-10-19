#pragma once
#include <cassert>

namespace emansis {
	#pragma region ����ڵ㶨��
	template<class T>
	/// <summary>
	/// ��������ڵ�
	/// </summary>
	struct node {
		#pragma region �������
		/// <summary>
		/// ����һ������ڵ�
		/// </summary>
		/// <param name="value">��ʼ��ʱ�����ֵ ȱʡ����ΪT��Ĭ�Ϲ���</param>
		node(const T& value = T())
			: m_tData(value)
			, m_pPrev(nullptr)
			, m_pNext(nullptr) {
			;
		}
		#pragma endregion
		#pragma region ��Ա����
		T			m_tData;	//���ݴ�Ŵ�
		node<T>*	m_pPrev;	//ָ����һ���ڵ��ָ��
		node<T>*	m_pNext;	//ָ����һ���ڵ��ָ��
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
		node<T>* m_pHead;
	#pragma endregion
	#pragma region �������
	public:
		/// <summary>
		/// ����һ��������
		/// </summary>
		list() {
			initList();
		}
		~list() {
			;
		}
	private:
		/// <summary>
		/// �����ʼ��
		/// <para>����ͷ�ڵ�ռ䲢����</para>
		/// </summary>
		void initList() {
			m_pHead = new node<T>;
			m_pHead->m_pNext = m_pHead->m_pPrev = m_pHead;
		}
	#pragma endregion
	#pragma region ���������
		class listIterator {
		private:
			node<T>* it;
		public:
			//iterator operator++() {
			//	assert(it);
			//	//TODO:++
			//}
		};
		typedef listIterator iterator, &refernce, *pointer;
		//typedef listIterator const const_iterator, const &const_refernce, const *const_pointer;
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
		//const_iterator begin() const {
		//	assert(!empty());
		//	return m_pHead->m_pNext;
		//}
		///// <summary>
		///// const_end������
		///// </summary>
		///// <para>*const������*</para>
		///// <returns>�������һ��Ԫ�ص���һ��λ�õ�const������</returns>
		//const_iterator end() const {
		//	assert(!empty());
		//	return m_pHead;
		//}
	#pragma endregion
	#pragma region �ռ������
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
		
	#pragma endregion
	#pragma region ��Ա�Ķ����
		/// <summary>
		/// β��һ������
		/// </summary>
		/// <para>*δ��ʼ����������øú����ᱨ��*</para>
		/// <param name="value">Ҫ���������</param>
		void push_back(const T& value) {
			assert(m_pHead);
			//��ȡһ���½ڵ㲢���ֵ
			node<T>* newNode = new node<T>(value);
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
			node<T>* popNode = m_pHead->m_pPrev;
			//β�ڵ�Ͽ�����
			popNode->m_pPrev->m_pNext	= popNode->m_pNext;
			popNode->m_pNext->m_pPrev	= popNode->m_pPrev;
			delete popNode;
		}
	#pragma endregion


	};
}