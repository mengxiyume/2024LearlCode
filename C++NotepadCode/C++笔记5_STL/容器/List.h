#pragma once
#include <cassert>
#include <initializer_list>
#include <algorithm>

namespace emansis {
	#pragma region 链表节点定义

	/// <summary>
	/// 单个链表节点类
	/// </summary>
	/// <typeparam name="T">链表节点存放的数据类型</typeparam>
	template<class T>
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

	#pragma region 链表正向迭代器类
	/// <summary>
	/// 链表正向迭代器类
	/// </summary>
	/// <typeparam name="T">迭代器指向的元素类型</typeparam>
	/// <typeparam name="Refrence">迭代器指向元素类型的引用</typeparam>
	/// <typeparam name="Pointer">迭代器指向元素类型的指针</typeparam>
	template<class T, class Refrence, class Pointer>
	class listIterator {
	public:
		Node<T>* m_pNode;	//链表节点指针
		typedef listIterator<T, Refrence, Pointer> Self;
		/// <summary>
		/// 链表迭代器构造
		/// </summary>
		/// <param name="it">用于构造迭代器的链表节点</param>
		listIterator(Node<T>* it) : m_pNode(it) { ; }
		#pragma region 操作符重载
		/// <summary>
		/// 前置++
		/// </summary>
		/// <returns>自增后的迭代器</returns>
		Self operator++() {
			m_pNode = m_pNode->m_pNext;
			return *this;
		}
		/// <summary>
		/// 后置++
		/// </summary>
		/// <returns>自增前的迭代器</returns>
		Self operator++(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pNext;
			return temp;
		}
		/// <summary>
		/// 前置--
		/// </summary>
		/// <returns>自减后的迭代器</returns>
		Self operator--() {
			m_pNode = m_pNode->m_pPrev;
			return *this;
		}
		/// <summary>
		/// 后置--
		/// </summary>
		/// <returns>自减前的迭代器</returns>
		Self operator--(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pPrev;
			return temp;
		}
		/// <summary>
		/// 解引用
		/// </summary>
		/// <returns>迭代器指向对象数据的引用</returns>
		Refrence operator*() {
			return m_pNode->m_tData;
		}
		/// <summary>
		/// -&gt;
		/// </summary>
		/// <returns>迭代器指向对象数据的地址</returns>
		Pointer operator->() {
			return &operator*();
		}
		/// <summary>
		/// 迭代器不相等关系操作符
		/// </summary>
		/// <param name="right">右操作数迭代器</param>
		/// <returns>
		/// left iterator != right iterator : true
		/// <para>else : false </para>
		/// </returns>
		bool operator!=(const Self& right) const {
			return m_pNode != right.m_pNode;
		}
		/// <summary>
		/// 迭代器相等关系操作符
		/// </summary>
		/// <param name="right">右操作数迭代器</param>
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
	#pragma region 链表反向迭代器类
	/// <summary>
	/// 链表反向迭代器类
	/// </summary>
	/// <typeparam name="T">迭代器指向的元素类型</typeparam>
	/// <typeparam name="Refrence">迭代器指向元素类型的引用</typeparam>
	/// <typeparam name="Pointer">迭代器指向元素类型的指针</typeparam>
	template<class T, class Refrence, class Pointer>
	class listReverseIterator {
	public:
		Node<T>* m_pNode;
		typedef listReverseIterator<T, Refrence, Pointer> Self;
		listReverseIterator(Node<T>* it) : m_pNode(it) { ; }
		#pragma region 操作符重载
		/// <summary>
		/// 反向前置++
		/// </summary>
		/// <returns>自增后的迭代器</returns>
		Self operator++() {
			m_pNode = m_pNode->m_pPrev;
			return *this;
		}
		/// <summary>
		/// 反向后置++
		/// </summary>
		/// <returns>自增前的迭代器</returns>
		Self operator++(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pPrev;
			return temp;
		}
		/// <summary>
		/// 反向前置--
		/// </summary>
		/// <returns>自减后的迭代器</returns>
		Self operator--() {
			m_pNode = m_pNode->m_pNext;
			return *this;
		}
		/// <summary>
		/// 反向后置--
		/// </summary>
		/// <returns>自减前的迭代器</returns>
		Self operator--(int) {
			Self temp(m_pNode);
			m_pNode = m_pNode->m_pNext;
			return temp;
		}
		/// <summary>
		/// 解引用
		/// </summary>
		/// <returns>迭代器指向对象数据的引用</returns>
		Refrence operator*() {
			return m_pNode->m_tData;
		}
		/// <summary>
		/// 成员访问
		/// </summary>
		/// <returns>迭代器指向对象数据的地址</returns>
		Pointer operator->() {
			return &operator*();
		}
		/// <summary>
		/// 迭代器不相等关系操作符
		/// </summary>
		/// <param name="right">右操作数迭代器</param>
		/// <returns>
		/// left iterator != right iterator : true
		/// <para>else : false </para>
		/// </returns>
		bool operator!=(const Self& right) {
			return m_pNode != right.m_pNode;
		}
		/// <summary>
		/// 迭代器相等关系操作符
		/// </summary>
		/// <param name="right">右操作数迭代器</param>
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
	/// 双向带头循环链表
	/// </summary>
	class list {
	#pragma region 结构成员
	private:
		Node<T>* m_pHead;	//链表哨兵位
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
		/// 使用初始化列表构造链表
		/// </summary>
		/// <param name="src">初始化列表</param>
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
	public:
		/// <summary>
		/// 赋值重载
		/// </summary>
		/// <param name="src">被复制的对象</param>
		/// <returns>完成复制后得到的对象</returns>
		list<T>& operator=(list<T> right) {
			swap(right);
			return *this;
		}
	#pragma region 迭代器相关
	public:
		#pragma region 正向迭代器
		typedef listIterator<T, T&, T*>				iterator;		//迭代器
		typedef listIterator<T, const T&, const T*> const_iterator;	//const迭代器
		/// <summary>
		/// begin迭代器
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回第一个元素位置的迭代器</returns>
		iterator begin() {
			assert(m_pHead);
			return iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// end迭代器
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回最后一个元素的下一个元素位置的迭代器</returns>
		iterator end() {
			assert(m_pHead);
			return iterator(m_pHead);
		}
		/// <summary>
		/// begin迭代器
		/// <para>*只读迭代器*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回第一个元素位置的迭代器</returns>
		iterator begin() const {
			assert(m_pHead);
			return iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// end迭代器
		/// <para>*只读迭代器*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回最后一个元素的下一个元素位置的迭代器</returns>
		iterator end() const {
			assert(m_pHead);
			return iterator(m_pHead);
		}
		/// <summary>
		/// const_begin迭代器
		/// <para>*const迭代器*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回第一个元素的const迭代器</returns>
		const_iterator cbegin() const {
			assert(m_pHead);
			return const_iterator(m_pHead->m_pNext);
		}
		/// <summary>
		/// const_end迭代器
		/// <para>*const迭代器*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回最后一个元素的下一个元素位置的const迭代器</returns>
		const_iterator cend() const {
			assert(m_pHead);
			return const_iterator(m_pHead);
		}
		#pragma endregion
		#pragma region 反向迭代器
		typedef listReverseIterator<T, T&, T*>				reverse_iterator;		//反向迭代器
		typedef listReverseIterator<T, const T&, const T*>	const_reverse_iterator;	//反向const迭代器
		/// <summary>
		/// reverse_begin迭代器
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回链表最后一个元素位置的反向迭代器</returns>
		reverse_iterator rbegin() {
			return m_pHead->m_pPrev;
		}
		/// <summary>
		/// reverse_begin迭代器
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回链表第一个元素的上一个元素位置的反向迭代器</returns>
		reverse_iterator rend() {
			return m_pHead;
		}
		/// <summary>
		/// reverse_begin迭代器
		/// <para>*指向内容不可更改*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回链表最后一个元素位置的反向迭代器</returns>
		reverse_iterator rbegin() const {
			return m_pHead->m_pPrev;
		}
		/// <summary>
		/// reverse_begin迭代器
		/// <para>*指向内容不可更改*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回链表第一个元素的上一个元素位置的反向迭代器</returns>
		reverse_iterator rend() const {
			return m_pHead;
		}
		/// <summary>
		/// reverse_begin迭代器
		/// <para>*const迭代器*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回链表最后一个元素位置的反向迭代器</returns>
		const_reverse_iterator crbegin() const {
			return m_pHead->m_pPrev;
		}
		/// <summary>
		/// reverse_begin迭代器
		/// <para>*const迭代器*</para>
		/// <para>*未初始化链表调用此函数会报错*</para>
		/// </summary>
		/// <returns>返回链表第一个元素的上一个元素位置的反向迭代器</returns>
		const_reverse_iterator crend() const {
			return m_pHead;
		}
		#pragma endregion
	#pragma endregion
	#pragma region 空间管理函数
	public:
		/// <summary>
		/// 计算链表中元素的数量
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <returns>返回链表中有效元素的个数</returns>
		size_t size() const  {
			assert(m_pHead);
			//迭代器遍历计算size
			size_t count = 0;
			for (const auto& e : *this)
				++count;
			return count;
		}
		/// <summary>
		/// 判空
		/// </summary>
		/// <returns>返回该链表是否为空链表</returns>
		bool empty() const  {
			assert(m_pHead);
			return (m_pHead->m_pNext == m_pHead);
		}
	#pragma endregion
	#pragma region 成员访问相关
	public:
		/// <summary>
		/// 获取链表中第一个元素
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// <para>*空链表调用该函数会报错*</para>
		/// </summary>
		/// <returns>链表中的第一个元素的引用</returns>
		T& front() {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pNext->m_tData;
		}
		/// <summary>
		/// 获取链表中第一个元素
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// <para>*空链表调用该函数会报错*</para>
		/// <para>*获取的数据不可更改*</para>
		/// </summary>
		/// <returns>链表中的第一个元素的const引用</returns>
		const T& front() const {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pNext->m_tData;
		}
		/// <summary>
		/// 获取链表的最后一个元素
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// <para>*空链表调用该函数会报错*</para>
		/// </summary>
		/// <returns>链表中最后一个元素的引用</returns>
		T& back() {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pPrev->m_tData;
		}
		/// <summary>
		/// 获取链表的最后一个元素
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// <para>*空链表调用该函数会报错*</para>
		/// <para>*获取的数据不可更改*</para>
		/// </summary>
		/// <returns>链表中最后一个元素的引用</returns>
		const T& back() const {
			assert(m_pHead);
			assert(!empty());
			return m_pHead->m_pPrev->m_tData;
		}
	#pragma endregion
	#pragma region 成员改动相关
	public:
		/// <summary>
		/// 交换两链表的内容
		/// </summary>
		/// <param name="right">另一个链表</param>
		void swap(list<T>& right) {
			std::swap(*this, right);
		}
		/// <summary>
		/// 在指定迭代器前插入一个元素
		/// </summary>
		/// <param name="position">指向坐标的迭代器</param>
		/// <param name="value">新插入的值</param>
		/// <returns>新插入元素的下一个元素的迭代器</returns>
		iterator insert(iterator position, const T& value) {
			//在position前插入新元素
			assert(m_pHead);
			//创建并填充新节点
			Node<T>* newNode = new Node<T>(value);
			//链接节点
			newNode->m_pPrev				= position.m_pNode->m_pPrev;
			newNode->m_pNext				= position.m_pNode;
			position.m_pNode->m_pPrev->m_pNext = newNode;
			position.m_pNode->m_pPrev			= newNode;

			return ++position;
		}
		/// <summary>
		/// 删除指定迭代器位置的元素
		/// <para>*存在迭代器失效问题，请使用返回值更新迭代器*</para>
		/// </summary>
		/// <param name="position">指向坐标的迭代器</param>
		/// <returns>被删除元素的下一个元素的迭代器</returns>
		iterator erase(iterator position) {
			//删除position位置的元素
			assert(!empty());
			//断开链接
			Node<T>* next = position.m_pNode->m_pNext;
			Node<T>* prev = position.m_pNode->m_pPrev;
			next->m_pPrev = prev;
			prev->m_pNext = next;
			//删除节点
			delete position.m_pNode;

			return iterator(next);
		}
		/// <summary>
		/// 尾插一个数据
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="value">要插入的数据</param>
		void push_back(const T& value) {
			assert(m_pHead);
			////获取一个新节点并填充值
			//Node<T>* newNode = new Node<T>(value);
			////链接新节点
			//newNode->m_pPrev			= m_pHead->m_pPrev;
			//newNode->m_pNext			= m_pHead;
			//m_pHead->m_pPrev->m_pNext	= newNode;
			//m_pHead->m_pPrev			= newNode;

			insert(end(), value);
		}
		/// <summary>
		/// 尾删一个节点
		/// <para>*空链表调用该函数会报错*</para>
		/// </summary>
		void pop_back() {
			assert(!empty());
			////获取尾节点
			//Node<T>* popNode = m_pHead->m_pPrev;
			////尾节点断开链接
			//popNode->m_pPrev->m_pNext	= popNode->m_pNext;
			//popNode->m_pNext->m_pPrev	= popNode->m_pPrev;
			//delete popNode;

			erase(--end());
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
	public:
		/// <summary>
		/// &gt;
		/// <para>优先比较元素数量，数量相等依次比较元素的大小</para>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="right">右操作数</param>
		/// <returns>
		/// left &gt; right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator>	(const list<T>& right) const  {
			return compare(right) > 0;
		}
		/// <summary>
		/// &gt;=
		/// <para>优先比较元素数量，数量相等依次比较元素的大小</para>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="right">右操作数</param>
		/// <returns>
		/// left &gt;= right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator>=	(const list<T>& right) const  {
			return compare(right) >= 0;
		}
		/// <summary>
		/// &lt;
		/// <para>优先比较元素数量，数量相等依次比较元素的大小</para>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="right">右操作数</param>
		/// <returns>
		/// left &lt; right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator<	(const list<T>& right) const  {
			return compare(right) < 0;
		}
		/// <summary>
		/// &lt;=
		/// <para>优先比较元素数量，数量相等依次比较元素的大小</para>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="right">右操作数</param>
		/// <returns>
		/// <para>left &lt;= right : true</para>
		/// <para>else : false</para>
		/// </returns>
		bool operator<=	(const list<T>& right) const  {
			return compare(right) <= 0;
		}
		/// <summary>
		/// ==
		/// <para>优先比较元素数量，数量相等依次比较元素的大小</para>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="right">右操作数</param>
		/// <returns>
		/// left == right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator==	(const list<T>& right) const  {
			return compare(right) == 0;
		}
		/// <summary>
		/// !=
		/// <para>优先比较元素数量，数量相等依次比较元素的大小</para>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="right">右操作数</param>
		/// <returns>
		/// left != right : true
		/// <para>else : false</para>
		/// </returns>
		bool operator!=	(const list<T>& right) const {
			return compare(right) != 0;
		}
	private:
		/// <summary>
		/// 对比两个链表
		/// <para>优先比较元素数量，数量相等依次比较元素的大小</para>
		/// <para>*未初始化的链表调用该函数会报错*</para>
		/// </summary>
		/// <param name="right">右操作数</param>
		/// <returns>
		/// left &gt; right : 正数
		/// <para>left &lt; right : 负数</para>
		/// <para>left = right : 0</para>
		/// </returns>
		int compare		(const list<T>& right) const {
			assert(m_pHead);
			if (m_pHead == right.m_pHead)
				return 0;
			size_t leftSize = size(), rightSize = right.size();
			if (leftSize - rightSize == 0) {
				//开始逐个比较
				const_iterator lIt = cbegin(), rIt = right.cbegin();
				while (lIt != cend()) {
					if (*lIt > *rIt) {
						return 1;
					}
					else if (*lIt < *rIt) {
						return -1;
					}
					//迭代器更新
					++lIt, ++rIt;
				}
				return 0;
			} 
			//size不相等
			else
				return (int)leftSize - (int)rightSize;
		}
	#pragma endregion
	};
}