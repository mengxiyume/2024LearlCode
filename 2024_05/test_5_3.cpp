#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

//����ϰ

//�ѵײ���Ծ���һ�����飬����Ѽ򵥶�����
/*
* ����ĳ���ڵ��ֵ���ǲ����ڻ�С���丸�ڵ��ֵ��
* ������һ����ȫ��������
* �ѵĸ��ڵ����ʱ�Ķѱ���Ϊ��ѻ����ѣ����ڵ���Сʱ��֮
*/

typedef int HeapDataType, HPData;

//FIXME:�һ����Ǻܻ������ã�֮�����Ż�
/// <summary>
/// ����������ֵ
/// <para>*����ָ����Ч����*</para>
/// </summary>
/// <param name="pValue1">ֵ1</param>
/// <param name="pValue2">ֵ2</param>
void swap(HPData* pValue1, HPData* pValue2) {
	assert(pValue1);
	assert(pValue2);

	HPData temp = *pValue1;
	*pValue1 = *pValue2;
	*pValue2 = temp;
}

//��������µ���
void bigBaseAdjustDown(size_t size, HPData* data, size_t position) {

	size_t parentPosition = 0;
	size_t childPosition = 0;

	parentPosition = position;
	childPosition = parentPosition * 2 + 1;		//��������
	while (childPosition < size) {

		//ѡ��С���ӽڵ�
		if (childPosition + 1 < size &&
			data[childPosition + 1] > data[childPosition]) {
			childPosition++;
		}

		//�ԱȽ������ӽ��
		if (data[childPosition] > data[parentPosition]) {
			//����
			swap(data + childPosition, data + parentPosition);

			//���ӵ���
			parentPosition = childPosition;
			childPosition = parentPosition * 2 + 1;
		}
		//����ʧ��ʱ����ҽ�������
		else {
			break;
		}
	}
}
//С�������µ���
void smallBaseAdjustDown(size_t size, HPData* data, size_t position) {

	size_t parentPosition = 0;
	size_t childPosition = 0;

	parentPosition = position;
	childPosition = parentPosition * 2 + 1;		//��������
	while (childPosition < size) {

		//ѡ��С���ӽڵ�
		if (childPosition + 1 < size &&
			data[childPosition + 1] < data[childPosition]) {
			childPosition++;
		}

		//�ԱȽ������ӽ��
		if (data[childPosition] < data[parentPosition]) {
			//����
			swap(data + childPosition, data + parentPosition);

			//���ӵ���
			parentPosition = childPosition;
			childPosition = parentPosition * 2 + 1;
		}
		//����ʧ��ʱ����ҽ�������
		else {
			break;
		}
	}
}

class Heap {
private:

#pragma region Values
	HPData* m_pData;
	size_t m_nSize;
	size_t m_nCapacity;
#pragma endregion

#pragma region �ڲ����ú���

	//TODO:�����㷨���Խ���ϣ�֮����Գ��Ը���

	/// <summary>
	///	С�� - ���ϵ����㷨
	///	<para>��childλ�ÿ�ʼ���ϵ���</para>
	/// <para>*û�нṹʱ���ñ���*</para>
	/// </summary>
	/// <param name="childPosition">�������ݵ�λ�� /*��ƫ������ʽ*/</param>
	void AdjustUp(size_t childPosition) {
		//������Ч�Լ��
		assert(this->m_pData);
		assert(childPosition <= this->m_nSize);

		size_t parentPosition = (childPosition - 1) / 2;

		//ѭ�����ϵ�����ֱ����ȫ����
		while ((childPosition != 0) && (
			this->m_pData[childPosition] < this->m_pData[parentPosition])) {
			swap(this->m_pData + childPosition, this->m_pData + parentPosition);
			childPosition = parentPosition;
			parentPosition = (childPosition - 1) / 2;
		}
	}

	/// <summary>
	///	С�� - ���µ����㷨
	///	<para>��parentλ�ÿ�ʼ���µ���</para>
	/// <para>*û�нṹʱ���ñ���*</para>
	/// </summary>
	/// <param name="parentPosition">�������ݵ�λ�� /*��ƫ������ʽ*/</param>
	void AdjustDown(size_t parentPosition) {
		//������Ч�Լ��
		assert(this->m_pData);
		assert(parentPosition <= this->m_nSize);

		//���µ���
		size_t childPosition = parentPosition * 2 + 1;	//�����±�
		while (childPosition < this->m_nSize) {

			//ѡ��С�ĺ���
			if ((childPosition + 1 < this->m_nSize) && 
				(this->m_pData[childPosition + 1] < this->m_pData[childPosition])) {
				childPosition++;
			}

			//�������ӽڵ�����
			if (this->m_pData[childPosition] < this->m_pData[parentPosition]) {
				swap(this->m_pData + childPosition, this->m_pData + parentPosition);

				//���ӵ���
				parentPosition = childPosition;
				childPosition = parentPosition * 2 + 1;
			}
			else {
				//������Ҷ�ڵ����
				break;
			}
		}
	}

#pragma endregion

public:

#pragma region �����������

	/// <summary>
	/// ����һ���ն�
	/// </summary>
	Heap() {
		this->m_pData = nullptr;
		this->m_nSize = 0;
		this->m_nCapacity = 0;
	}
	/// <summary>
	/// ����һ���ѣ��Բ����б�����ݹ���
	/// </summary>
	/// <param name="count">�����б���Ԫ�ص�����</param>
	/// <param name="arr">�����б�</param>
	Heap(size_t count, const HPData* arr) {

		//�ռ�����
		HPData* newData = (HPData*)malloc(sizeof(HPData) * count);
		assert(newData);
		//����¼�봦��
		this->m_pData = newData;
		this->m_nCapacity = count;
		this->m_nSize = count;
		memmove(this->m_pData, arr, count * sizeof(HPData));

		//���µ������� n-log(n) O(N)����������
		for (long long i = (this->m_nSize - 1 - 1) / 2; i >= 0; i--) {
			//size��һ��-1����β�ڵ��±꣬�ڶ���-1���Ҹ��ڵ�Ĳ��������Ϊ (size -1 -1) / 2
			//����ȫ�������ĵ�����һ����Ҷ�ӽڵ㿪ʼ��ǰ�ߣ������µ����ڵ�
			AdjustDown(i);
		}
	}

	/// <summary>
	/// ����ѿռ�
	/// </summary>
	~Heap() {
		if (this->m_pData != nullptr) {
			free(this->m_pData);
		}
		this->m_pData = nullptr;
		this->m_nSize = 0;
		this->m_nCapacity = 0;
	}

#pragma endregion

#pragma region �ѽṹ�ĳ������

	/// <summary>
	/// �Ѳ���
	/// </summary>
	/// <param name="value">�����ֵ</param>
	void push(HPData value) {
		//���Ӵ洢���±�λ�ù���: �����±� = (�����±� - 1) / 2;

		//�ռ����ˣ�����
		if (this->m_nSize == m_nCapacity) {
			size_t newCapacity = (this->m_nCapacity != 0) ? this->m_nCapacity * 2 : 4;
			HPData* newData = (HPData*)realloc(this->m_pData, sizeof(HPData) * newCapacity);
			assert(newData);
			this->m_pData		= newData;
			this->m_nCapacity	= newCapacity;
		}

		//���� + �������ݽṹ
		this->m_pData[this->m_nSize] = value;
		this->m_nSize++;
		AdjustUp(this->m_nSize - 1);
	}

	/// <summary>
	/// ɾ���Ѷ�������
	/// <para>*û�нṹʱ���ñ���*</para>
	/// </summary>
	void pop() {
		//������Ч�Լ��
		assert(this->m_nSize);
		assert(this->m_pData);

		//��β���ݽ�����ɾ��β������
		swap((this->m_pData + 0), (this->m_pData + this->m_nSize - 1));
		this->m_nSize--;

		//���µ���
		AdjustDown(0);
	}

	/// <summary>
	///	��ȡ�Ѷ�������	
	/// <para>*û�нṹʱ���ñ���*</para>
	/// </summary>
	/// <returns>���ضѶ�������</returns>
	HPData top() {
		//������Ч�Լ��
		assert(this->m_nSize);
		assert(this->m_pData);

		return this->m_pData[0];
	}

	/// <summary>
	/// ����Ԫ�صĸ���
	/// </summary>
	/// <returns>����Ԫ�صĸ���</returns>
	size_t size() {
		return this->m_nSize;
	}

	/// <summary>
	/// ���Ƿ�Ϊ��
	/// </summary>
	/// <returns>Ϊ���򷵻�true����֮����false</returns>
	bool isEmpty() {
		return (bool)!(this->m_nSize);
	}

	/// <summary>
	/// ��ӡ��
	/// </summary>
	void print() {
		string strBuffer;
		char szBuffer_data[1024];

		for (long long i = 0; i < this->m_nSize; i++) {
			sprintf(szBuffer_data, "%d ", this->m_pData[i]);
			strBuffer.append(szBuffer_data, strlen(szBuffer_data));
		}

		cout << strBuffer << endl;
	}

#pragma endregion

};

void heapTest_01() {

	Heap* heap = new Heap();
	
	for (int i = 0; i < 10; i++) {
		heap->push(i + 1);
	}
	heap->print();
	heap->pop();
	heap->print();
	cout << "top: " << heap->top() << " empty: " << heap->isEmpty() << " size: " << heap->size() << endl;

	delete(heap);
	heap = nullptr;
	printf("%p\n", heap);

}

//������ - ���� - �����
void HeapSort(size_t count, HPData* arr) {
	assert(arr);
	assert(count);

	//������ֱ�ӽ��� - �����
	for (long long i = (count - 1 - 1) / 2; i >= 0; i--) {
		//���µ����㷨
		bigBaseAdjustDown(count, arr, i);
	}

	//������Ѷ��Ĵ����ŵ�����λ��
	size_t back = count - 1;	//���һ��Ԫ�ص��±�

	while (back > 0) {
		//�����Ѷ���Ԫ��
		swap(arr + back, arr);
		//���µ���ʣ�µĽṹ  - �ѵ����ݵ��±�պ���ʣ�¶ѽṹ�Ĵ�С
		bigBaseAdjustDown(back, arr, 0);

		back--;
	}
}

void testHeapSort() {
	int arr[] = { 9, 372, 7, 6, 968, 4, 3, 2, 1, 0 };

	HeapSort(_countof(arr), arr);

	for (int i = 0; i < _countof(arr); i++) {
		printf("%d ", arr[i]);
	}

	putchar('\n');
}

//int main() {
//
//	//heapTest_01();
//	testHeapSort();
//
//	return 0;
//}