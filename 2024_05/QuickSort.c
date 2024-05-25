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

static void g_funcQuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void QuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);
	
	g_funcQuickSort(arr, arrCount, singleDataSize, comp);
}

static void g_funcQuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	size_t subKey = 0;				//key值的坐标
	size_t left = 0;				//左指针下标
	size_t right = arrCount - 1;	//右指针下标

	//两端区域分离
	while (left < right)
	{
		//left步进
		while ((long long)left < (long long)right && comp((char*)arr + right * singleDataSize, (char*)arr + subKey * singleDataSize) >= 0)
		{
			right--;
		}
		//right步进
		while ((long long)left < (long long)right && comp((char*)arr + left * singleDataSize, (char*)arr + subKey * singleDataSize) <= 0)
		{
			left++;
		}
		//交换找出的值
		swap(singleDataSize, (char*)arr + left * singleDataSize, (char*)arr + right * singleDataSize);
	}
	//key值到中间
	swap(singleDataSize, (char*)arr + left * singleDataSize, (char*)arr + subKey * singleDataSize);
	subKey = left;

	//两端区域分别再次排序
	if (subKey > 0) {
		g_funcQuickSort(arr, subKey, singleDataSize, comp);
	}
	if (arrCount - subKey - 1 > 0) {
		g_funcQuickSort((char*)arr + (subKey + 1) * singleDataSize, arrCount - subKey - 1, singleDataSize, comp);
	}
}