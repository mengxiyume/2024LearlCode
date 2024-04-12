#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//void exchange(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void revertArr(int* nums, int size) {
//    int i = 0;
//    for (i = 0; i < size / 2; i++) {
//        exchange(nums + i, nums + (size - i - 1));
//    }
//}
//
//void rotate(int* nums, int numsSize, int k) {
//
//    //原地法
//
//    k %= numsSize;
//
//    if (k != 0)
//    {
//        revertArr(nums + (numsSize - k), k);
//        revertArr(nums, numsSize - k);
//        if (numsSize > 2 || k % 2 == 1)
//        {
//            revertArr(nums, numsSize);
//        }
//    }
//
//}
//
//int main()
//{
//    int arr[] = { 1, 2 };
//    int k = 1;
//
//    rotate(arr, _countof(arr), k);
//    
//    int i = 0;
//    for (i = 0; i < _countof(arr); i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//}
//

/// <summary>
/// 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
/// </summary>
/// <returns></returns>

int missingNumber(int* nums, int numsSize) {
	
	int i = 0;
	int val = 0;
	for (i = 0; i < numsSize; i++)
	{
		val ^= nums[i];
		val ^= i;
	}
	val ^= numsSize;
	return val;
}

void test_0()
{
	int arr1[] = { 3, 0, 1 };
	int arr2[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };

	int i = 0;
	for (i = 0; i < _countof(arr1); i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n%d\n",missingNumber(arr1, _countof(arr1)));
	for (i = 0; i < _countof(arr2); i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n%d\n",missingNumber(arr2, _countof(arr2)));

}

//int main()
//{
//	test_0();
//}