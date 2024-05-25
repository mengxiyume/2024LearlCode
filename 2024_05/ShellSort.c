#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

//ϣ������

//Ԥ����	--	Ŀ�꣺�ӽ�����
//��������	--	����

//Ԥ���򣺷����������
//Ŀ��:��ĸ��컻�������λ�ã�С�������컻��ǰ���λ��
//gap = 3 ���Ϊgap�ķ�Ϊһ��

void ShellSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp)
{
	assert(arr);
	assert(arrCount);
	assert(singleDataSize);
	assert(comp);

	int gap = arrCount;
	void* tmp = malloc(singleDataSize);
	assert(tmp);
	while (gap > 1)
	{
		gap /= 2;
		//����log(N)�β������򣬼��gap

		size_t i = 0;
		for (i = 0; i < arrCount - gap; i++)
		{
			//���в������򣬷�gap��ֱ�����
			size_t end = i;

			//int tmp = arr[end + gap];
			memmove(tmp, ((char*)arr + (end + gap) * singleDataSize), singleDataSize);

			while (end + gap > 0 && end < (size_t)0 - gap) 
			{
				//if (tmp < arr[end]) {
				if (comp(tmp, (char*)arr + end * singleDataSize) <= 0)
				{

					//arr[end + gap] = arr[end];
					memmove((char*)arr + (end + gap) * singleDataSize, (char*)arr + end * singleDataSize, singleDataSize);
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//arr[end + gap] = tmp;
			memmove((char*)arr + (end + gap) * singleDataSize, tmp, singleDataSize);
		}
	}

	free(tmp);
	tmp = NULL;
	//ϣ�������𽥽�������Ϊ���򣬲���������Խ�ӽ�����ʱЧ��Խ�ߣ�ʹ�����������������󻯲��������Ч������
}