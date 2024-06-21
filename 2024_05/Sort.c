#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

/// <summary>
/// 交换
/// </summary>
/// <param name="size">数据的大小</param>
/// <param name="p1">数据1的地址</param>
/// <param name="p2">数据2的地址</param>
void swap(size_t size, const void* p1, const void* p2)
{
	assert(size);
	assert(p1);
	assert(p2);

	if (p1 == p2)
		return;

	unsigned char* _1 = p1;
	unsigned char* _2 = p2;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		//换值
		unsigned char tempData = *_1;
		*_1 = *_2;
		*_2 = tempData;
		//指针段移动
		_1++;
		_2++;
	}
}

void Sort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp)
{	//TODO:写好排序之后再选一个效率高的调用
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);

	QuickSort(arr, arrCount, singleDataSize, comp);
}