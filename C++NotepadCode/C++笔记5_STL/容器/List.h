#pragma once
#include <cassert>

namespace emansis {
	#pragma region 链表节点定义
	template<class T>
	/// <summary>
	/// 单个链表节点
	/// </summary>
	struct Node {
		#pragma region 构造相关
		/// <summary>
		/// 构造一个链表节点
		/// </summary>
		/// <param name="value">初始化时填入的值 缺省参数为T的默认构造</param>
		Node(const T& value = T())
			: m_tData(value)
			, m_pPrev(nullptr)
			, m_pNext(nullptr) {
			;
		}
		#pragma endregion
		#pragma region 成员变量
		T			m_tData;	//数据存放处
		Node<T>*	m_pPrev;	//指向上一个节点的指针
		Node<T>*	m_pNext;	//指向下一个节点的指针
		#pragma endregion
	};
	#pragma endregion

#pragma region 链表迭代器类
	template<class T, class Refrence, class Pointer>
	class listIterator {
	private:
		Node<T>* data;
	public:
		typedef listIterator<T, Refrence, Pointer> Self;
		listIterator(Node<T>* it) : data(it) { ; }
		/// <summary>
		/// 前置++
		/// </summary>
		/// <returns>自增后的迭代器存放的变量的引用</returns>
		Refrence operator++() {
			data = data->m_pNext;
			return data->m_tData;
		}
		/// <summary>
		/// 后置++
		/// </summary>
		/// <returns>自增前的迭代器存放的变量的引用</returns>
		Refrence operator++(int) {
			Self temp(data);
			data = data->m_pNext;
			return temp;
		}
		/// <summary>
		/// 前置--
		/// </summary>
		/// <returns>自减后的迭代器存放的变量的引用</returns>
		Refrence operator--() {
			data = data->m_pPrev;
			return data;
		}
		/// <summary>
		/// 后置--
		/// </summary>
		/// <returns>自减前的迭代器存放的变量的引用</returns>
		Refrence operator--(int) {
			Self temp(data);
			data = data->m_pPrev;
			return temp;
		}
		/// <summary>
		/// 解引用
		/// </summary>
		/// <returns>迭代器指向对象的引用</returns>
		Refrence operator*() {
			return data->m_tData;
		}
		/// <summary>
		/// 成员访问
		/// </summary>
		/// <returns>迭代器指向对象的地址</returns>
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
	/// 双向带头循环链表
	/// </summary>
	class list {
	#pragma region 结构成员
	private:
		Node<T>* m_pHead;
	#pragma endregion
	#pragma region 构造相关
	public:
		/// <summary>
		/// 构造一个空链表
		/// </summary>
		list() {
			initList();
		}
		/// <summary>
		/// 析构函数
		/// </summary>
		~list() {
			clear();
			delete m_pHead;
		}
	private:
		/// <summary>
		/// 链表初始化
		/// <para>申请头节点空间并链接</para>
		/// </summary>
		void initList() {
			m_pHead = new Node<T>;
			m_pHead->m_pNext = m_pHead->m_pPrev = m_pHead;
		}
	#pragma endregion
	#pragma region 迭代器相关
	public:
		typedef listIterator<T, T&, T*>				iterator;
		typedef listIterator<T, const T&, const T*> const_iterator;

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
		const_iterator cbegin() const {
			assert(!empty());
			return m_pHead->m_pNext;
		}
		/// <summary>
		/// const_end迭代器
		/// </summary>
		/// <para>*const迭代器*</para>
		/// <returns>返回最后一个元素的下一个位置的const迭代器</returns>
		const_iterator cend() const {
			assert(!empty());
			return m_pHead;
		}
	#pragma endregion
	#pragma region 空间管理函数
	public:
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
	public:
	#pragma endregion
	#pragma region 成员改动相关
	public:
		/// <summary>
		/// 尾插一个数据
		/// </summary>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// <param name="value">要插入的数据</param>
		void push_back(const T& value) {
			assert(m_pHead);
			//获取一个新节点并填充值
			Node<T>* newNode = new Node<T>(value);
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
			Node<T>* popNode = m_pHead->m_pPrev;
			//尾节点断开链接
			popNode->m_pPrev->m_pNext	= popNode->m_pNext;
			popNode->m_pNext->m_pPrev	= popNode->m_pPrev;
			delete popNode;
		}
		/// <summary>
		/// 清除链表中的所有元素
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		void clear() {
			assert(m_pHead);
			while (!empty()) {
				pop_back();
			}
		}
	#pragma endregion
	#pragma region 关系运算符重载

	#pragma endregion


	};
}