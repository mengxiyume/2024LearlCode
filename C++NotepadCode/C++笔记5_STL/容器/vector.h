#pragma once

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <cassert>
#include <initializer_list>
namespace emansis {

	//TODO:迭代器类与反向迭代器类实现
	template<class T>
	/// <summary>
	/// 顺序表
	/// </summary>
	class vector {
	#pragma region 构造相关
	public:
		/// <summary>
		/// 默认构造
		/// </summary>
		vector() = default;
		template<class InputIterator>
		/// <summary>
		/// 迭代器区间初始化
		/// </summary>
		/// <param name="start">迭代器开始的位置</param>
		/// <param name="finish">迭代器结束的下一个位置</param>
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
		/// 初始化列表构造
		/// </summary>
		/// <param name="il">初始化列表</param>
		vector(std::initializer_list<T> il) {
			reserve(il.size());
			for (auto e : il) {
				*this += e;
			}
		}
		/// <summary>
		/// N项数值填充初始化
		/// </summary>
		/// <param name="n">初始化的数量</param>
		/// <param name="value">需要填入的值</param>
		explicit vector(size_t n, const T& value = T()) {
			vector<T> temp;
			temp.resize(n, value);
			swap(temp);
		}
		/// <summary>
		/// 拷贝构造
		/// </summary>
		/// <param name="src">被拷贝的顺序表对象</param>
		explicit vector(const vector<T>& src) {
			reserve(src.capacity());
			for (const auto& e : src)
				*this += e;
		}
		/// <summary>
		/// 析构函数
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
	#pragma region 迭代器相关
		#pragma region 正向迭代器
		typedef			T* iterator;		//迭代器
		typedef const	T* const_iterator;	//const迭代器
		/// <summary>
		/// begin迭代器
		/// </summary>
		/// <returns>第一个有效元素位置的迭代器</returns>
		iterator begin() {
			return m_pStart;
		}
		/// <summary>
		/// end迭代器
		/// </summary>
		/// <returns>最后一个有效元素的下一个位置的迭代器</returns>
		iterator end() {
			return m_pFinish;
		}
		/// <summary>
		/// begin迭代器
		/// <para>*只读迭代器</para>
		/// </summary>
		/// <returns>第一个有效元素位置的迭代器</returns>
		iterator begin() const {
			return m_pStart;
		}
		/// <summary>
		/// end迭代器
		/// <para>*只读迭代器</para>
		/// </summary>
		/// <returns>最后一个有效元素的下一个位置的迭代器</returns>
		iterator end() const {
			return m_pFinish;
		}
		/// <summary>
		/// cbegin迭代器
		/// <para>*const迭代器</para>
		/// </summary>
		/// <returns>第一个有效元素位置的迭代器</returns>
		const_iterator cbegin() const {
			return m_pStart;
		}
		/// <summary>
		/// cend迭代器
		/// <para>*const迭代器</para>
		/// </summary>
		/// <returns>最后一个有效元素的下一个位置的迭代器</returns>
		const_iterator cend() const {
			return m_pFinish;
		}
		#pragma endregion
		#pragma region 反向迭代器
		typedef			T* reverse_iterator;		//反向迭代器
		typedef const	T* const_reverse_iterator;	//const反向迭代器
		/// <summary>
		/// rbegin反向迭代器
		/// </summary>
		/// <returns>最后一个有效元素位置的反向迭代器</returns>
		reverse_iterator rbegin() {
			return m_pFinish - 1;
		}
		/// <summary>
		/// rend反向迭代器
		/// </summary>
		/// <returns>第一个有效元素的上一个位置的反向迭代器</returns>
		reverse_iterator rend() {
			return m_pStart - 1;
		}
		/// <summary>
		/// rbegin反向迭代器
		/// <para>*只读迭代器</para>
		/// </summary>
		/// <returns>最后一个有效元素位置的反向迭代器</returns>
		reverse_iterator rbegin() const {
			return m_pFinish - 1;
		}
		/// <summary>
		/// rend反向迭代器
		/// <para>*只读迭代器</para>
		/// </summary>
		/// <returns>第一个有效元素的上一个位置的反向迭代器</returns>
		reverse_iterator rend() const {
			return m_pStart - 1;
		}
		/// <summary>
		/// crbegin反向迭代器
		/// <para>*const迭代器</para>
		/// </summary>
		/// <returns>最后一个有效元素位置的迭代器</returns>
		const_reverse_iterator crbegin() const {
			return m_pFinish - 1;
		}
		/// <summary>
		/// crend迭代器
		/// <para>*const迭代器</para>
		/// </summary>
		/// <returns>第一个有效元素的下一个位置的反向迭代器</returns>
		const_reverse_iterator crend() const {
			return m_pStart - 1;
		}
		#pragma endregion
	#pragma endregion
	#pragma region 空间管理函数
	public:
		/// <summary>
		/// 顺序表中有效元素的数量
		/// </summary>
		/// <returns>有效元素的数量</returns>
		size_t size() const {
			return m_pFinish - m_pStart;
		}
		/// <summary>
		/// 顺序表的容量
		/// </summary>
		/// <returns>容量</returns>
		size_t capacity() const {
			return m_pEndOfStorage - m_pStart;
		}
		/// <summary>
		/// 当前顺序表是否为空表
		/// </summary>
		/// <returns>
		/// 为空 : true
		/// <para>else : false</para>
		/// </returns>
		bool empty() const {
			return !(m_pFinish - m_pStart);
		}
		/// <summary>
		/// 设定当前有效元素的数量
		/// </summary>
		/// <param name="newSize">新设置的有效元素数量</param>
		/// <param name="value">增加有效元素数量时填充的默认值</param>
		void resize(size_t newSize, T value = T()) {
			//缩小空间
			if (newSize < size()) {
				m_pFinish -= (size() - newSize);
				return;
			}
			//容器需要扩容
			else if (newSize > capacity()) {
				reserve(newSize);
			}
			//剩余空间使用value填充
			T* cur = m_pFinish;
			while (cur < m_aData + newSize) {
				*cur = value;
				++cur;
			}
			m_pFinish = m_aData + newSize;
		}
		/// <summary>
		/// 重设容量
		/// <para>*填入容量为0时报错*</para>
		/// </summary>
		/// <param name="newCapacity">新的容量</param>
		void reserve(size_t newCapacity) {
			assert(newCapacity);
			//没有空间时直接申请空间并初始化
			T* temp = new T[newCapacity];
			if (m_aData != nullptr) {
				//已有空间时创建新空间并移动数据和释放旧空间
				////移动数据	//浅拷贝，会出问题
				////memmove(temp, m_aData, size() * sizeof(T));
				//深拷贝
				for (size_t i = 0; i < size(); ++i) {
					temp[i] = m_aData[i];
				}
				
				//释放旧空间
				delete[] m_aData;
			}
			//管理数据移动
			m_pEndOfStorage = temp + newCapacity;
			m_pFinish = temp + size();
			m_pStart = temp;
			m_aData = temp;
		}
	#pragma endregion
	#pragma region 成员访问相关
	public:
		#pragma region 访问成员
		/// <summary>
		/// []
		/// </summary>
		/// <param name="pos">要访问的坐标</param>
		/// <returns>指定坐标位置元素的引用</returns>
		T& operator[](size_t pos) {
			return at(pos);
		}
		/// <summary>
		/// 访问指定坐标的元素
		/// </summary>
		/// <param name="pos">坐标</param>
		/// <returns>指定坐标元素的引用</returns>
		T& at(size_t pos) {
			assert(pos < size());
			return m_aData[pos];
		}
		/// <summary>
		/// 顺序表中第一个元素
		/// </summary>
		/// <returns>第一个有效元素的引用</returns>
		T& front() {
			return *m_pStart;
		}
		/// <summary>
		/// 顺序表中最后一个元素
		/// </summary>
		/// <returns>最有一个有效元素的引用</returns>
		T& back() {
			return *(m_pFinish - 1);
		}
		/// <summary>
		/// 顺序表存放的数据
		/// </summary>
		/// <returns>存放数据位置的指针</returns>
		T* data() {
			return m_aData;
		}
		#pragma endregion
		#pragma region 访问const成员
		/// <summary>
		/// []
		/// <para>*只读引用*</para>
		/// </summary>
		/// <param name="pos">要访问的坐标</param>
		/// <returns>指定坐标位置元素的引用</returns>
		const T& operator[](size_t pos) const {
			return at(pos);
		}
		/// <summary>
		/// 访问指定坐标的元素
		/// <para>*只读引用*</para>
		/// </summary>
		/// <param name="pos">坐标</param>
		/// <returns>指定坐标元素的引用</returns>
		const T& at(size_t pos) const {
			assert(pos < size());
			return m_aData[pos];
		}
		/// <summary>
		/// 顺序表中第一个元素
		/// <para>*只读引用*</para>
		/// </summary>
		/// <returns>第一个有效元素的引用</returns>
		const T& front() const {
			return *m_pStart;
		}
		/// <summary>
		/// 顺序表中最后一个元素
		/// <para>*只读引用*</para>
		/// </summary>
		/// <returns>最有一个有效元素的引用</returns>
		const T& back() const {
			return *m_pFinish;
		}
		/// <summary>
		/// 顺序表存放的数据
		/// <para>*只读引用*</para>
		/// </summary>
		/// <returns>存放数据位置的指针</returns>
		const T* data() const {
			return m_aData;
		}
		#pragma endregion
	#pragma endregion
#pragma region 成员改动相关
	public:
		void push_back(const T& value) {
			//容量检测
			if (size() + 1 > capacity()) {
				size_t newCapacity = m_aData == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			//尾插
			*m_pFinish = value;
			//尾元素指针移动
			++m_pFinish;
		}
		void pop_back() {
			assert(!empty());
			//尾元素指针移动
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
			//容量检测
			if (size() + 1 >= capacity()) {
				size_t newCapacity = m_aData == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			//数据移动
			for (size_t i = size(); i > position; --i) {
				m_aData[i] = m_aData[i - 1];
			}
			//数据写入
			m_aData[position] = value;

			//尾元素指针移动
			++m_pFinish;
		}
		iterator insert(iterator position, const T& value) {
			//迭代器版本insert
			assert(position >= m_pStart && position <= m_pFinish);

			//iterator oldStart = m_pStart;
			////容量检测
			//if (size() + 1 >= capacity()) {
			//	size_t newCapacity = m_aData == nullptr ? 4 : capacity() * 2;
			//	reserve(newCapacity);	//迭代器指向更新
			//	position = m_pStart + (position - oldStart);
			//}
			////数据移动
			//iterator curIt = m_pFinish;
			//while (curIt > position) {
			//	*curIt = *(curIt - 1);
			//	--curIt;
			//}
			////插入元素
			//*position = value;
			////尾指针更新
			//++m_pFinish;
			//return position + 1;

			size_t uOffsetPosition = position - begin();
			insert(uOffsetPosition, value);
			return begin() + uOffsetPosition + 1;
		}
		void erase(size_t position) {
			assert(position < size());
			assert(!empty());
			//数据移动
			for (size_t i = position; i < size() - 1; ++i) {
				m_aData[i] = m_aData[i + 1];
			}
			//尾元素指针移动
			--m_pFinish;
		}
		iterator erase(iterator position) {
			//迭代器版本insert
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
#pragma region 关系操作符重载
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
			//如果两个对象的数据量相等，则逐一比较其中的数据，否则数据量多的对象大
			if (false == ret) {
				//数据量相等，逐一比较其中的数据
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
		T* m_aData;			//数据存放的位置
		T* m_pStart;		//有效数据开始的位置
		T* m_pFinish;		//有效数据结束的位置
		T* m_pEndOfStorage;	//申请的空间结束的位置
	};
}