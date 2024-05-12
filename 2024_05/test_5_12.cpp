#define _CRT_SECURE_NO_WARNINGS\

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>


//��ʽ������

/*
* ���������� ��
*	ǰ�� -	������������������
*	���� -	������������������
*	���� -	������������������
* 
*	���� -	ÿ��˳�����
*/

typedef class BinaryTree {
public:
#pragma region �ṹ�弰��������
	typedef int BinaryTreeNodeDataType, BTData;
	//���ڵ�
	typedef struct BinaryTreeNode {
		BTData data;
		BinaryTreeNode*	left;	//��������ַ
		BinaryTreeNode*	right;	//��������ַ
	}BTNode, node;
	size_t size;				//��Ч�ڵ������
	size_t depth;				//�������
#pragma endregion

#pragma region �����������
	BinaryTree() {
		this->m_nSize = 0;
		this->size = this->m_nSize;
		this->m_nDepth = 0;
		this->depth = this->m_nDepth;
		this->m_pTopNode = nullptr;
	}

	~BinaryTree() {
		//����ɾ���ṹ
		treeDestroy(this->m_pTopNode);
		this->m_pTopNode = nullptr;

		//��¼����
		this->m_nSize = 0;
		this->size = this->m_nSize;
		this->m_nDepth = 0;
		this->depth = this->m_nDepth;
	}
#pragma endregion

#pragma region �������������
	void preOrder() {
		preOrder(this->m_pTopNode);
		putchar('\n');
	}
	void inOrder() {
		inOrder(this->m_pTopNode);
		putchar('\n');
	}
	void postOrder() {
		postOrder(this->m_pTopNode);
		putchar('\n');
	}

	//����
	size_t reSize() {
		size_t newSize = getTreeSize(this->m_pTopNode);
		this->m_nSize = newSize;
		this->size = this->m_nSize;
		return this->size;
	}
	//���
	size_t reDepth() {
		size_t newDepth = getTreeDepth(this->m_pTopNode);
		this->m_nDepth = newDepth;
		this->depth = this->m_nDepth;
		return this->depth;
	}

	size_t getLevelNodeCount(size_t k) {
		return treeKLevelNodeCount(this->m_pTopNode, k);
	}
#pragma endregion

	void BinTreeTestFunc();

private:
#pragma region �ڲ�����
	node* m_pTopNode;		//���ڵ�
	size_t	m_nSize;		//��Ч�ڵ������
	size_t m_nDepth;		//�������
#pragma endregion

#pragma region �ڲ���������

	//��ȡһ���ڵ�Ŀռ䲢��ʼ��
	node* ByeOneNode(BTData value) {
		//�ռ�����
		node* newNode = (node*)malloc(sizeof(node));
		assert(newNode);
		//��ʼ����ע��
		newNode->data = value;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}

	size_t getTreeSize(node* pNode) {
		//�ݹ�ͳ�����нڵ�
		//�սڵ㲻ͳ��
		if (pNode == nullptr) {
			return 0;
		}
		//����ͳ�����
		size_t leftValue = getTreeSize(pNode->left);
		size_t rightValue = getTreeSize(pNode->right);
		return 1 + leftValue + rightValue;
	}

	//���
	size_t getTreeDepth(node* pNode) {
		//�ݹ�ͳ�����нڵ�
		//�սڵ㲻ͳ��
		if (pNode == nullptr) {
			return 0;
		}
		//ͳ��������������
		size_t leftValue = getTreeDepth(pNode->left);
		size_t rightValue = getTreeDepth(pNode->right);
		return 1 + (leftValue > rightValue ? leftValue : rightValue);
	}

	size_t treeKLevelNodeCount(node* pNode, size_t k) {
		//���������k����
		//�������սڵ�
		if (pNode == nullptr) {
			return 0;
		}
		//������Ŀ��ڵ�
		else if (k == 1) {
			return 1;
		}
		//Ŀ��ڵ��ϲ�ڵ㣬������ȡͳ������
		size_t leftValue = treeKLevelNodeCount(pNode->left, k - 1);
		size_t rightValue = treeKLevelNodeCount(pNode->right, k - 1);
		size_t sum = leftValue + rightValue;
		return sum;
	}

	//��������ݻ�
	void treeDestroy(node* pTop) {
		//TODO:�ݻ���

		if (pTop == nullptr) {
			return;
		}

		//�ݻ������������ٴݻ��Լ�
		treeDestroy(pTop->left);
		treeDestroy(pTop->right);
		free(pTop);
		pTop = nullptr;
	}

	//����
	void preOrder(node* pNode) {
		if (pNode == nullptr) {
			printf("N ");
			return;
		}

		printf("%d ", pNode->data);	//��
		preOrder(pNode->left);		//��
		preOrder(pNode->right);		//��
	}

	void inOrder(node* pNode) {
		if (pNode == nullptr) {
			printf("N ");
			return;
		}

		inOrder(pNode->left);		//��
		printf("%d ", pNode->data);	//��
		inOrder(pNode->right);		//��
	}

	void postOrder(node* pNode) {
		if (pNode == nullptr) {
			printf("N ");
			return;
		}

		postOrder(pNode->left);		//��
		postOrder(pNode->right);	//��
		printf("%d ", pNode->data);	//��
	}

	////�������
	//void levelOrder(node* pNode) {
	//	//�սڵ����N
	//	if (pNode == nullptr) {
	//		printf("N ");
	//		return;
	//	}
	//}

#pragma endregion

}BinTree;

void BinTree::BinTreeTestFunc() {
	//�������ƴ��һ�������������Ե����ṹ
	int k = 6;
	node* (*arr) = (node**)malloc(sizeof(node*) * k);
	assert(arr);

	//�ռ����������
	for (int i = 0; i < k; i++) {
		arr[i] = ByeOneNode(i + 1);
	}

	//����

	arr[0]->left = arr[1];
	arr[1]->left = arr[2];

	arr[0]->right = arr[3];
	arr[3]->left = arr[4];
	arr[3]->right = arr[5];

	//��͵Ĳ���
	node* tempNode = ByeOneNode(1144514);
	arr[2]->right = tempNode;

	this->m_pTopNode = arr[0];
	this->reSize();
	this->reDepth();
}

void Test_BinaryTree_01() {
	BinTree* tree1 = new BinTree();

	//...	���ֱ���
	tree1->BinTreeTestFunc();
	size_t k = 4;
	size_t kLevelNodeCount = tree1->getLevelNodeCount(k);
	printf("size: %zd  depth: %zd\n%zd Level Nodes Count:%zd\n", tree1->size, tree1->depth, k, kLevelNodeCount);
	tree1->preOrder();
	tree1->inOrder();
	tree1->postOrder();

	delete(tree1);
	tree1 = nullptr;
}

int main() {
	Test_BinaryTree_01();

	//cout << "Hello BineryLinkTrue" << endl;
	return 0;
}