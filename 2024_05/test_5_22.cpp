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
////˫����洢���ݵ�����
//typedef BTNode* DoubleLinkListDataType, * DLData;
//
//#pragma region ˫����
//
///// <summary>
///// ˫������
///// <para>-�ṹ-</para>
///// <para><seealso cref="node - һ������ڵ�"/></para>
///// <para>-��Ա-</para>
///// <para><seealso cref="pushFront() - ͷ��"/></para>
///// <para><seealso cref="pushBack() - β��"/></para>
///// <para><seealso cref="insert() - ����"/></para>
///// <para><seealso cref="popFront() - ͷɾ"/></para>
///// <para><seealso cref="popBack() - βɾ"/></para>
///// <para><seealso cref="del() - ɾ��"/></para>
///// <para><seealso cref="getPos() - ��ȡָ���ڵ�"/></para>
///// <para><seealso cref="print() - ��ӡ����"/></para>
///// <para><seealso cref="m_pFront - �����һ����Ч�ڵ�"/></para>
///// <para><seealso cref="m_pBack - �������һ����Ч�ڵ�"/></para>
///// <para><seealso cref="m_nSize - ������Ч�ڵ������"/></para>
///// </summary>
//typedef class DoubleLinkList {
//	//����һ��˫������
//public:
//
//	/// <summary>
//	/// һ��������ڵ�
//	/// <para>-��Ա-</para>
//	/// <para><remarks>data - �ڵ��ŵ�����</remarks></para>
//	/// <para><remarks>next - ��һ���ڵ�ĵ�ַ</remarks></para>
//	/// </summary>
//	typedef struct Node {
//		DLData data;		//�ڵ��ŵ�����
//		struct Node* prev;	//��һ���ڵ�ĵ�ַ
//		struct Node* next;	//��һ���ڵ�ĵ�ַ
//	}Node, node;
//
//	/*----------------------------------------------//
//	* �벻Ҫ���и��ĸ�ָ��ָ�������				//
//	* ����ֵ�����Ĳ�Ӱ��ʵ�ʽṹ					//
//	* �������ú������Ľṹ��д */					//
//	const node* m_pFront;	//�����һ����Ч�ڵ�	//
//	const node* m_pBack;	//�������һ����Ч�ڵ�	//
//	size_t m_nSize;			//������Ч�ڵ������	//
//	/*----------------------------------------------*/
//
//#pragma region �����������
//
//	DoubleLinkList();
//	~DoubleLinkList();
//
//#pragma endregion
//
//#pragma region �����������
//
//	/// <summary>
//	/// ������ͷ���ڵ���в���
//	/// </summary>
//	/// <param name="value">������Ҫ��¼��ֵ</param>
//	void pushFront(DLData value);
//	/// <summary>
//	/// ������β���ڵ���в���
//	/// </summary>
//	/// <param name="value">������Ҫ��¼��ֵ</param>
//	void pushBack(DLData value);
//	/// <summary>
//	/// ��ָ���ڵ�ǰ��������
//	/// <para>*�ڵ���Чʱ����*</para>
//	/// </summary>
//	/// <param name="next">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
//	/// <param name="value">������Ҫ��¼��ֵ</param>
//	void insert(node* next, DLData value);
//	/// <summary>
//	/// ��ָ���������ڵ�
//	/// <para>*������Чʱ����*</para>
//	/// </summary>
//	/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
//	/// <param name="value">������Ҫ��¼��ֵ</param>
//	void insert(size_t position, DLData value);
//
//	/// <summary>
//	/// ɾ������ͷ�ĵ�һ����Ч�ڵ�
//	/// <para>*�޽ڵ�ʱ����*</para>
//	/// </summary>
//	void popFront();
//	/// <summary>
//	/// ɾ����������һ����Ч�ڵ�
//	/// <para>*�޽ڵ�ʱ����*</para>
//	/// </summary>
//	void popBack();
//	/// <summary>
//	/// ɾ��ָ���ڵ�
//	/// <para>*�ڵ���Чʱ����*</para>
//	/// </summary>
//	/// <param name="delNode">ָ���ڵ��ָ��</param>
//	void del(node* delNode);
//	/// <summary>
//	/// ɾ��ָ���ڵ�
//	/// <para>*������Чʱ����*</para>
//	/// </summary>
//	/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
//	void del(size_t position);
//
//	///// <summary>
//	///// ��ȡ��ǰ����ĵ�һ����Ч�ڵ�
//	///// </summary>
//	///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
//	//node* getFront();
//	///// <summary>
//	///// ��ȡ��ǰ��������һ����Ч�ڵ�
//	///// </summary>
//	///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
//	//node* getBack();
//
//	/// <summary>
//	/// ��ȡָ���ڵ�
//	/// </summary>
//	/// <param name="position">�ڵ������ /*��ƫ������ʽ*/</param>
//	/// <returns>���ҵ��Ľڵ��ָ�� | δ���ҵ�ʱ����nullptr</returns>
//	node* getPos(size_t position);
//
//	/// <summary>
//	/// �������е����ݴ�ӡ
//	/// </summary>
//	void print();
//
//#pragma endregion
//
//private:
//
//	node* pHead = nullptr;			//����ͷ
//	size_t nodeCount = 0;			//������Ч�ڵ������
//
//	/// <summary>
//	/// ����һ������ڵ�
//	/// <para>*����ʧ�ܱ���*</para>
//	/// </summary>
//	/// <returns>������Ľڵ�</returns>
//	node* buyOneNode();				//��ȡһ������ڵ�
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
////��pop��push�����ظ����ַ���
//
///// <summary>
///// ����һ������ڵ�
///// <para>*����ʧ�ܱ���*</para>
///// </summary>
///// <returns>������Ľڵ�</returns>
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
//#pragma region �����������
//
//DLList::DoubleLinkList() {
//	//ͷ�ڵ�����
//	pHead = buyOneNode();
//
//	//ͷ�ڵ�ѭ�����ӳ�ʼ��
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
//	//�Ͽ�ѭ������
//	pHead->prev->next = nullptr;
//	pHead->prev = nullptr;
//
//	//�����ͷ�
//	node* curNode = pHead;
//
//	while (curNode != nullptr) {
//		//�����ͷ�
//		node* prevNode = curNode;
//		curNode = curNode->next;
//		free(prevNode);
//		prevNode = nullptr;
//	}
//
//	//ָ�����
//	pHead = nullptr;
//	this->m_pFront = nullptr;
//	this->m_pBack = nullptr;
//	nodeCount = 0;
//	this->m_nSize = 0;
//}
//
//#pragma endregion
//
//#pragma region �����������
//
///// <summary>
///// ������ͷ���ڵ���в���
///// </summary>
///// <param name="value">������Ҫ��¼��ֵ</param>
//void DLList::pushFront(DLData value) {
//	//������ע��
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//�Ӳ�����
//	newNode->next = pHead->next;
//	newNode->prev = pHead;
//	pHead->next->prev = newNode;
//	pHead->next = newNode;
//
//	//����ֵ����
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// ������β���ڵ���в���
///// </summary>
///// <param name="value">������Ҫ��¼��ֵ</param>
//void DLList::pushBack(DLData value) {
//	//������ע��
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//�Ӳ�����
//	newNode->next = pHead;
//	newNode->prev = pHead->prev;
//	pHead->prev->next = newNode;
//	pHead->prev = newNode;
//
//	//����ֵ����
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// ��ָ���ڵ�ǰ��������
///// <para>*�ڵ���Чʱ����*</para>
///// </summary>
///// <param name="next">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
///// <param name="value">������Ҫ��¼��ֵ</param>
//void DLList::insert(node* next, DLData value) {
//	//������Ч�Լ��
//	if (next != nullptr) {
//		//��鴫��ڵ��Ƿ������Ľڵ�
//		node* curNode = pHead->next;
//		bool haveNode = false;
//		while (curNode != pHead) {
//			if (curNode == next)
//				haveNode = true;
//			curNode = curNode->next;
//		}
//		//�Ǳ�����ڵ���Ч
//		assert_set(haveNode, "����ڵ���Ч");
//	}
//
//	//������ע��
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//�Ӳ�����
//	next = next != nullptr ? next : pHead;
//	newNode->next = next;
//	newNode->prev = next->prev;
//	next->prev->next = newNode;
//	next->prev = newNode;
//
//	//����ֵ����
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// ��ָ���������ڵ�
///// <para>*������Чʱ����*</para>
///// </summary>
///// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
///// <param name="value">������Ҫ��¼��ֵ</param>
//void DLList::insert(size_t position, DLData value) {
//	//������Ч�Լ��
//	if (position > nodeCount) {
//		//Խ����Ч
//		assert_set(0, "ָ��������Ч");
//	}
//
//	//������ע��
//	node* newNode = buyOneNode();
//	newNode->data = value;
//
//	//Ѱ������ǰһ���ڵ�
//	node* prev = getPos(position)->prev;
//
//	//�Ӳ�����
//	prev = prev != nullptr ? prev : pHead;
//	newNode->prev = prev;
//	newNode->next = prev->next;
//	prev->next->prev = newNode;
//	prev->next = newNode;
//
//	//����ֵ����
//	this->m_pFront = pHead->next;
//	this->m_pBack = pHead->prev;
//	nodeCount++;
//	this->m_nSize = nodeCount;
//}
//
///// <summary>
///// ɾ������ͷ�ĵ�һ����Ч�ڵ�
///// <para>*�޽ڵ�ʱ����*</para>
///// </summary>
//void DLList::popFront() {
//	//��Ч���ж�
//	assert_set(pHead->next != pHead, "�޿�ɾ���ڵ�");
//
//	node* delNode = pHead->next;
//	//�ڵ��޳�
//	pHead->next->next->prev = pHead;
//	pHead->next = delNode->next;
//
//	//����ռ�ÿռ�
//	free(delNode);
//	delNode = nullptr;
//
//	//����ֵ����
//	this->m_pFront = pHead->next != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->next != pHead ? pHead->prev : nullptr;
//	nodeCount--;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// ɾ����������һ����Ч�ڵ�
///// <para>*�޽ڵ�ʱ����*</para>
///// </summary>
//void DLList::popBack() {
//	//��Ч���ж�
//	assert_set(pHead->prev != pHead, "�޿�ɾ���ڵ�");
//
//	node* delNode = pHead->prev;
//	//�ڵ��޳�
//	pHead->prev->prev->next = pHead;
//	pHead->prev = delNode->prev;
//
//	//����ռ�ÿռ�
//	free(delNode);
//	delNode = nullptr;
//
//	//����ֵ����
//	this->m_pFront = pHead->prev != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->prev != pHead ? pHead->prev : nullptr;
//	m_nSize--;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// ɾ��ָ���ڵ�
///// <para>*�ڵ���Чʱ����*</para>
///// </summary>
///// <param name="delNode">ָ���ڵ��ָ��</param>
//void DLList::del(node* delNode) {
//	//������Ч�Լ��
//	assert_set(delNode, "����ڵ���Ч");
//
//	//��鴫��ڵ��Ƿ������Ľڵ�
//	bool haveNode = false;
//	node* curNode = pHead->next;
//	//�Ǳ�����ڵ���Ч
//	while (curNode != pHead) {
//		if (curNode == delNode)
//			haveNode = true;
//		curNode = curNode->next;
//	}
//	//������ͷ�ڵ���Ч
//	haveNode = (haveNode == false ? (delNode == pHead ? true : false) : haveNode);
//	assert_set(haveNode, "����ڵ���Ч");
//
//	//�ڵ��޳�
//	delNode->prev->next = delNode->next;
//	delNode->next->prev = delNode->prev;
//
//	//����ռ�ÿռ�
//	free(delNode);
//	delNode = nullptr;
//
//	//����ֵ����
//	this->m_pFront = pHead->next != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->next != pHead ? pHead->prev : nullptr;
//	nodeCount--;
//	this->m_nSize = nodeCount;
//}
///// <summary>
///// ɾ��ָ���ڵ�
///// <para>*������Чʱ����*</para>
///// </summary>
///// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
//void DLList::del(size_t position) {
//	if (position > nodeCount) {
//		//Խ����Ч
//		assert_set(0, "ָ��������Ч");
//	}
//
//	//��ȡ��һ���ڵ�ĵ�ַ
//	node* delNode = getPos(position);
//
//	//�ڵ��޳�
//	delNode->prev->next = delNode->next;
//	delNode->next->prev = delNode->prev;
//
//	//����ռ�ÿռ�
//	free(delNode);
//	delNode = nullptr;
//
//	//����ֵ����
//	this->m_pFront = pHead->prev != pHead ? pHead->next : nullptr;
//	this->m_pBack = pHead->prev != pHead ? pHead->prev : nullptr;
//	nodeCount--;
//	this->m_nSize = nodeCount;
//}
//
/////// <summary>
/////// ��ȡ��ǰ����ĵ�һ����Ч�ڵ�
/////// </summary>
/////// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
////DLList::node* DLList::getFront() {
////	return pHead->next;
////}
/////// <summary>
/////// ��ȡ��ǰ��������һ����Ч�ڵ�
/////// </summary>
/////// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
////DLList::node* DLList::getBack() {
////	return pHead->prev;
////}
//
///// <summary>
///// ��ȡָ���ڵ�
///// </summary>
///// <param name="position">�ڵ������ /*��ƫ������ʽ*/</param>
///// <returns>���ҵ��Ľڵ��ָ�� | δ���ҵ�ʱ����nullptr</returns>
//DLList::node* DLList::getPos(size_t position) {
//	//������Ч�Լ��
//	if (position > nodeCount) {
//		//Խ����Ч
//		return nullptr;
//	}
//
//	//ѭ�����ʲ���pos�ڵ�
//	node* curNode = pHead->next;
//	for (size_t i = 0; i < position; i++) {
//		curNode = curNode->next;
//	}
//
//	return curNode;
//}
//
///// <summary>
///// �������е����ݴ�ӡ
///// </summary>
//void DLList::print() {
//
//	if (pHead->next == pHead) {
//		//����������ʱ��ӡ
//		std::cout << "null" << std::endl;
//		return;
//	}
//
//	//����������ʱ��ӡ
//	std::cout << "null <- ";
//
//	node* curNode = pHead->next;
//	while (curNode != pHead) {
//		assert(curNode);	//��һ�нṹ����ʱ����Ҫ
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
////����
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
///// ǰ���������������
///// </summary>
////<param name="fromateInitStringZero">��0��β�ĸ�ʽ���ַ���</param>
////<param name="position">���Ƶ�ǰ���ַ����ĵڼ����ַ���ʼ�ж�����ֵ��ָ��</param>
////<return>���������ĸ��ڵ�</return>
//BTNode* createBinTree(const char* fromateInitStringZero, size_t* position) {
//	//������ǰ��Ҫ��ӵ��ַ�
//	assert(fromateInitStringZero);
//
//	if (*fromateInitStringZero == '\0' || *(fromateInitStringZero + *position) == '\0') {
//		return NULL;
//	}
//
//	//������
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
//	//����������
//	BTNode* newLeftRoot = createBinTree(fromateInitStringZero, position);
//	newRootNode->left = newLeftRoot;
//	if (*(fromateInitStringZero + *position) == '\0') {
//		return newRootNode;
//	}
//
//	//����������
//	BTNode* newRightRoot = createBinTree(fromateInitStringZero, position);
//	newRootNode->right = newRightRoot;
//	if (*(fromateInitStringZero + *position) == '\0') {
//		return newRootNode;
//	}
//
//	//��ɽ������ظ��ڵ�
//	return newRootNode;
//}
//
////�ݻٸ�����������
//void destroyBinTree(BTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	destroyBinTree(root->left);
//	destroyBinTree(root->right);
//	//��������ݻ���������
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
//	printf("%c ", root->data);	//��
//	preOrder(root->left);		//��
//	preOrder(root->right);		//��
//}
//
////�������������
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
//		//��ǰ�����
//		BTNode* front = queue->front();
//		queue->pop();
//
//		//��ӡ��
//		if (front == nullptr) {
//			printf("N ");
//		}
//		else {
//			printf("%c ", front->data);
//			//��һ�����
//			queue->push(front->left);
//			queue->push(front->right);
//		}
//
//		////����ӡ��
//		//printf("%c ", front->data);
//		////��һ�����
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
////��ȫ������
////�������, ����ȫ�������Ĳ������������
//bool ComplateBinTree(BTNode* root) {
//	Queue* queue = new Queue();
//
//	if (root != nullptr) {
//		queue->push(root);
//	}
//	else {
//		delete(queue);
//		queue = nullptr;
//		//��������false
//		return false;
//	}
//
//	while (queue->empty() != true) {
//		//��ǰ�����
//		BTNode* front = queue->front();
//		queue->pop();
//
//		//�����սڵ��˳�ѭ��
//		if (front == nullptr) {
//			break;
//		}
//		else {
//			//��һ�����
//			queue->push(front->left);
//			queue->push(front->right);
//		}
//
//		front = nullptr;
//	}
//	bool isComplate = true;
//	//���ʣ��δ���������Ƿ�������Ϊ��
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

//����
extern "C" {
	#include "./Sort.h"
}

typedef int testSortDataType;

signed char testCompFunc(void* p1, void* p2) {
	//return (*(testSortDataType*)p2) - (*(testSortDataType*)p1);		//	<	С��
	return (*(testSortDataType*)p1) - (*(testSortDataType*)p2);		//	>	����
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