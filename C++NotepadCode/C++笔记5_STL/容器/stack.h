#pragma once
#include "./vector.h"
#include <initializer_list>
namespace emansis {
#pragma region ջ
	/// <summary>
	/// ջ
	/// </summary>
	/// <typeparam name="T">�洢���ݵ�����</typeparam>
	/// <typeparam name="Container">�洢���ݵ�����</typeparam>
	template<class T, class Container = vector<T>>
	class stack {
	#pragma region ��Ա����
	private:
		Container* m_pData;	//���ڴ洢ջ���ݵ�����
	#pragma endregion
	#pragma region ��Ա����
	private:
		/// <summary>
		/// ��ʼ��ջ
		/// <para>*�ظ����ûᱨ��*</para>
		/// </summary>
		void initStack() {
			assert(!m_pData);
			m_pData = new Container();
		}
	public:
		/// <summary>
		/// ���캯�� ��ʼ��ջ
		/// </summary>
		stack() : m_pData(nullptr){
			initStack();
		}
		/// <summary>
		/// ��������
		/// <para>*�ռ䱻��ǰ�ͷŻᱨ��*</para>
		/// </summary>
		~stack() {
			assert(m_pData);
			delete m_pData;
		}
		/// <summary>
		///  ѹ��һ������
		/// </summary>
		/// <param name="value">����</param>
		void push(const T& value) {
			m_pData->push_back(value);
		}
		/// <summary>
		/// ����ջ������
		/// </summary>
		void pop() {
			m_pData->pop_back();
		}
		/// <summary>
		/// ��ȡջ������
		/// </summary>
		/// <returns>ջ�����ݵ�����</returns>
		T& top() {
			return m_pData->back();
		}
		/// <summary>
		/// ���ջ�Ƿ�Ϊ��ջ
		/// </summary>
		/// <returns>
		/// Ϊ�� : true
		///	<para>else : false</para>
		/// </returns>
		bool empty() {
			return m_pData->empty();
		}
		/// <summary>
		/// ��ȡջ�����ݵ�����
		/// </summary>
		/// <returns>ջ����Ч���ݵ�����</returns>
		size_t size() {
			return m_pData->size();
		}
		/// <summary>
		/// ������ջ����
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		void swap(stack& right) {
			Container* temp = m_pData;
			m_pData = right.m_pData;
			right.m_pData = temp;
		}
	#pragma endregion
	};
#pragma endregion
}