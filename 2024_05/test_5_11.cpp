#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
using namespace std;
#include <string>

//topK问题，用堆解决

typedef int HeapDataType, HPData;

void swap(HPData& a, HPData& b) {
	HPData tempValue = a;
	a = b;
	b = tempValue;
}

//小根堆向下调整算法
void AdjustDown(size_t count, HPData* data, size_t position) {
	assert(count);
	assert(data);

	size_t parentPosition = position;
	size_t childPosition = parentPosition * 2 + 1;
	while (childPosition < count) {
		//找出数值较小的子节点
		if (childPosition + 1 < count &&
			data[childPosition + 1] < data[childPosition]) {
			childPosition++;
		}

		//子节点比父节点小时对调节点数值，否则停止调整并结束
		if (data[childPosition] < data[parentPosition]) {
			//调换
			swap(data[childPosition], data[parentPosition]);
			//迭代
			parentPosition = childPosition;
			childPosition = parentPosition * 2 + 1;
		}
		else {
			break;
		}
	}
}

//堆排序 - 降序 - 建小堆
void _HeapSort(size_t count, HPData* arr) {
	assert(arr);
	assert(count);

	//将数组直接建堆 - 小根堆
	for (long long i = (count - 1 - 1) / 2; i >= 0; i--) {
		//向下调整算法
		AdjustDown(count, arr, i);
	}

	//逐个将堆顶的小数放到后排位置
	size_t back = count - 1;	//最后一个元素的下标

	while (back > 0) {
		//交换堆顶底元素
		swap(arr[back], arr[0]);
		//向下调整剩下的结构  - 堆底数据的下标刚好是剩下堆结构的大小
		AdjustDown(back, arr, 0);

		back--;
	}
}

//找出前10大的数值
void topK(size_t k, HPData* buffer, size_t srcSize, const HPData* data) {
	//找大值，建小堆，逐个进堆比较
	assert(k);
	assert(buffer);
	assert(srcSize);
	assert(data);

	if (srcSize <= k) {
		memmove(buffer, data, srcSize * sizeof(HPData));
		return;
	}

	//建堆,堆大小为k
	memmove(buffer, data, k * sizeof(HPData));
	//向下调整建堆
	for (long long i = (k - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(k, buffer, i);
	}

	for (long long i = k - 1; i < srcSize; i++) {
		buffer[0] = data[i];
		AdjustDown(k, buffer, 0);
	}
	//排序
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