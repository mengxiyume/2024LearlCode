#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

//希尔排序

//预排序	--	目标：接近有序
//插入排序	--	有序

//预排序：分组插入排序
//目标:大的更快换到后面的位置，小的数更快换到前面的位置
//gap = 3 间距为gap的分为一组

void ShellSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);

	int gap = arrCount;
	void* tmp = malloc(singleDataSize);
	assert(tmp);
	while (gap > 1)
	{
		gap /= 2;
		//进行log(N)次插入排序，间隔gap

		size_t i = 0;
		for (i = 0; i < arrCount - gap; i++)
		{
			//进行插入排序，分gap组分别排序
			size_t end = i;

			//int tmp = arr[end + gap];
			memmove(tmp, ((char*)arr + (end + gap) * singleDataSize), singleDataSize);

			while (end + gap > 0 && end < (size_t)0 - gap) 
			{
				//if (tmp < arr[end]) {
				if (comp(tmp, (char*)arr + end * singleDataSize) <= 0)
				{

					//arr[end + gap] = arr[end];
					memmove((char*)arr + (end + gap) * singleDataSize, (char*)arr + end * singleDataSize, singleDataSize);
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//arr[end + gap] = tmp;
			memmove((char*)arr + (end + gap) * singleDataSize, tmp, singleDataSize);
		}
	}

	free(tmp);
	tmp = NULL;
	//希尔排序逐渐将数组排为有序，插入排序在越接近有序时效率越高，使数组分组且逐渐有序，最大化插入排序的效率优势
}