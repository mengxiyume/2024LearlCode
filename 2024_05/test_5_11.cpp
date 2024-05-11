#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
using namespace std;
#include <string>
#include <cstdint>
#include <ctime>

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
		perror("data ����������k��");
		exit(-1);
	}

	//����,�Ѵ�СΪk
	memmove(buffer, data, k * sizeof(HPData));
	//���µ�������
	for (long long i = (k - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(k, buffer, i);
	}

	for (long long i = k - 1; i < srcSize; i++) {

		//�Ѷ�����
		if (buffer[0] < data[i]) {
			buffer[0] = data[i];
			AdjustDown(k, buffer, 0);
		}
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

//����һ������K�������ֵ���ļ�,��ʱʹ�üǵ�ɾ��
void CreateRandomTestFile_TopK(const char* filePath, size_t k) {
	FILE* randomFile = fopen(filePath, "wb");
	if (randomFile == nullptr) {
		perror("File Open Error\n");
		exit(-1);
	}
	srand(time(0));

	//��ֵ�����Լӽ������б�
	const HPData MaxValue = INT_MAX;
	const HPData MinValue = INT_MIN;
	//const HPData MaxValue = 5;
	//const HPData MinValue = -5;

	for (long long i = 0; i < k; i++) {
		//��������� - �޶���Χ
		int ran1 = rand();
		int ran2 = rand() % 31;
		int ran3 = ran2 != 0 ? (rand() % ran2) : 0;
		HPData randValue = (HPData)((((((long long)ran1 + i) << ran2 ) >> ran3) + rand() % 2) % ((long long)MaxValue + 1));
		randValue += rand() % 2 == 0 ? 0 : MinValue;
		//printf("ran1:%-10d <<%-5d >>%-5d randValue:%10d\n", ran1, ran2, ran3, randValue);

		//д���ļ�
		fwrite(&randValue, sizeof(randValue), 1, randomFile);
	}

	fclose(randomFile);
	randomFile = nullptr;
}

//topK����
void topkInputFromFile(size_t k, HPData* buffer, FILE* dataFile) {
	//����,�����л�ȡk������

	//�������ݲ���k��ʱ�˳�����
	HPData readValue = 0;
	for (long long i = 0; i < k; i++) {
		if (1 != fread(&readValue, sizeof(readValue), 1, dataFile)) {
			perror("data ����������k��");
			exit(-1);
		}
		buffer[i] = readValue;
	}
	//��k�����ݽ���
	for (long long i = (k - 1 - 1) / 2; i >= 0; i--) {
		//�ӵ�����һ����Ҷ�ӽڵ���ǰ�ߣ������µ�������
		AdjustDown(k, buffer, i);
	}

	//����������һ�ڶѶ��Ƚ�
	while (1 == fread(&readValue, sizeof(readValue), 1, dataFile)) {
		//��ȡֵ��������ʱ�滻�Ѷ����ݣ���������
		if (readValue > buffer[0]) {
			buffer[0] = readValue;
			AdjustDown(k, buffer, 0);
		}
	}
	//�������ݶ�ȡ���������
}

//��������
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