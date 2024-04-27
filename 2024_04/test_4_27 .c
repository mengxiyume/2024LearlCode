#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q) 
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	//������ע��
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	newNode->_data = data;
	newNode->_next = NULL;

	//�Ӳ�
	q->_front = (q->_front != NULL) ? (q->_front) : (newNode);
	if (q->_rear != NULL)
	{
		q->_rear->_next = newNode;
	}
	q->_rear = newNode;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_front);
	QNode* delNode = q->_front;

	//�ڵ�ֵ����
	q->_front = q->_front->_next;
	q->_rear = (q->_rear != delNode) ? (q->_rear) : NULL;

	//�ռ����
	free(delNode);
	delNode = NULL;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	QNode* curNode = q->_front;
	int size = 0;
	//����
	while (curNode != NULL)
	{
		curNode = curNode->_next;
		size++;
	}

	return size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return (int)(!!q->_front);
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	//ѭ�������ͷ�
	assert(q);

	QNode* curNode = q->_front;
	while (curNode != NULL)
	{
		QNode* delNode = curNode;
		curNode = curNode->_next;
		free(delNode);
		delNode = NULL;
	}

	q->_front = NULL;
	q->_rear = NULL;
}

void QueueTest_01()
{
	Queue q1;
	QueueInit(&q1);

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		QueuePush(&q1, i + 1);
		printf("%d ", QueueBack(&q1));
	}
	printf("\nsize:%d\n", QueueSize(&q1));
	while (QueueEmpty(&q1))
	{
		printf("%d ", QueueFront(&q1));
		QueuePop(&q1);
	}
	printf("\nsize:%d\n", QueueSize(&q1));


	QueueDestroy(&q1);
}

int main() {

	QueueTest_01();

	return 0;
}