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

const static void g_funcQuickSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	size_t subKey = 0;				//keyֵ������
	size_t left = 0;				//��ָ���±�
	size_t right = arrCount - 1;	//��ָ���±�

	//�����������
	while (left < right)
	{
		//left����
		while (left < right && comp((char*)arr + right * singleDataSize, (char*)arr + subKey * singleDataSize) >= 0)
			right--;
		//right����
		while (left < right && comp((char*)arr + left * singleDataSize, (char*)arr + subKey * singleDataSize) <= 0)
			left++;
		//�����ҳ���ֵ
		swap(singleDataSize, (char*)arr + left * singleDataSize, (char*)arr + right * singleDataSize);
	}
	//keyֵ���м�
	swap(singleDataSize, (char*)arr + left * singleDataSize, (char*)arr + subKey * singleDataSize);
	subKey = left;

	//��������ֱ��ٴ�����
	if (subKey > 0)
		g_funcQuickSort(arr, subKey, singleDataSize, comp);
	if (arrCount - subKey - 1 > 0)
		g_funcQuickSort((char*)arr + (subKey + 1) * singleDataSize, arrCount - subKey - 1, singleDataSize, comp);
}