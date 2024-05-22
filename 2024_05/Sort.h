#pragma once

#include <string.h>
#include <stdlib.h>
#include <assert.h>

/// <summary>
/// ���ڱȽϵĻص�����
/// <para>*����ָ��Ϊ��ʱ����*</para>
/// </summary>
/// <param name="p1">��һ������ֵ��ָ��</param>
/// <param name="p2">�ڶ�������ֵ��ָ��</param>
/// <returns>����0ʱִ�н��� | С�ڻ����0ʱ��ִ�н���</returns>
typedef signed char compareFunc(void* p1, void* p2);

/// <summary>
/// ����
/// </summary>
/// <param name="arr">����</param>
/// <param name="arrCount">���ݵ�����</param>
/// <param name="singleDataSize">�������ݵĴ�С</param>
/// <param name="comp">���ڱȽϵĻص�����</param>
typedef void sortFunc(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

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
void Sort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void InsertSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void SelectSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);

void BubbleSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp);