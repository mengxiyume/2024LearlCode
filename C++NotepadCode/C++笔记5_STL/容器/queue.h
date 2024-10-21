#pragma once
#include "./List.h"
namespace emansis {
#pragma region 队列
	template<class T, class Container = list<T>>
	class queue {
	#pragma region 成员变量
	private:
		Container* m_pData;		//存放数据的容器
	#pragma endregion
	#pragma region 成员函数
	private:
		/// <summary>
		/// 初始化队列
		/// <para>*重复调用会报错*</para>
		/// </summary>
		void initQueue() {
			assert(!m_pData);
			m_pData = new Container();
		}
	public:
		/// <summary>
		/// 构造函数 初始化队列
		/// </summary>
		queue() : m_pData(nullptr){
			initQueue();
		}
		/// <summary>
		/// 析构函数
		/// <para>*空间被提前释放会报错*</para>
		/// </summary>
		~queue() {
			assert(m_pData);
			delete m_pData;
		}
		/// <summary>
		/// 检查队列是否为空
		/// </summary>
		/// <returns>
		/// 为空 : true;
		/// <para>else : false</para>
		/// </returns>
		bool empty() {
			return m_pData->empty();
		}
		/// <summary>
		/// 获取队列内的数据个数
		/// </summary>
		/// <returns>队列内有效数据的数量</returns>
		size_t size() {
			return m_pData->size();
		}
		/// <summary>
		/// 获取队头的元素
		/// </summary>
		/// <returns>队列头部的数据</returns>
		T& front() {
			return *(m_pData->begin());
		}
		/// <summary>
		/// 获取队尾的元素
		/// </summary>
		/// <returns>队列尾部的数据</returns>
		T& back() {
			return *(--(m_pData->end()));
		}
		/// <summary>
		/// 在队列尾部插入一个数据
		/// </summary>
		/// <param name="value">要插入的数据</param>
		void push(const T& value) {
			m_pData->push_back(value);
		}
		/// <summary>
		/// 删除队头的数据
		/// </summary>
		void pop() {
			m_pData->erase(m_pData->begin());
		}
		/// <summary>
		/// 交换两个队列的数据
		/// </summary>
		/// <param name="right">右操作数</param>
		void swap(queue& right) {
			Container* temp = m_pData;
			m_pData = right.m_pData;
			right.m_pData = temp;
		}
	#pragma endregion
	};
#pragma endregion
}