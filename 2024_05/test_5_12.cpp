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
	size_t size;
#pragma endregion

#pragma region �����������
	BinaryTree() {
		this->size = 0;
		this->m_nSize = 0;
		this->m_pTopNode = nullptr;
	}

	~BinaryTree() {
		//����ɾ���ṹ
		treeDestroy(this->m_pTopNode);
		this->m_pTopNode = nullptr;

		//��¼����
		this->size = 0;
		this->m_nSize = 0;
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
#pragma endregion

	void BinTreeTestFunc();

private:
#pragma region �ڲ�����
	node* m_pTopNode;		//���ڵ�
	size_t	m_nSize;		//��Ч�ڵ������
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
		return pNode == nullptr ?
			0 :
			1 + getTreeSize(pNode->left) + getTreeSize(pNode->right);
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

	this->m_pTopNode = arr[0];
	this->reSize();
}

void Test_BinaryTree_01() {
	BinTree* tree1 = new BinTree();

	//...	���ֱ���
	tree1->BinTreeTestFunc();
	tree1->preOrder();
	tree1->inOrder();
	tree1->postOrder();
	printf("size: %zd\n", tree1->size);

	delete(tree1);
	tree1 = nullptr;
}

int main() {
	Test_BinaryTree_01();

	//cout << "Hello BineryLinkTrue" << endl;
	return 0;
}