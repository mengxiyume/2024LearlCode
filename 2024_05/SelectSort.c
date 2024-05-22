#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

void SelectSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	char* posArr = (char*)arr;
	size_t i = 0;
	for (i = 0; i < arrCount; i++)
	{
		size_t j = 0;
		void* end = posArr + ((arrCount - 1 - i) * singleDataSize);
		for (j = 0; j < arrCount - i - 1; j++)
		{
			//比较和换内容
			void* cur = posArr + (j * singleDataSize);
			if (comp(end, cur) <= 0)
			{
				swap(singleDataSize, end, cur);
			}
		}
	}
}