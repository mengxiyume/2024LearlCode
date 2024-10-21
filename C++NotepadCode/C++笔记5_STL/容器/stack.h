#pragma once
#include "./vector.h"
#include <initializer_list>
namespace emansis {
#pragma region 栈
	/// <summary>
	/// 栈
	/// </summary>
	/// <typeparam name="T">存储数据的类型</typeparam>
	/// <typeparam name="Container">存储数据的容器</typeparam>
	template<class T, class Container = vector<T>>
	class stack {
	#pragma region 成员变量
	private:
		Container* m_pData;	//用于存储栈数据的容器
	#pragma endregion
	#pragma region 成员函数
	private:
		/// <summary>
		/// 初始化栈
		/// <para>*重复调用会报错*</para>
		/// </summary>
		void initStack() {
			assert(!m_pData);
			m_pData = new Container();
		}
	public:
		/// <summary>
		/// 构造函数 初始化栈
		/// </summary>
		stack() : m_pData(nullptr){
			initStack();
		}
		/// <summary>
		/// 析构函数
		/// <para>*空间被提前释放会报错*</para>
		/// </summary>
		~stack() {
			assert(m_pData);
			delete m_pData;
		}
		/// <summary>
		///  压入一个数据
		/// </summary>
		/// <param name="value">数据</param>
		void push(const T& value) {
			m_pData->push_back(value);
		}
		/// <summary>
		/// 弹出栈顶数据
		/// </summary>
		void pop() {
			m_pData->pop_back();
		}
		/// <summary>
		/// 获取栈顶数据
		/// </summary>
		/// <returns>栈顶数据的引用</returns>
		T& top() {
			return m_pData->back();
		}
		/// <summary>
		/// 检测栈是否为空栈
		/// </summary>
		/// <returns>
		/// 为空 : true
		///	<para>else : false</para>
		/// </returns>
		bool empty() {
			return m_pData->empty();
		}
		/// <summary>
		/// 获取栈内数据的数量
		/// </summary>
		/// <returns>栈内有效数据的数量</returns>
		size_t size() {
			return m_pData->size();
		}
		/// <summary>
		/// 交换两栈数据
		/// </summary>
		/// <param name="right">右操作数</param>
		void swap(stack& right) {
			Container* temp = m_pData;
			m_pData = right.m_pData;
			right.m_pData = temp;
		}
	#pragma endregion
	};
#pragma endregion
}