#pragma once

#include <string.h>
#include <stdlib.h>
#include <assert.h>

/// <summary>
/// 用于比较的回调函数
/// <para>*传入指针为空时报错*</para>
/// </summary>
/// <param name="p1">第一个传入值的指针</param>
/// <param name="p2">第二个传入值的指针</param>
/// <returns>大于0时执行交换 | 小于或等于0时不执行交换</returns>
typedef signed char compareFunc(void* p1, void* p2);

/// <summary>
/// 排序
/// </summary>
/// <param name="arr">数组</param>
/// <param name="arrCount">数据的数量</param>
/// <param name="singleDataSize">单个数据的大小</param>
/// <param name="comp">用于比较的回调函数</param>
typedef void sortFunc(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

/// <summary>
/// 交换
/// </summary>
/// <param name="size">数据的大小</param>
/// <param name="p1">数据1的地址</param>
/// <param name="p2">数据2的地址</param>
void swap(size_t size, void* p1, void* p2);

/// <summary>
/// 排序
/// </summary>
/// <param name="arr">数组</param>
/// <param name="arrCount">数据的数量</param>
/// <param name="singleDataSize">单个数据的大小</param>
/// <param name="comp">用于比较的回调函数</param>
void Sort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void InsertSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void SelectSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void BubbleSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);