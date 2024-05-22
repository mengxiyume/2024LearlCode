#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//typedef char BinaryTreeNodeDataType, BTData;
//
//typedef struct BinaryTreeNode {
//	BTData data;
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//}BTNode;
//
////双链表存储数据的类型
//typedef BTNode* DoubleLinkListDataType, * DLData;
//
//#pragma region 双链表
//
///// <summary>
///// 双链表类
///// <para>-结构-</para>
///// <para><seealso cref="node - 一个链表节点"/></para>
///// <para>-成员-</para>
///// <para><seealso cref="pushFront() - 头插"/></para>
///// <para><seealso cref="pushBack() - 尾插"/></para>
///// <para><seealso cref="insert() - 插入"/></para>
///// <para><seealso cref="popFront() - 头删"/></para>
///// <para><seealso cref="popBack() - 尾删"/></para>
///// <para><seealso cref="del() - 删除"/></para>
///// <para><seealso cref="getPos() - 获取指定节点"/></para>
///// <para><seealso cref="print() - 打印链表"/></para>
///// <para><seealso cref="m_pFront - 链表第一个有效节点"/></para>
///// <para><seealso cref="m_pBack - 链表最后一个有效节点"/></para>
///// <para><seealso cref="m_nSize - 链表有效节点的数量"/></para>
///// </summary>
//typedef class DoubleLinkList {
//	//这是一个双链表类
//public:
//
//	/// <summary>
//	/// 一个单链表节点
//	/// <para>-成员-</para>
//	/// <para><remarks>data - 节点存放的数据</remarks></para>
//	/// <para><remarks>next - 下一个节点的地址</remarks></para>
//	/// </summary>
//	typedef struct Node {
//		DLData data;		//节点存放的数据
//		struct Node* prev;	//上一个节点的地址
//		struct Node* next;	//下一个节点的地址
//	}Node, node;
//
//	/*----------------------------------------------//
//	* 请不要自行更改该指针指向的内容				//
//	* 表面值，更改不影响实际结构					//
//	* 调用内置函数更改结构后覆写 */					//
//	const node* m_pFront;	//链表第一个有效节点	//
//	const node* m_pBack;	//链表最后一个有效节点	//
//	size_t m_nSize;			//链表有效节点的数量	//
//	/*----------------------------------------------*/
//
//#pragma region 构造相关重载
//
//	DoubleLinkList();
//	~DoubleLinkList();
//
//#pragma endregion
//
//#pragma region 常规链表操作
//
//	/// <summary>
//	/// 从链表头部节点进行插入
//	/// </summary>
//	/// <param name="value">插入需要记录的值</param>
//	void pushFront(DLData value);
//	/// <summary>
//	/// 从链表尾部节点进行插入
//	/// </summary>
//	/// <param name="value">插入需要记录的值</param>
//	void pushBack(DLData value);
//	/// <summary>
//	/// 在指定节点前插入数据
//	/// <para>*节点无效时报错*</para>
//	/// </summary>
//	/// <param name="next">指定节点的指针 | nullptr 代表插入坐标第零个节点</param>
//	/// <param name="value">插入需要记录的值</param>
//	void insert(node* next, DLData value);
//	/// <summary>
//	/// 在指定坐标插入节点
//	/// <para>*坐标无效时报错*</para>
//	/// </summary>
//	/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
//	/// <param name="value">插入需要记录的值</param>
//	void insert(size_t position, DLData value);
//
//	/// <summary>
//	/// 删除链表头的第一个有效节点
//	/// <para>*无节点时报错*</para>
//	/// </summary>
//	void popFront();
//	/// <summary>
//	/// 删除链表的最后一个有效节点
//	/// <para>*无节点时报错*</para>
//	/// </summary>
//	void popBack();
//	/// <summary>
//	/// 删除指定节点
//	/// <para>*节点无效时报错*</para>
//	/// </summary>
//	/// <param name="delNode">指定节点的指针</param>
//	void del(node* delNode);
//	/// <summary>
//	/// 删除指定节点
//	/// <para>*坐标无效时报错*</para>
//	/// </summary>
//	/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
//	void del(size_t position);
//
//	///// <summary>
//	///// 获取当前链表的第一个有效节点
//	///// </summary>
//	///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
//	//node* getFront();
//	///// <summary>
//	///// 获取当前链表的最后一个有效节点
//	///// </summary>
//	///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
//	//node* getBack();
//
//	/// <summary>
//	/// 获取指定节点
//	/// </summary>
//	/// <param name="position">节点的坐标 /*以偏移量形式*/</param>
//	/// <returns>查找到的节点的指针 | 未查找到时返回nullptr</returns>
//	node* getPos(size_t position);
//
//	/// <summary>
//	/// 将链表中的内容打印
//	/// </summary>
//	void print();
//
//#pragma endregion
//
//private:
//
//	node* pHead = nullptr;			//链表头
//	size_t nodeCount = 0;			//链表有效节点的数量
//
//	/// <summary>
//	/// 申请一个链表节点
//	/// <para>*申请失败报错*</para>
//	/// </summary>
//	/// <returns>已申请的节点</returns>
//	node* buyOneNode();				//获取一个链表节点
//
//}DLList;
//
//#define assert_set(expression, str) (void)(                                          \
//            (!!(expression)) ||                                                      \
//            (_wassert(_CRT_WIDE(str), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
//        )
//
//#pragma region private
//
////将pop与push功能重复部分分离
//
///// <summary>
///// 申请一个链表节点
///// <para>*申请失败报错*</para>
///// </summary>
///// <returns>已申请的节点</returns>
//DLList::node* DLList::buyOneNode() {
//	DLList::node* temp = (DLList::node*)malloc(sizeof(DLList::node));
//	assert(temp);
//	return temp;
//}
//
//#pragma endregion
//
//#pragma region public
//
//#pragma region 构造相关重载
//
//DLList::DoubleLinkList() {
//	//头节点申请
//	pHead = buyOneNode();
//
//	//头节点循环链接初始化
//	pHead->next = pHead;
//	pHead->prev = pHead;
//
//	this->m_pFront = nullptr;
//	this->m_pBack = nullptr;
//	nodeCount = 0;
//	this->m_nSize = 0;
//}
//
//DLList::~DoubleLinkList() {
//	//断开循环链接
//	pHead->prev->next = nullptr;
//	pHead->prev = nullptr;
//
//	//迭代释放
//	node* curNode = pHead;
//
//	while (curNode != nullptr) {
//		//迭代释放
//		node* prevNode = curNode;
//		curNode = curNode->next;
//		free(prevNode);
//		prevNode = nullptr;
//	}
//
//	//指针归零
//	pHead = nullptr;
//	this->m_pFront = nullptr;
//	this->m_pBack = nullptr;
//	nodeCount = 0;
//	this->m_nSize = 0;
//}
//
//#pragma endregion
//
//#pragma region 常规链表操作
//
///// <summary>
///// 从链表头部节点进行插入
///// </summary>
///// <param name="value">插入需要记录的值</param>
//void DLList::pushFront(DLData value) {
//	//申请与注入
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//接驳链表
//	newNode->next = pHead->next;
//	newNode->prev = pHead;
//	pHead->next->prev = newNode;
//	pHead->next = newNode;
//
//	//表面值更新
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// 从链表尾部节点进行插入
///// </summary>
///// <param name="value">插入需要记录的值</param>
//void DLList::pushBack(DLData value) {
//	//申请与注入
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//接驳链表
//	newNode->next = pHead;
//	newNode->prev = pHead->prev;
//	pHead->prev->next = newNode;
//	pHead->prev = newNode;
//
//	//表面值更新
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// 在指定节点前插入数据
///// <para>*节点无效时报错*</para>
///// </summary>
///// <param name="next">指定节点的指针 | nullptr 代表插入坐标第零个节点</param>
///// <param name="value">插入需要记录的值</param>
//void DLList::insert(node* next, DLData value) {
//	//参数有效性检查
//	if (next != nullptr) {
//		//检查传入节点是否该链表的节点
//		node* curNode = pHead->next;
//		bool haveNode = false;
//		while (curNode != pHead) {
//			if (curNode == next)
//				haveNode = true;
//			curNode = curNode->next;
//		}
//		//非本链表节点无效
//		assert_set(haveNode, "传入节点无效");
//	}
//
//	//申请与注入
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//接驳链表
//	next = next != nullptr ? next : pHead;
//	newNode->next = next;
//	newNode->prev = next->prev;
//	next->prev->next = newNode;
//	next->prev = newNode;
//
//	//表面值更新
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// 在指定坐标插入节点
///// <para>*坐标无效时报错*</para>
///// </summary>
///// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
///// <param name="value">插入需要记录的值</param>
//void DLList::insert(size_t position, DLData value) {
//	//参数有效性检查
//	if (position > nodeCount) {
//		//越界无效
//		assert_set(0, "指定坐标无效");
//	}
//
//	//申请与注入
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//寻找坐标前一个节点
//	node* prev = getPos(position)->prev;
//
//	//接驳链表
//	prev = prev != nullptr ? prev : pHead;
//	newNode->prev = prev;
//	newNode->next = prev->next;
//	prev->next->prev = newNode;
//	prev->next = newNode;
//
//	//表面值更新
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
//
///// <summary>
///// 删除链表头的第一个有效节点
///// <para>*无节点时报错*</para>
///// </summary>
//void DLList::popFront() {
//	//有效性判断
//	assert_set(pHead->next != pHead, "无可删除节点");
//
//	node* delNode = pHead->next;
//	//节点剔除
//	pHead->next->next->prev = pHead;
//	pHead->next = delNode->next;
//
//	//回收占用空间
//	free(delNode);
//	delNode = nullptr;
//
//	//表面值更新
//	this->m_pFront = pHead->next != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->next != pHead ? pHead->prev : nullptr;
//	nodeCount--;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// 删除链表的最后一个有效节点
///// <para>*无节点时报错*</para>
///// </summary>
//void DLList::popBack() {
//	//有效性判断
//	assert_set(pHead->prev != pHead, "无可删除节点");
//
//	node* delNode = pHead->prev;
//	//节点剔除
//	pHead->prev->prev->next = pHead;
//	pHead->prev = delNode->prev;
//
//	//回收占用空间
//	free(delNode);
//	delNode = nullptr;
//
//	//表面值更新
//	this->m_pFront = pHead->prev != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->prev != pHead ? pHead->prev : nullptr;
//	m_nSize--;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// 删除指定节点
///// <para>*节点无效时报错*</para>
///// </summary>
///// <param name="delNode">指定节点的指针</param>
//void DLList::del(node* delNode) {
//	//参数有效性检查
//	assert_set(delNode, "传入节点无效");
//
//	//检查传入节点是否该链表的节点
//	bool haveNode = false;
//	node* curNode = pHead->next;
//	//非本链表节点无效
//	while (curNode != pHead) {
//		if (curNode == delNode)
//			haveNode = true;
//		curNode = curNode->next;
//	}
//	//该链表头节点无效
//	haveNode = (haveNode == false ? (delNode == pHead ? true : false) : haveNode);
//	assert_set(haveNode, "传入节点无效");
//
//	//节点剔除
//	delNode->prev->next = delNode->next;
//	delNode->next->prev = delNode->prev;
//
//	//回收占用空间
//	free(delNode);
//	delNode = nullptr;
//
//	//表面值更新
//	this->m_pFront = pHead->next != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->next != pHead ? pHead->prev : nullptr;
//	nodeCount--;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// 删除指定节点
///// <para>*坐标无效时报错*</para>
///// </summary>
///// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
//void DLList::del(size_t position) {
//	if (position > nodeCount) {
//		//越界无效
//		assert_set(0, "指定坐标无效");
//	}
//
//	//获取上一个节点的地址
//	node* delNode = getPos(position);
//
//	//节点剔除
//	delNode->prev->next = delNode->next;
//	delNode->next->prev = delNode->prev;
//
//	//回收占用空间
//	free(delNode);
//	delNode = nullptr;
//
//	//表面值更新
//	this->m_pFront = pHead->prev != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->prev != pHead ? pHead->prev : nullptr;
//	nodeCount--;
//	this->m_nSize = nodeCount;
//}
//
/////// <summary>
/////// 获取当前链表的第一个有效节点
/////// </summary>
/////// <returns>节点指针 | 无有效节点时返回nullptr</returns>
////DLList::node* DLList::getFront() {
////	return pHead->next;
////}
/////// <summary>
/////// 获取当前链表的最后一个有效节点
/////// </summary>
/////// <returns>节点指针 | 无有效节点时返回nullptr</returns>
////DLList::node* DLList::getBack() {
////	return pHead->prev;
////}
//
///// <summary>
///// 获取指定节点
///// </summary>
///// <param name="position">节点的坐标 /*以偏移量形式*/</param>
///// <returns>查找到的节点的指针 | 未查找到时返回nullptr</returns>
//DLList::node* DLList::getPos(size_t position) {
//	//参数有效性检查
//	if (position > nodeCount) {
//		//越界无效
//		return nullptr;
//	}
//
//	//循环访问查找pos节点
//	node* curNode = pHead->next;
//	for (size_t i = 0; i < position; i++) {
//		curNode = curNode->next;
//	}
//
//	return curNode;
//}
//
///// <summary>
///// 将链表中的内容打印
///// </summary>
//void DLList::print() {
//
//	if (pHead->next == pHead) {
//		//链表无内容时打印
//		std::cout << "null" << std::endl;
//		return;
//	}
//
//	//链表有内容时打印
//	std::cout << "null <- ";
//
//	node* curNode = pHead->next;
//	while (curNode != pHead) {
//		assert(curNode);	//这一行结构完整时不必要
//		std::cout << curNode->data;
//		curNode->next != pHead && std::cout << " <=> ";
//		curNode = curNode->next;
//	}
//
//	std::cout << " -> null" << std::endl;
//}
//
//#pragma endregion
//
//#pragma endregion
//
//#pragma endregion
//
////队列
//typedef class Queue {
//public:
//	DLList* data;
//	Queue() {
//		data = new DLList();
//	}
//	~Queue() {
//		data->~DoubleLinkList();
//		data = nullptr;
//	}
//	void push(BTNode* value) {
//		this->data->pushBack(value);
//	}
//	void pop() {
//		this->data->popFront();
//	}
//	BTNode* front() {
//		assert(this->data->m_nSize);
//		return (BTNode*)(this->data->getPos(0)->data);
//	}
//	bool empty() {
//		return !(this->data->m_nSize);
//	}
//}Queue;
//
///// <summary>
///// 前序遍历创建二叉树
///// </summary>
////<param name="fromateInitStringZero">以0结尾的格式化字符串</param>
////<param name="position">控制当前从字符串的第几个字符开始行动的数值的指针</param>
////<return>创建的树的根节点</return>
//BTNode* createBinTree(const char* fromateInitStringZero, size_t* position) {
//	//解析当前需要入队的字符
//	assert(fromateInitStringZero);
//
//	if (*fromateInitStringZero == '\0' || *(fromateInitStringZero + *position) == '\0') {
//		return NULL;
//	}
//
//	//根建立
//	char curData = *(fromateInitStringZero + *position);
//	(*position)++;
//	if (curData == '#') {
//		return NULL;
//	}
//
//	BTNode* newRootNode = (BTNode*)malloc(sizeof(BTNode));
//	assert(newRootNode);
//	newRootNode->data = curData;
//	newRootNode->left = NULL;
//	newRootNode->right = NULL;
//	if (*(fromateInitStringZero + *position) == '\0') {
//		return newRootNode;
//	}
//
//	//左子树建立
//	BTNode* newLeftRoot = createBinTree(fromateInitStringZero, position);
//	newRootNode->left = newLeftRoot;
//	if (*(fromateInitStringZero + *position) == '\0') {
//		return newRootNode;
//	}
//
//	//右子树建立
//	BTNode* newRightRoot = createBinTree(fromateInitStringZero, position);
//	newRootNode->right = newRightRoot;
//	if (*(fromateInitStringZero + *position) == '\0') {
//		return newRootNode;
//	}
//
//	//完成建立返回根节点
//	return newRootNode;
//}
//
////摧毁给定根及子树
//void destroyBinTree(BTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	destroyBinTree(root->left);
//	destroyBinTree(root->right);
//	//后序遍历摧毁树，方便
//	free(root);
//	//*root = NULL;
//}
//
//void preOrder(BTNode* root) {
//	if (root == nullptr) {
//		//printf("N ");
//		return;
//	}
//
//	printf("%c ", root->data);	//根
//	preOrder(root->left);		//左
//	preOrder(root->right);		//右
//}
//
////二叉树层序遍历
//void LevelOrder(BTNode* root) {
//	Queue* queue = new Queue();
//
//	if (root != nullptr) {
//		queue->push(root);
//	}
//	else {
//		delete(queue);
//		queue = nullptr;
//		return;
//	}
//
//	while (queue->empty() != true) {
//		//当前层出队
//		BTNode* front = queue->front();
//		queue->pop();
//
//		//打印空
//		if (front == nullptr) {
//			printf("N ");
//		}
//		else {
//			printf("%c ", front->data);
//			//下一层入队
//			queue->push(front->left);
//			queue->push(front->right);
//		}
//
//		////不打印空
//		//printf("%c ", front->data);
//		////下一层入队
//		//if (front->left != nullptr) {
//		//	queue->push(front->left);
//		//}
//		//if (front->right != nullptr) {
//		//	queue->push(front->right);
//		//}
//
//		front = nullptr;
//	}
//
//	delete(queue);
//	queue = nullptr;
//}
//
//void LevelOrderTest() {
//	char szBuffer[1024] = "123###457###6##";
//	size_t pos = 0;
//	BTNode* binTreeRoot = createBinTree(szBuffer, &pos);
//
//	preOrder(binTreeRoot);
//	putchar('\n');
//	LevelOrder(binTreeRoot);
//	putchar('\n');
//
//	destroyBinTree(binTreeRoot);
//	binTreeRoot = NULL;
//}
//
////完全二叉树
////层序遍历, 非完全二叉树的层序遍历不连续
//bool ComplateBinTree(BTNode* root) {
//	Queue* queue = new Queue();
//
//	if (root != nullptr) {
//		queue->push(root);
//	}
//	else {
//		delete(queue);
//		queue = nullptr;
//		//空树返回false
//		return false;
//	}
//
//	while (queue->empty() != true) {
//		//当前层出队
//		BTNode* front = queue->front();
//		queue->pop();
//
//		//遇到空节点退出循环
//		if (front == nullptr) {
//			break;
//		}
//		else {
//			//下一层入队
//			queue->push(front->left);
//			queue->push(front->right);
//		}
//
//		front = nullptr;
//	}
//	bool isComplate = true;
//	//监测剩余未遍历部分是否连续且为空
//	while (queue->empty() != true) {
//		BTNode* front = queue->front();
//		queue->pop();
//		if (front != nullptr) {
//			isComplate = false;
//			break;
//		}
//	}
//
//	delete(queue);
//	queue = nullptr;
//
//	return isComplate;
//}
//
//void ComplateTest() {
//	char szBuffer[1024] = "123##7##45##6##";
//	size_t pos = 0;
//	BTNode* binTreeRoot = createBinTree(szBuffer, &pos);
//
//	LevelOrder(binTreeRoot);
//	putchar('\n');
//	printf("isComplate:%d\n", ComplateBinTree(binTreeRoot));
//
//	destroyBinTree(binTreeRoot);
//	binTreeRoot = NULL;
//}

//排序
extern "C" {
	#include "./Sort.h"
}

typedef int testSortDataType;

signed char testCompFunc(void* p1, void* p2) {
	//return (*(testSortDataType*)p2) - (*(testSortDataType*)p1);		//	<	小于
	return (*(testSortDataType*)p1) - (*(testSortDataType*)p2);		//	>	大于
}

compareFunc* comp1 = testCompFunc;

void SortTest_01() {
	testSortDataType arr[] = { 39,8,9,6,4,12,5,2,1,10 };
	
	sort(arr, _countof(arr), sizeof(*arr), comp1);
	//SelectSort(arr, _countof(arr), sizeof(*arr), comp1);

	for (int i = 0; i < _countof(arr); i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int main() {
	//LevelOrderTest();
	//ComplateTest();
	SortTest_01();

	return 0;
}