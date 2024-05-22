#define _CRT_SECURE_NO_WARNINGS

#include "./Sort.h"

//ϣ������

//Ԥ����	--	Ŀ�꣺�ӽ�����
//��������	--	����

//Ԥ���򣺷����������
//Ŀ��:��ĸ��컻�������λ�ã�С�������컻��ǰ���λ��
//gap = 3 ���Ϊgap�ķ�Ϊһ��

void ShellSort(void* arr, size_t arrCount, size_t singleDataSize, compareFunc* comp) {
	int gap = arrCount;
	while (gap > 1) {
		gap /= 2;
		//����log(N)�β������򣬼��gap

		size_t i = 0;
		for (i = 0; i < arrCount - gap; i++) {
			//���в������򣬷�gap��ֱ�����
			size_t end = i;
			int tmp = arr[end + gap];
			while (end + gap >= 0) {
				if (tmp < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
	//ϣ�������𽥽�������Ϊ���򣬲���������Խ�ӽ�����ʱЧ��Խ�ߣ�ʹ�����������������󻯲��������Ч������
}