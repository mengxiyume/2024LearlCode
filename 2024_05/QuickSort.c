#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"


/************快速排序************
* 	方法1：
*	用待排序数组第一个值作为关键值Key，使用二叉树前序遍历的方式对待排序数组进行遍历排序
*	双指针，left与right控制，left寻找比key大的数值，right寻找比key小的数值，寻找极值，可逆
*	right指针先行，在两个指针相遇之前，若找到对应值则指针停止寻找，两个指针均找到对应值交换其内容
*	两个指针相遇时调换key与left指针的内容，至此单次前序部分完成，key被移动到了正确的位置，key左边的值小于或等于key，右边的大于或等于key
*	对两个区间再次分别进行同样的操作,直到递归遍历完成，数组有序
*/

/* 快排在面临近有序数组时容易一直处理最坏情况，时间复杂度O(N)
*	如果并非每次都是最坏情况，则能够将时间复杂度拉到 O(N*logN)
*	随机选key或三数取中则可以避免每次都选择最坏情况	//RANDOME!!!
*		用随机数指定key，将其与left对比后调换，后流程相同
*		拿到开头，中间以及结尾的元素，取中间值与left调换，后流程相同
*	****- 今晚太累了，明天继续_202405260215am -****
*/

const static void g_funcQuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void QuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);
	
	g_funcQuickSort(arr, arrCount, singleDataSize, comp);
}

const static size_t g_funcGetMidNumPos(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	//取中间数
	size_t leftPos = 0;
	size_t midPos = arrCount / 2;
	size_t rightPos = arrCount;

	//不全等返回中间值
	if (comp((char*)arr + leftPos * singleDataSize, (char*)arr + rightPos * singleDataSize) < 0)
	{
		if (comp((char*)arr + midPos * singleDataSize, (char*)arr + rightPos * singleDataSize) < 0)
		{
			return midPos;
		}
		else if (comp((char*)arr + rightPos * singleDataSize, (char*)arr + leftPos * singleDataSize) < 0)
		{
			return rightPos;
		}
	}
	else
	{
		if (midPos > rightPos)
		if (comp((char*)arr + midPos * singleDataSize, (char*)arr + rightPos * singleDataSize) > 0)
		{
			return midPos;
		}
		else if (comp((char*)arr + rightPos * singleDataSize, (char*)arr + leftPos * singleDataSize) > 0)
		{
			return leftPos;
		}
	}
	//全相等默认返回首元素
	return 0;
}

const static void g_funcQuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	size_t subKey = 0;				//key值的坐标
	size_t leftPos = 0;				//左指针下标
	size_t rightPos = arrCount - 1;	//右指针下标

	size_t midPos = g_funcGetMidNumPos(arr, arrCount, singleDataSize, comp);
	swap(singleDataSize, (char*)arr + leftPos * singleDataSize, (char*)arr + midPos * singleDataSize);

	//两端区域分离
	while (leftPos < rightPos)
	{
		//left步进
		while (leftPos < rightPos && comp((char*)arr + rightPos * singleDataSize, (char*)arr + subKey * singleDataSize) >= 0)
			rightPos--;
		//right步进
		while (leftPos < rightPos && comp((char*)arr + leftPos * singleDataSize, (char*)arr + subKey * singleDataSize) <= 0)
			leftPos++;
		//交换找出的值
		swap(singleDataSize, (char*)arr + leftPos * singleDataSize, (char*)arr + rightPos * singleDataSize);
	}
	//key值到中间
	swap(singleDataSize, (char*)arr + leftPos * singleDataSize, (char*)arr + subKey * singleDataSize);
	subKey = leftPos;

	//两端区域分别再次排序
	if (subKey > 0)
		g_funcQuickSort(arr, subKey, singleDataSize, comp);
	if (arrCount - subKey - 1 > 0)
		g_funcQuickSort((char*)arr + (subKey + 1) * singleDataSize, arrCount - subKey - 1, singleDataSize, comp);
}