#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
using namespace std;
#include <string>
#include <cstdint>
#include <ctime>

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
		perror("data 数据量不足k个");
		exit(-1);
	}

	//建堆,堆大小为k
	memmove(buffer, data, k * sizeof(HPData));
	//向下调整建堆
	for (long long i = (k - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(k, buffer, i);
	}

	for (long long i = k - 1; i < srcSize; i++) {

		//堆顶过滤
		if (buffer[0] < data[i]) {
			buffer[0] = data[i];
			AdjustDown(k, buffer, 0);
		}
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

//生成一个含有K个随机数值的文件,临时使用记得删除
void CreateRandomTestFile_TopK(const char* filePath, size_t k) {
	FILE* randomFile = fopen(filePath, "wb");
	if (randomFile == nullptr) {
		perror("File Open Error\n");
		exit(-1);
	}
	srand(time(0));

	//极值，可以加进参数列表
	const HPData MaxValue = INT_MAX;
	const HPData MinValue = INT_MIN;
	//const HPData MaxValue = 5;
	//const HPData MinValue = -5;

	for (long long i = 0; i < k; i++) {
		//随机数产生 - 限定范围
		int ran1 = rand();
		int ran2 = rand() % 31;
		int ran3 = ran2 != 0 ? (rand() % ran2) : 0;
		HPData randValue = (HPData)((((((long long)ran1 + i) << ran2 ) >> ran3) + rand() % 2) % ((long long)MaxValue + 1));
		randValue += rand() % 2 == 0 ? 0 : MinValue;
		//printf("ran1:%-10d <<%-5d >>%-5d randValue:%10d\n", ran1, ran2, ran3, randValue);

		//写入文件
		fwrite(&randValue, sizeof(randValue), 1, randomFile);
	}

	fclose(randomFile);
	randomFile = nullptr;
}

//topK本体
void topkInputFromFile(size_t k, HPData* buffer, FILE* dataFile) {
	//建堆,从流中获取k个数据

	//流中数据不足k个时退出程序
	HPData readValue = 0;
	for (long long i = 0; i < k; i++) {
		if (1 != fread(&readValue, sizeof(readValue), 1, dataFile)) {
			perror("data 数据量不足k个");
			exit(-1);
		}
		buffer[i] = readValue;
	}
	//将k个数据建堆
	for (long long i = (k - 1 - 1) / 2; i >= 0; i--) {
		//从倒数第一个非叶子节点向前走，并向下调整数据
		AdjustDown(k, buffer, i);
	}

	//流中数据逐一在堆顶比较
	while (1 == fread(&readValue, sizeof(readValue), 1, dataFile)) {
		//读取值满足条件时替换堆顶数据，并调整堆
		if (readValue > buffer[0]) {
			buffer[0] = readValue;
			AdjustDown(k, buffer, 0);
		}
	}
	//流中数据读取处理完结束
}

//辅助调用
void topkInputFromFile(size_t k, HPData* buffer, const char* filePath) {
	FILE* valueFile = fopen(filePath, "rb");
	if (valueFile == nullptr) {
		perror("File Open Error\n");
		exit(-1);
	}
	topkInputFromFile(k, buffer, valueFile);
	fclose(valueFile);
	valueFile = nullptr;

}

void test_topK_02() {
	size_t valueNum = (size_t)25536;
	const char* tempFileName = "./topkTempRandomTestFileHeapDataTypeIsInt.tmp";
	CreateRandomTestFile_TopK(tempFileName, valueNum);

	size_t k = 10;
	HPData* buffer = (HPData*)malloc(sizeof(HPData) * k);
	assert(buffer);

	//FILE* valueFile = fopen(tempFileName, "rb");
	//if (valueFile == nullptr) {
	//	perror("File Open Error\n");
	//	exit(-1);
	//}
	//topkInputFromFile(k, buffer, valueFile);
	//fclose(valueFile);
	//valueFile = nullptr;

	topkInputFromFile(k, buffer, tempFileName);
	_HeapSort(k, buffer);

	for (long long i = 0; i < k; i++) {
		printf("%d ", buffer[i]);
	}
	putchar('\n');

	free(buffer);
	buffer = nullptr;

	remove(tempFileName);
}

//int main() {
//	//test_topK_01();
//	test_topK_02();
//	return 0;
//}