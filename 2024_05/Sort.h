#pragma once

#include <string.h>
#include <stdlib.h>
#include <assert.h>

/// <summary>
/// ���ڱȽϵĻص�����
/// <para>���ز���һ��������Ĺ�ϵֵ</para>
/// <para>*����ָ��Ϊ��ʱ����*</para>
/// </summary>
/// <param name="p1">��һ������ֵ��ָ��</param>
/// <param name="p2">�ڶ�������ֵ��ָ��</param>
/// <returns>
/// <para>a &lt; b : ret &lt; 0</para>
/// <para>a = b : ret = 0</para>
/// <para>a &gt; b : ret &gt; 0</para>
/// </returns>
typedef signed char compareFunc(const void* p1, const void* p2);

/// <summary>
/// ����
/// </summary>
/// <param name="arr">����</param>
/// <param name="arrCount">���ݵ�����</param>
/// <param name="singleDataSize">�������ݵĴ�С</param>
/// <param name="comp">���ڱȽϵĻص�����</param>
typedef void sortFunc(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);

/// <summary>
/// ����
/// </summary>
/// <param name="size">���ݵĴ�С</param>
/// <param name="p1">����1�ĵ�ַ</param>
/// <param name="p2">����2�ĵ�ַ</param>
void swap(size_t size, void* p1, void* p2);

/// <summary>
/// ����
/// </summary>
/// <param name="arr">����</param>
/// <param name="arrCount">���ݵ�����</param>
/// <param name="singleDataSize">�������ݵĴ�С</param>
/// <param name="comp">���ڱȽϵĻص�����</param>
void Sort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);

void InsertSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);

void SelectSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);

void BubbleSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);

void ShellSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);

void QuickSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);