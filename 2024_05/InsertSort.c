#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

void InsertSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);

	int i = 0;
	void* tmp = malloc(singleDataSize);
	assert(tmp);
	for (i = 0; i < arrCount - 1; i++)
	{
		size_t end = i;
		memmove(tmp, ((char*)arr) + (end + 1) * singleDataSize, singleDataSize);

		while (end + 1 >= 0)
		{

			if (comp(tmp, (char*)arr + end * singleDataSize) <= 0)
			{
				//当前数据放到后面
				memmove((char*)arr + (end + 1) * singleDataSize, (char*)arr + end * singleDataSize, singleDataSize);
				--end;
			}
			else
			{
				break;
			}
		}
		//当前数据放到前面
		memmove(((char*)arr) + (end + 1) * singleDataSize, tmp, singleDataSize);
	}
	free(tmp);
	tmp = NULL;
}