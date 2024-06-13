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

const static void g_funcQuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
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
		g_funcQuickSort(arr, subKey, singleDataSize, comp);
	if (arrCount - subKey - 1 > 0)
		g_funcQuickSort((char*)arr + (subKey + 1) * singleDataSize, arrCount - subKey - 1, singleDataSize, comp);
}