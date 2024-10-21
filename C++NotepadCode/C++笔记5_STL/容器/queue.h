#pragma once
#include "./List.h"
namespace emansis {
#pragma region ����
	template<class T, class Container = list<T>>
	class queue {
	#pragma region ��Ա����
	private:
		Container* m_pData;		//������ݵ�����
	#pragma endregion
	#pragma region ��Ա����
	private:
		/// <summary>
		/// ��ʼ������
		/// <para>*�ظ����ûᱨ��*</para>
		/// </summary>
		void initQueue() {
			assert(!m_pData);
			m_pData = new Container();
		}
	public:
		/// <summary>
		/// ���캯�� ��ʼ������
		/// </summary>
		queue() : m_pData(nullptr){
			initQueue();
		}
		/// <summary>
		/// ��������
		/// <para>*�ռ䱻��ǰ�ͷŻᱨ��*</para>
		/// </summary>
		~queue() {
			assert(m_pData);
			delete m_pData;
		}
		/// <summary>
		/// �������Ƿ�Ϊ��
		/// </summary>
		/// <returns>
		/// Ϊ�� : true;
		/// <para>else : false</para>
		/// </returns>
		bool empty() {
			return m_pData->empty();
		}
		/// <summary>
		/// ��ȡ�����ڵ����ݸ���
		/// </summary>
		/// <returns>��������Ч���ݵ�����</returns>
		size_t size() {
			return m_pData->size();
		}
		/// <summary>
		/// ��ȡ��ͷ��Ԫ��
		/// </summary>
		/// <returns>����ͷ��������</returns>
		T& front() {
			return *(m_pData->begin());
		}
		/// <summary>
		/// ��ȡ��β��Ԫ��
		/// </summary>
		/// <returns>����β��������</returns>
		T& back() {
			return *(--(m_pData->end()));
		}
		/// <summary>
		/// �ڶ���β������һ������
		/// </summary>
		/// <param name="value">Ҫ���������</param>
		void push(const T& value) {
			m_pData->push_back(value);
		}
		/// <summary>
		/// ɾ����ͷ������
		/// </summary>
		void pop() {
			m_pData->erase(m_pData->begin());
		}
		/// <summary>
		/// �����������е�����
		/// </summary>
		/// <param name="right">�Ҳ�����</param>
		void swap(queue& right) {
			Container* temp = m_pData;
			m_pData = right.m_pData;
			right.m_pData = temp;
		}
	#pragma endregion
	};
#pragma endregion
}