#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

//希尔排序

//预排序	--	目标：接近有序
//插入排序	--	有序

//预排序：分组插入排序
//目标:大的更快换到后面的位置，小的数更快换到前面的位置
//gap = 3 间距为gap的分为一组

void ShellSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp) {
	int gap = arrCount;
	while (gap > 1) {
		gap /= 2;
		//进行log(N)次插入排序，间隔gap

		size_t i = 0;
		for (i = 0; i < arrCount - gap; i++) {
			//进行插入排序，分gap组分别排序
			size_t end = i;
			int tmp = arr[end + gap];
			while (end + gap >= 0) {
				if (tmp < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
	//希尔排序逐渐将数组排为有序，插入排序在越接近有序时效率越高，使数组分组且逐渐有序，最大化插入排序的效率优势
}