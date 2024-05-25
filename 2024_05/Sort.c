#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

/// <summary>
/// ����
/// </summary>
/// <param name="size">���ݵĴ�С</param>
/// <param name="p1">����1�ĵ�ַ</param>
/// <param name="p2">����2�ĵ�ַ</param>
void swap(size_t size, void* p1, void* p2)
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
		//��ֵ
		unsigned char tempData = *_1;
		*_1 = *_2;
		*_2 = tempData;
		//ָ����ƶ�
		_1++;
		_2++;
	}
}

void Sort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{	//TODO:д������֮����ѡһ��Ч�ʸߵĵ���
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);

	QuickSort(arr, arrCount, singleDataSize, comp);
}