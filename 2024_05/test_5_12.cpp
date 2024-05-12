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
		this->m_pRoot = nullptr;
	}

	~BinaryTree() {
		//����ɾ���ṹ
		treeDestroy(this->m_pRoot);
		this->m_pRoot = nullptr;

		//��¼����
		this->m_nSize = 0;
		this->size = this->m_nSize;
		this->m_nDepth = 0;
		this->depth = this->m_nDepth;
	}
#pragma endregion

#pragma region �������������
	void preOrder() {
		preOrder(this->m_pRoot);
		putchar('\n');
	}
	void inOrder() {
		inOrder(this->m_pRoot);
		putchar('\n');
	}
	void postOrder() {
		postOrder(this->m_pRoot);
		putchar('\n');
	}

	//����
	size_t reSize() {
		size_t newSize = getTreeSize(this->m_pRoot);
		this->m_nSize = newSize;
		this->size = this->m_nSize;
		return this->size;
	}
	//���
	size_t reDepth() {
		size_t newDepth = getTreeDepth(this->m_pRoot);
		this->m_nDepth = newDepth;
		this->depth = this->m_nDepth;
		return this->depth;
	}

	size_t getLevelNodeCount(size_t k) {
		return treeKLevelNodeCount(this->m_pRoot, k);
	}

	size_t getLeafNodeCount() {
		return getLeafNodeCount(this->m_pRoot);
	}

	node* find(BTData x) {
		return find(this->m_pRoot, x);
	}

	bool isEmpty() {
		return !(this->m_pRoot);
	}
#pragma endregion

#pragma region ����������
	//�������
	bool operator==(const class BinaryTree &rightTree) {
		//�����ж�
		if (this->m_nSize != rightTree.m_nSize	||
			this->m_nDepth != rightTree.m_nDepth) {
			return false;
		}
		if (this->m_pRoot == rightTree.m_pRoot) {
			return true;
		}
		//�ڲ��ṹ����ֵ�ж�
		return treeCompare(this->m_pRoot, rightTree.m_pRoot);
	}

#pragma endregion

	void BinTreeTestFunc();

private:
#pragma region �ڲ�����
	node* m_pRoot;		//���ڵ�
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

	size_t getTreeSize(node* root) {
		//�ݹ�ͳ�����нڵ�
		//�սڵ㲻ͳ��
		if (root == nullptr) {
			return 0;
		}
		//����ͳ�����
		size_t leftValue = getTreeSize(root->left);
		size_t rightValue = getTreeSize(root->right);
		return 1 + leftValue + rightValue;
	}

	//���
	size_t getTreeDepth(node* root) {
		//�ݹ�ͳ�����нڵ�
		//�սڵ㲻ͳ��
		if (root == nullptr) {
			return 0;
		}
		//ͳ��������������
		size_t leftValue = getTreeDepth(root->left);
		size_t rightValue = getTreeDepth(root->right);
		return 1 + (leftValue > rightValue ? leftValue : rightValue);
	}

	size_t treeKLevelNodeCount(node* root, size_t k) {
		//������k����
		//�������սڵ�
		if (root == nullptr) {
			return 0;
		}
		//������Ŀ��ڵ�
		else if (k == 1) {
			return 1;
		}
		//Ŀ��ڵ��ϲ�ڵ㣬������ȡͳ������
		size_t leftValue = treeKLevelNodeCount(root->left, k - 1);
		size_t rightValue = treeKLevelNodeCount(root->right, k - 1);
		return leftValue + rightValue;
	}
	
	node* find(node* root, BTData x) {
		//���սڵ㷵�ؿ�
		if (root == nullptr) {
			return nullptr;
		}
		//�ҵ��ڵ㷵�ظýڵ��ָ��
		else if (root->data == x) {
			return root;
		}
		//��ǰ�ڵ㲻ΪѰ�ҵĽڵ�ʱ����Ѱ��,�����ϴ����ҵ��Ľڵ�
		node* leftPtr = find(root->left, x);
		if (leftPtr != nullptr) {
			return leftPtr;
		}
		node* rightPtr = find(root->right, x);
		if (rightPtr != nullptr) {
			return rightPtr;
		}
		return nullptr;
	}

	size_t getLeafNodeCount(node* root) {
		if (root == nullptr) {
			return 0;
		}

		if (root->left == nullptr && root->right == nullptr) {
			return 1;
		}

		size_t leftValue = getLeafNodeCount(root->left);
		size_t rightValue = getLeafNodeCount(root->right);

		return leftValue + rightValue;
	}

	//��������ݻ�
	void treeDestroy(node* root) {
		//TODO:�ݻ���

		if (root == nullptr) {
			return;
		}

		//�ݻ������������ٴݻ��Լ�
		treeDestroy(root->left);
		treeDestroy(root->right);
		free(root);
		root = nullptr;
	}

	//����
	void preOrder(node* root) {
		if (root == nullptr) {
			printf("N ");
			return;
		}

		printf("%d ", root->data);	//��
		preOrder(root->left);		//��
		preOrder(root->right);		//��
	}

	void inOrder(node* root) {
		if (root == nullptr) {
			printf("N ");
			return;
		}

		inOrder(root->left);		//��
		printf("%d ", root->data);	//��
		inOrder(root->right);		//��
	}

	void postOrder(node* root) {
		if (root == nullptr) {
			printf("N ");
			return;
		}

		postOrder(root->left);		//��
		postOrder(root->right);	//��
		printf("%d ", root->data);	//��
	}

	bool treeCompare(node* leftRoot, node* rightRoot) {
		
		//���Ҹ�����Ϊ��
		if (leftRoot == nullptr && rightRoot == nullptr) {
			return true;
		}
		//���Ҹ�������һ��Ϊ��
		else if (leftRoot == nullptr || rightRoot == nullptr) {
			return false;
		}
		//���Ҹ�������Ϊ��ʱ�Ƚϸ���ֵ
		else if (leftRoot->data != rightRoot->data) {
			return false;
		}
		//���Ҹ�������Ϊ���Ҷ���ȣ��ݹ����
		bool leftValue = treeCompare(leftRoot->left, rightRoot->left);
		if (leftValue == false) {
			return false;
		}
		bool rightValue = treeCompare(leftRoot->right, rightRoot->right);
		if (rightValue == false) {
			return false;
		}
		//��������ֵ������󷵻�ֵ
		return leftValue && rightValue;
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

	//����ڵ�Ĳ���
	node* tempNode = ByeOneNode(114514);
	arr[1]->right = tempNode;

	this->m_pRoot = arr[0];
	this->reSize();
	this->reDepth();
}

void Test_BinaryTree_01() {
	BinTree* tree1 = new BinTree();

	//...	���ֱ���
	tree1->BinTreeTestFunc();
	size_t k = 4;
	size_t kLevelNodeCount = tree1->getLevelNodeCount(k);
	BinTree::BTData findData = 114514;
	BinTree::node* findNode = tree1->find(findData);
	printf("size: %zd  depth: %zd\n"
		"%zd Level Nodes Count:%zd\n"
		"Find %p:->data= %d\n"
		"LeafNodeCount: %zd\n",
		tree1->size, tree1->depth,
		k, kLevelNodeCount,
		findNode, findNode != nullptr ? findNode->data : 0xCCCCCCCC,
		tree1->getLeafNodeCount());

	tree1->preOrder();
	tree1->inOrder();
	tree1->postOrder();

	//ͬһ������ӦΪtrue
	BinTree* tree1_1 = tree1;
	printf("��ȣ�%d\n", (*tree1) == (*tree1_1));

	BinTree* tree2 = new BinaryTree();
	tree2->BinTreeTestFunc();
	//����������������ͬ��ӦΪtrue
	printf("��ȣ�%d\n", *tree1 == *tree2);
	//�������������ݲ�ͬ��ӦΪfalse
	tree2->find(114514)->data = 20;
	printf("��ȣ�%d\n", *tree1 == *tree2);

	tree2->preOrder();

	delete(tree2);
	tree2 = nullptr;

	delete(tree1);
	tree1 = nullptr;
	tree1_1 = nullptr;
}

int main() {
	Test_BinaryTree_01();

	//cout << "Hello BineryLinkTrue" << endl;
	return 0;
}