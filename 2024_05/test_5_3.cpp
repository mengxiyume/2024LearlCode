#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

//堆练习

//堆底层可以就是一个数组，数组堆简单而抽象
/*
* 堆中某个节点的值总是不大于或不小于其父节点的值；
* 堆总是一棵完全二叉树。
* 堆的根节点最大时的堆被称为大堆或大根堆，跟节点最小时反之
*/

typedef int HeapDataType, HPData;

class Heap {
private:

#pragma region Values
	HPData* m_pData;
	size_t m_nSize;
	size_t m_nCapacity;
#pragma endregion

	//我还不是很会用引用，之后在优化
	/// <summary>
	/// 调换两个数值
	/// <para>*传入指针无效报错*</para>
	/// </summary>
	/// <param name="pValue1">值1</param>
	/// <param name="pValue2">值2</param>
	void swap(HPData* pValue1, HPData* pValue2) {
		assert(pValue1);
		assert(pValue2);

		HPData temp = *pValue1;
		*pValue1 = *pValue2;
		*pValue2 = temp;
	}

	/// <summary>
	///	小堆 - 向上调整算法
	///	<para>从child位置开始向上调整</para>
	/// <para>*没有结构时调用报错*</para>
	/// </summary>
	/// <param name="childPosition">调整数据的位置 /*以偏移量形式*/</param>
	void AdjustUp(size_t childPosition) {
		//操作有效性检查
		assert(this->m_pData);
		assert(childPosition <= this->m_nSize);

		size_t parentPosition = (childPosition - 1) / 2;

		//循环向上调整，直至完全调整
		while ((childPosition != 0) && (this->m_pData[childPosition] < this->m_pData[parentPosition])) {
			swap(this->m_pData + childPosition, this->m_pData + parentPosition);
			childPosition = parentPosition;
			parentPosition = (childPosition - 1) / 2;
		}
	}

	/// <summary>
	///	小堆 - 向下调整算法
	///	<para>从parent位置开始向下调整</para>
	/// <para>*没有结构时调用报错*</para>
	/// </summary>
	/// <param name="parentPosition">调整数据的位置 /*以偏移量形式*/</param>
	void AdjustDown(size_t parentPosition) {
		//操作有效性检查
		assert(this->m_pData);
		assert(parentPosition <= this->m_nSize);

		//向下调整
		size_t childPosition = parentPosition * 2 + 1;
		while (childPosition < this->m_nSize) {

			//选出小的孩子
			if ((childPosition + 1 < this->m_nSize) && 
				(this->m_pData[childPosition + 1] < this->m_pData[childPosition])) {
				childPosition++;
			}

			//交换父子节点数据
			if (this->m_pData[childPosition] < this->m_pData[parentPosition]) {
				swap(this->m_pData + childPosition, this->m_pData + parentPosition);
				parentPosition = childPosition;
				childPosition = parentPosition * 2 + 1;
			}
			else {
				//交换至叶节点结束
				break;
			}
		}
	}

public:

#pragma region 构造相关重载

	Heap() {
		this->m_pData = nullptr;
		this->m_nSize = 0;
		this->m_nCapacity = 0;
	}
	~Heap() {
		if (this->m_pData != nullptr) {
			free(this->m_pData);
		}
		this->m_pData = nullptr;
		this->m_nSize = 0;
		this->m_nCapacity = 0;
	}

#pragma endregion

#pragma region 堆结构的常规操作

	/// <summary>
	/// 堆插入
	/// </summary>
	/// <param name="value">需插入值</param>
	void push(HPData value) {
		//父子存储的下标位置规律: 父亲下标 = (孩子下标 - 1) / 2;

		//空间满了，扩容
		if (this->m_nSize == m_nCapacity) {
			size_t newCapacity = (this->m_nCapacity != 0) ? this->m_nCapacity * 2 : 4;
			HPData* newData = (HPData*)realloc(this->m_pData, sizeof(HPData) * newCapacity);
			assert(newData);
			this->m_pData		= newData;
			this->m_nCapacity	= newCapacity;
		}

		//插入 + 调整数据结构
		this->m_pData[this->m_nSize] = value;
		this->m_nSize++;
		AdjustUp(this->m_nSize - 1);
	}

	/// <summary>
	/// 删除堆顶的数据
	/// <para>*没有结构时调用报错*</para>
	/// </summary>
	void pop() {
		//操作有效性检查
		assert(this->m_nSize);
		assert(this->m_pData);

		//首尾数据交换，删除尾部数据
		swap((this->m_pData + 0), (this->m_pData + this->m_nSize - 1));
		this->m_nSize--;

		//向下调整
		AdjustDown(0);
	}

	/// <summary>
	///	获取堆顶的数据	
	/// <para>*没有结构时调用报错*</para>
	/// </summary>
	/// <returns>返回堆顶的数据</returns>
	HPData top() {
		//操作有效性检查
		assert(this->m_nSize);
		assert(this->m_pData);

		return this->m_pData[0];
	}

	/// <summary>
	/// 堆中元素的个数
	/// </summary>
	/// <returns>堆中元素的个数</returns>
	size_t size() {
		return this->m_nSize;
	}

	/// <summary>
	/// 堆是否为空
	/// </summary>
	/// <returns>为空则返回true，反之返回false</returns>
	bool isEmpty() {
		return (bool)!(this->m_nSize);
	}

	/// <summary>
	/// 打印堆
	/// </summary>
	void print() {
		string strBuffer;
		char szBuffer_data[1024];

		for (int i = 0; i < this->m_nSize; i++) {
			sprintf(szBuffer_data, "%d ", this->m_pData[i]);
			strBuffer.append(szBuffer_data, strlen(szBuffer_data));
		}

		cout << strBuffer << endl;
	}

#pragma endregion

};

int main() {

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

	return 0;
}