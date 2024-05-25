#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

void BubbleSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);

	size_t i = 0;
	for (i = 0; i < arrCount - 1; i++) 
	{
		size_t j = 0;
		unsigned char ifExchange = 0;
		for (j = 1; j < arrCount - i; j++)
		{
			if (comp(((char*)arr) + (j - 1) * singleDataSize, ((char*)arr) + j * singleDataSize) > 0) 
			{
				swap(singleDataSize, ((char*)arr) + (j - 1) * singleDataSize, ((char*)arr) + j * singleDataSize);
				ifExchange = 1;
			}
		}
		if (ifExchange == 0) 
		{
			break;
			//return;
		}
	}
}