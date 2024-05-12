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
		this->m_pRoot = nullptr;
	}

	~BinaryTree() {
		//遍历删除结构
		treeDestroy(this->m_pRoot);
		this->m_pRoot = nullptr;

		//记录清理
		this->m_nSize = 0;
		this->size = this->m_nSize;
		this->m_nDepth = 0;
		this->depth = this->m_nDepth;
	}
#pragma endregion

#pragma region 二叉树常规操作
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

	//计数
	size_t reSize() {
		size_t newSize = getTreeSize(this->m_pRoot);
		this->m_nSize = newSize;
		this->size = this->m_nSize;
		return this->size;
	}
	//深度
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

#pragma region 操作符重载
	//相等运算
	bool operator==(const class BinaryTree &rightTree) {
		//基础判断
		if (this->m_nSize != rightTree.m_nSize	||
			this->m_nDepth != rightTree.m_nDepth) {
			return false;
		}
		if (this->m_pRoot == rightTree.m_pRoot) {
			return true;
		}
		//内部结构及数值判断
		return treeCompare(this->m_pRoot, rightTree.m_pRoot);
	}

#pragma endregion

	void BinTreeTestFunc();

private:
#pragma region 内部变量
	node* m_pRoot;		//根节点
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

	size_t getTreeSize(node* root) {
		//递归统计所有节点
		//空节点不统计
		if (root == nullptr) {
			return 0;
		}
		//左右统计求和
		size_t leftValue = getTreeSize(root->left);
		size_t rightValue = getTreeSize(root->right);
		return 1 + leftValue + rightValue;
	}

	//深度
	size_t getTreeDepth(node* root) {
		//递归统计所有节点
		//空节点不统计
		if (root == nullptr) {
			return 0;
		}
		//统计左右最深子树
		size_t leftValue = getTreeDepth(root->left);
		size_t rightValue = getTreeDepth(root->right);
		return 1 + (leftValue > rightValue ? leftValue : rightValue);
	}

	size_t treeKLevelNodeCount(node* root, size_t k) {
		//遍历，k迭代
		//遍历到空节点
		if (root == nullptr) {
			return 0;
		}
		//遍历到目标节点
		else if (k == 1) {
			return 1;
		}
		//目标节点上层节点，向下收取统计数据
		size_t leftValue = treeKLevelNodeCount(root->left, k - 1);
		size_t rightValue = treeKLevelNodeCount(root->right, k - 1);
		return leftValue + rightValue;
	}
	
	node* find(node* root, BTData x) {
		//到空节点返回空
		if (root == nullptr) {
			return nullptr;
		}
		//找到节点返回该节点的指针
		else if (root->data == x) {
			return root;
		}
		//当前节点不为寻找的节点时继续寻找,并向上传递找到的节点
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

	//后序遍历摧毁
	void treeDestroy(node* root) {
		//TODO:摧毁树

		if (root == nullptr) {
			return;
		}

		//摧毁左右子树，再摧毁自己
		treeDestroy(root->left);
		treeDestroy(root->right);
		free(root);
		root = nullptr;
	}

	//遍历
	void preOrder(node* root) {
		if (root == nullptr) {
			printf("N ");
			return;
		}

		printf("%d ", root->data);	//根
		preOrder(root->left);		//左
		preOrder(root->right);		//右
	}

	void inOrder(node* root) {
		if (root == nullptr) {
			printf("N ");
			return;
		}

		inOrder(root->left);		//左
		printf("%d ", root->data);	//根
		inOrder(root->right);		//右
	}

	void postOrder(node* root) {
		if (root == nullptr) {
			printf("N ");
			return;
		}

		postOrder(root->left);		//左
		postOrder(root->right);	//右
		printf("%d ", root->data);	//根
	}

	bool treeCompare(node* leftRoot, node* rightRoot) {
		
		//左右根树都为空
		if (leftRoot == nullptr && rightRoot == nullptr) {
			return true;
		}
		//左右根树其中一个为空
		else if (leftRoot == nullptr || rightRoot == nullptr) {
			return false;
		}
		//左右根树都不为空时比较根的值
		else if (leftRoot->data != rightRoot->data) {
			return false;
		}
		//左右根树都不为空且都相等，递归计算
		bool leftValue = treeCompare(leftRoot->left, rightRoot->left);
		if (leftValue == false) {
			return false;
		}
		bool rightValue = treeCompare(leftRoot->right, rightRoot->right);
		if (rightValue == false) {
			return false;
		}
		//左右树等值且运算后返回值
		return leftValue && rightValue;
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

	//额外节点的测试
	node* tempNode = ByeOneNode(114514);
	arr[1]->right = tempNode;

	this->m_pRoot = arr[0];
	this->reSize();
	this->reDepth();
}

void Test_BinaryTree_01() {
	BinTree* tree1 = new BinTree();

	//...	各种遍历
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

	//同一棵树，应为true
	BinTree* tree1_1 = tree1;
	printf("相等？%d\n", (*tree1) == (*tree1_1));

	BinTree* tree2 = new BinaryTree();
	tree2->BinTreeTestFunc();
	//两棵树，且内容相同，应为true
	printf("相等？%d\n", *tree1 == *tree2);
	//两棵树，且内容不同，应为false
	tree2->find(114514)->data = 20;
	printf("相等？%d\n", *tree1 == *tree2);

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