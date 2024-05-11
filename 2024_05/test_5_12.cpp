#define _CRT_SECURE_NO_WARNINGS\

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>


//链式二叉树

/*
* 二叉树遍历 ：
*	前序 -	根，左子树，右子树
*	中序 -	左子树，根，右子树
*	后序 -	左子树，右子树，根
* 
*	层序 -	每层顺序遍历
*/

typedef class BinaryTree {
public:
#pragma region 结构体及变量定义
	typedef int BinaryTreeNodeDataType, BTData;
	//树节点
	typedef struct BinaryTreeNode {
		BTData data;
		BinaryTreeNode*	left;	//左子树地址
		BinaryTreeNode*	right;	//右子树地址
	}BTNode, node;
	size_t size;				//有效节点的数量
	size_t depth;				//树的深度
#pragma endregion

#pragma region 构造相关重载
	BinaryTree() {
		this->m_nSize = 0;
		this->size = this->m_nSize;
		this->m_nDepth = 0;
		this->depth = this->m_nDepth;
		this->m_pTopNode = nullptr;
	}

	~BinaryTree() {
		//遍历删除结构
		treeDestroy(this->m_pTopNode);
		this->m_pTopNode = nullptr;

		//记录清理
		this->m_nSize = 0;
		this->size = this->m_nSize;
		this->m_nDepth = 0;
		this->depth = this->m_nDepth;
	}
#pragma endregion

#pragma region 二叉树常规操作
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

	//计数
	size_t reSize() {
		size_t newSize = getTreeSize(this->m_pTopNode);
		this->m_nSize = newSize;
		this->size = this->m_nSize;
		return this->size;
	}
	//深度
	size_t reDepth() {
		size_t newDepth = getTreeDepth(this->m_pTopNode);
		this->m_nDepth = newDepth;
		this->depth = this->m_nDepth;
		return this->depth;
	}
#pragma endregion

	void BinTreeTestFunc();

private:
#pragma region 内部变量
	node* m_pTopNode;		//根节点
	size_t	m_nSize;		//有效节点的数量
	size_t m_nDepth;		//树的深度
#pragma endregion

#pragma region 内部操作函数

	//获取一个节点的空间并初始化
	node* ByeOneNode(BTData value) {
		//空间申请
		node* newNode = (node*)malloc(sizeof(node));
		assert(newNode);
		//初始化与注入
		newNode->data = value;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}

	size_t getTreeSize(node* pNode) {
		//递归统计所有节点
		return pNode == nullptr ?
			0 :
			1 + getTreeSize(pNode->left) + getTreeSize(pNode->right);
	}

	//深度
	size_t getTreeDepth(node* pNode) {
		//递归统计所有节点
		size_t leftValue = 0;
		size_t rightValue = 0;
		return pNode == nullptr ?
			0 :
			1 + ((leftValue = getTreeDepth(pNode->left)) > (rightValue = getTreeDepth(pNode->right)) ? 
				leftValue :
				rightValue);
	}

	//后序遍历摧毁
	void treeDestroy(node* pTop) {
		//TODO:摧毁树

		if (pTop == nullptr) {
			return;
		}

		//摧毁左右子树，再摧毁自己
		treeDestroy(pTop->left);
		treeDestroy(pTop->right);
		free(pTop);
		pTop = nullptr;
	}

	//遍历
	void preOrder(node* pNode) {
		if (pNode == nullptr) {
			printf("N ");
			return;
		}

		printf("%d ", pNode->data);	//根
		preOrder(pNode->left);		//左
		preOrder(pNode->right);		//右
	}

	void inOrder(node* pNode) {
		if (pNode == nullptr) {
			printf("N ");
			return;
		}

		inOrder(pNode->left);		//左
		printf("%d ", pNode->data);	//根
		inOrder(pNode->right);		//右
	}

	void postOrder(node* pNode) {
		if (pNode == nullptr) {
			printf("N ");
			return;
		}

		postOrder(pNode->left);		//左
		postOrder(pNode->right);	//右
		printf("%d ", pNode->data);	//根
	}

	////层序遍历
	//void levelOrder(node* pNode) {
	//	//空节点输出N
	//	if (pNode == nullptr) {
	//		printf("N ");
	//		return;
	//	}
	//}

#pragma endregion

}BinTree;

void BinTree::BinTreeTestFunc() {
	//这个用来拼接一个可以用来测试的树结构
	int k = 6;
	node* (*arr) = (node**)malloc(sizeof(node*) * k);
	assert(arr);

	//空间申请与填充
	for (int i = 0; i < k; i++) {
		arr[i] = ByeOneNode(i + 1);
	}

	//链接

	arr[0]->left = arr[1];
	arr[1]->left = arr[2];

	arr[0]->right = arr[3];
	arr[3]->left = arr[4];
	arr[3]->right = arr[5];

	this->m_pTopNode = arr[0];
	this->reSize();
	this->reDepth();
}

void Test_BinaryTree_01() {
	BinTree* tree1 = new BinTree();

	//...	各种遍历
	tree1->BinTreeTestFunc();
	printf("size: %zd\tdepth: %zd\n", tree1->size, tree1->depth);
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