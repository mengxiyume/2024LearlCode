#pragma once
#include <cassert>

namespace emansis {
	#pragma region 链表节点定义
	template<class T>
	/// <summary>
	/// 单个链表节点
	/// </summary>
	struct node {
		#pragma region 构造相关
		/// <summary>
		/// 构造一个链表节点
		/// </summary>
		/// <param name="value">初始化时填入的值 缺省参数为T的默认构造</param>
		node(const T& value = T())
			: m_tData(value)
			, m_pPrev(nullptr)
			, m_pNext(nullptr) {
			;
		}
		#pragma endregion
		#pragma region 成员变量
		T			m_tData;	//数据存放处
		node<T>*	m_pPrev;	//指向上一个节点的指针
		node<T>*	m_pNext;	//指向下一个节点的指针
		#pragma endregion
	};
	#pragma endregion

	template<class T>
	/// <summary>
	/// 双向带头循环链表
	/// </summary>
	class list {
	#pragma region 结构成员
	private:
		node<T>* m_pHead;
	#pragma endregion
	#pragma region 构造相关
	public:
		/// <summary>
		/// 构造一个空链表
		/// </summary>
		list() {
			initList();
		}
		~list() {
			;
		}
	private:
		/// <summary>
		/// 链表初始化
		/// <para>申请头节点空间并链接</para>
		/// </summary>
		void initList() {
			m_pHead = new node<T>;
			m_pHead->m_pNext = m_pHead->m_pPrev = m_pHead;
		}
	#pragma endregion
	#pragma region 迭代器相关
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
		/// begin迭代器
		/// </summary>
		/// <returns>返回第一个元素的迭代器</returns>
		iterator begin() {
			assert(!empty());
			return m_pHead->m_pNext;
		}
		/// <summary>
		/// end迭代器
		/// </summary>
		/// <returns>返回最后一个元素的下一个位置的迭代器</returns>
		iterator end() {
			assert(!empty());
			return m_pHead;
		}
		/// <summary>
		/// begin迭代器
		/// <para>*只读迭代器*</para>
		/// </summary>
		/// <returns>返回第一个元素的迭代器</returns>
		iterator begin() const {
			assert(!empty());
			return m_pHead->m_pNext;
		}
		/// <summary>
		/// end迭代器
		/// </summary>
		/// <para>*只读迭代器*</para>
		/// <returns>返回最后一个元素的下一个位置的迭代器</returns>
		iterator end() const {
			assert(!empty());
			return m_pHead;
		}
		/// <summary>
		/// const_begin迭代器
		/// <para>*const迭代器*</para>
		/// </summary>
		/// <returns>返回第一个元素的const迭代器</returns>
		//const_iterator begin() const {
		//	assert(!empty());
		//	return m_pHead->m_pNext;
		//}
		///// <summary>
		///// const_end迭代器
		///// </summary>
		///// <para>*const迭代器*</para>
		///// <returns>返回最后一个元素的下一个位置的const迭代器</returns>
		//const_iterator end() const {
		//	assert(!empty());
		//	return m_pHead;
		//}
	#pragma endregion
	#pragma region 空间管理函数
		/// <summary>
		/// 计算链表中元素的数量
		/// </summary>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// <returns>返回链表中有效元素的个数</returns>
		size_t size() {
			assert(m_pHead);
			//TODO:迭代器遍历计算size
		}
		/// <summary>
		/// 判空
		/// </summary>
		/// <returns>返回该链表是否为空链表</returns>
		bool empty() {
			assert(m_pHead);
			return (m_pHead->m_pNext == m_pHead);
		}
	#pragma endregion
	#pragma region 成员访问相关
		
	#pragma endregion
	#pragma region 成员改动相关
		/// <summary>
		/// 尾插一个数据
		/// </summary>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// <param name="value">要插入的数据</param>
		void push_back(const T& value) {
			assert(m_pHead);
			//获取一个新节点并填充值
			node<T>* newNode = new node<T>(value);
			//链接新节点
			newNode->m_pPrev			= m_pHead->m_pPrev;
			newNode->m_pNext			= m_pHead;
			m_pHead->m_pPrev->m_pNext	= newNode;
			m_pHead->m_pPrev			= newNode;
		}
		/// <summary>
		/// 尾删一个节点
		/// <para>*空链表调用该函数会报错*</para>
		/// </summary>
		void pop_back() {
			assert(!empty());
			//获取尾节点
			node<T>* popNode = m_pHead->m_pPrev;
			//尾节点断开链接
			popNode->m_pPrev->m_pNext	= popNode->m_pNext;
			popNode->m_pNext->m_pPrev	= popNode->m_pPrev;
			delete popNode;
		}
	#pragma endregion


	};
}