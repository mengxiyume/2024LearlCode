#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"


/************��������************
* 	����1��
*	�ô����������һ��ֵ��Ϊ�ؼ�ֵKey��ʹ�ö�����ǰ������ķ�ʽ�Դ�����������б�������
*	˫ָ�룬left��right���ƣ�leftѰ�ұ�key�����ֵ��rightѰ�ұ�keyС����ֵ��Ѱ�Ҽ�ֵ������
*	rightָ�����У�������ָ������֮ǰ�����ҵ���Ӧֵ��ָ��ֹͣѰ�ң�����ָ����ҵ���Ӧֵ����������
*	����ָ������ʱ����key��leftָ������ݣ����˵���ǰ�򲿷���ɣ�key���ƶ�������ȷ��λ�ã�key��ߵ�ֵС�ڻ����key���ұߵĴ��ڻ����key
*	�����������ٴηֱ����ͬ���Ĳ���,ֱ���ݹ������ɣ���������
*/

/* ���������ٽ���������ʱ����һֱ����������ʱ�临�Ӷ�O(N)
*	�������ÿ�ζ������������ܹ���ʱ�临�Ӷ����� O(N*logN)
*	���ѡkey������ȡ������Ա���ÿ�ζ�ѡ������	//RANDOME!!!
*		�������ָ��key��������left�ԱȺ��������������ͬ
*		�õ���ͷ���м��Լ���β��Ԫ�أ�ȡ�м�ֵ��left��������������ͬ
*	****- ����̫���ˣ��������_202405260215am -****
*/

const static void g_funcQuickSort_Hoare(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);
const static void g_funcQuickSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp);

void QuickSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);
	
	g_funcQuickSort(arr, arrCount, singleDataSize, comp);
}

const static size_t g_funcGetMidNumPos(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp)
{
	//ȡ�м���
	size_t leftPos = 0;
	size_t midPos = arrCount / 2;
	size_t rightPos = arrCount;

	//��ȫ�ȷ����м�ֵ
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
	//ȫ���Ĭ�Ϸ�����Ԫ��
	return 0;
}

//ǰ��ָ�뷨
/*
* ��ʼʱprevָ��ָ�����п�ͷcurָ��ָ��prevָ��ĺ�һ��λ��
* Ȼ���ж�curָ��ָ��������Ƿ�С��key����С��key����prev����һλ������cur��prevָ������ݻ�����Ȼ��curָ��++
* ���curָ������ݴ���key����cur++����
* ��curԽ��ʱ����prevָ���������key���н���
* ������ɵ��������Զ�����������ʽ������������
*/
const static void g_funcQuickSort(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp)
{
	size_t subKey = 0;
	size_t prev = 0;
	size_t cur = prev + 1;
	//����ȡ��
	size_t midPos = g_funcGetMidNumPos(arr, arrCount, singleDataSize, comp);
	swap(singleDataSize, arr, (char*)arr + midPos * singleDataSize);
	subKey = 0;

	//���˱���
	while (cur < arrCount)
	{
		//�ѱ�key�����ֵ������
		//�ѱ�keyС����ֵ��ǰ��
		//if (arr[cur] < arr[subKey])
		//if (comp((char*)arr + cur, (char*)arr + subKey) < 0)
		if (comp((char*)arr + cur, arr) < 0)
		{
			prev++;
			//swap(arr + cur, arr + prev);
			//����cur��prev��ʹ��key���ֵ������Ŀ���λ��
			swap(singleDataSize, (char*)arr + cur * singleDataSize, (char*)arr + prev * singleDataSize);
		}
		//ÿ�ζԱ����ۺ������curָ�붼Ҫ����ƶ�1��λ
		cur++;
	}
	//swap(arr + subKey, arr + prev);
	//��ɵ��������keyֵ�ŵ��м䣬key��λ�þ��ҵ���
	//swap(singleDataSize, (char*)arr + subKey * singleDataSize, (char*)arr + prev * singleDataSize);
	swap(singleDataSize, arr, (char*)arr + prev * singleDataSize);

	//ʣ�����������
	g_funcQuickSort(arr, prev, singleDataSize, comp);
	g_funcQuickSort((char*)arr + prev + 1, arrCount - prev - 1 , singleDataSize, comp);
}

//ԭ��
const static void g_funcQuickSort_Hoare(void* arr, const size_t arrCount, const size_t singleDataSize, const compareFunc* comp)
{
	size_t subKey = 0;				//keyֵ������
	size_t leftPos = 0;				//��ָ���±�
	size_t rightPos = arrCount - 1;	//��ָ���±�

	size_t midPos = g_funcGetMidNumPos(arr, arrCount, singleDataSize, comp);
	swap(singleDataSize, (char*)arr + leftPos * singleDataSize, (char*)arr + midPos * singleDataSize);

	//�����������
	while (leftPos < rightPos)
	{
		//left����
		while (leftPos < rightPos && comp((char*)arr + rightPos * singleDataSize, (char*)arr + subKey * singleDataSize) >= 0)
			rightPos--;
		//right����
		while (leftPos < rightPos && comp((char*)arr + leftPos * singleDataSize, (char*)arr + subKey * singleDataSize) <= 0)
			leftPos++;
		//�����ҳ���ֵ
		swap(singleDataSize, (char*)arr + leftPos * singleDataSize, (char*)arr + rightPos * singleDataSize);
	}
	//keyֵ���м�
	swap(singleDataSize, (char*)arr + leftPos * singleDataSize, (char*)arr + subKey * singleDataSize);
	subKey = leftPos;

	//��������ֱ��ٴ�����
	if (subKey > 0)
		g_funcQuickSort_Hoare(arr, subKey, singleDataSize, comp);
	if (arrCount - subKey - 1 > 0)
		g_funcQuickSort_Hoare((char*)arr + (subKey + 1) * singleDataSize, arrCount - subKey - 1, singleDataSize, comp);
}