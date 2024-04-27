#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q) 
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	//申请与注入
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	newNode->_data = data;
	newNode->_next = NULL;

	//接驳
	q->_front = (q->_front != NULL) ? (q->_front) : (newNode);
	if (q->_rear != NULL)
	{
		q->_rear->_next = newNode;
	}
	q->_rear = newNode;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_front);
	QNode* delNode = q->_front;

	//节点值更新
	q->_front = q->_front->_next;
	q->_rear = (q->_rear != delNode) ? (q->_rear) : NULL;

	//空间回收
	free(delNode);
	delNode = NULL;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	QNode* curNode = q->_front;
	int size = 0;
	//遍历
	while (curNode != NULL)
	{
		curNode = curNode->_next;
		size++;
	}

	return size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return (int)(!!q->_front);
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	//循环遍历释放
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