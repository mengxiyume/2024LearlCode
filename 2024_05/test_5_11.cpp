#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
using namespace std;
#include <string>

//topK���⣬�öѽ��

typedef int HeapDataType, HPData;

void swap(HPData& a, HPData& b) {
	HPData tempValue = a;
	a = b;
	b = tempValue;
}

//С�������µ����㷨
void AdjustDown(size_t count, HPData* data, size_t position) {
	assert(count);
	assert(data);

	size_t parentPosition = position;
	size_t childPosition = parentPosition * 2 + 1;
	while (childPosition < count) {
		//�ҳ���ֵ��С���ӽڵ�
		if (childPosition + 1 < count &&
			data[childPosition + 1] < data[childPosition]) {
			childPosition++;
		}

		//�ӽڵ�ȸ��ڵ�Сʱ�Ե��ڵ���ֵ������ֹͣ����������
		if (data[childPosition] < data[parentPosition]) {
			//����
			swap(data[childPosition], data[parentPosition]);
			//����
			parentPosition = childPosition;
			childPosition = parentPosition * 2 + 1;
		}
		else {
			break;
		}
	}
}

//������ - ���� - ��С��
void _HeapSort(size_t count, HPData* arr) {
	assert(arr);
	assert(count);

	//������ֱ�ӽ��� - С����
	for (long long i = (count - 1 - 1) / 2; i >= 0; i--) {
		//���µ����㷨
		AdjustDown(count, arr, i);
	}

	//������Ѷ���С���ŵ�����λ��
	size_t back = count - 1;	//���һ��Ԫ�ص��±�

	while (back > 0) {
		//�����Ѷ���Ԫ��
		swap(arr[back], arr[0]);
		//���µ���ʣ�µĽṹ  - �ѵ����ݵ��±�պ���ʣ�¶ѽṹ�Ĵ�С
		AdjustDown(back, arr, 0);

		back--;
	}
}

//�ҳ�ǰ10�����ֵ
void topK(size_t k, HPData* buffer, size_t srcSize, const HPData* data) {
	//�Ҵ�ֵ����С�ѣ�������ѱȽ�
	assert(k);
	assert(buffer);
	assert(srcSize);
	assert(data);

	if (srcSize <= k) {
		memmove(buffer, data, srcSize * sizeof(HPData));
		return;
	}

	//����,�Ѵ�СΪk
	memmove(buffer, data, k * sizeof(HPData));
	//���µ�������
	for (long long i = (k - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(k, buffer, i);
	}

	for (long long i = k - 1; i < srcSize; i++) {
		buffer[0] = data[i];
		AdjustDown(k, buffer, 0);
	}
	//����
	//_HeapSort(k, buffer);
}

void test_topK_01() {
	const size_t arrSize = 255;
	size_t k = 10;
	HPData* arr = (HPData*)malloc(sizeof(HPData) * arrSize);
	HPData* buffer = (HPData*)malloc(sizeof(HPData) * k);
	assert(arr);
	assert(buffer);

	for (long long i = 0; i < arrSize; i++) {
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	putchar('\n');

	arr[123] = 445;
	arr[75] = 996;
	arr[210] = 888;
	arr[114] = 514;

	topK(k, buffer, arrSize, arr);
	_HeapSort(k, buffer);
	for (long long i = 0; i < k; i++) {
		printf("%d ", buffer[i]);
	}
	putchar('\n');

	free(arr);
	free(buffer);
}

int main() {
	test_topK_01();
	return 0;
}