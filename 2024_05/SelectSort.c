#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

void SelectSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);

	size_t i = 0;
	for (i = 0; i < arrCount; i++)
	{
		size_t j = 0;
		unsigned char ifExchange = 0;

		//选择最值，与数组内容交换
		void* seleValue = (char*)arr + ((arrCount - i - 1) * singleDataSize);

		for (j = 0; j < arrCount - i; j++) {
			if (comp(((char*)arr + (j * singleDataSize)), seleValue) > 0) 
			{
				seleValue = (char*)arr + (j * singleDataSize);
				ifExchange = 1;
			}
		}
		if (ifExchange != 0) 
		{
			swap(singleDataSize, seleValue, (char*)arr + (arrCount - i - 1) * singleDataSize);
		}
	}
}