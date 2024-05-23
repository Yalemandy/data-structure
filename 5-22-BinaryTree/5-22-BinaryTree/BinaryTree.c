#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);

	BTNode* tmp = *root;
	free(tmp);
}

// 节点的创建
BTNode* BinaryTreeNode(BTDataType data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NewNode == NULL)
	{
		perror("malloc fail!");
		return NULL;
	}

	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%d ",root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%d ",root->data);
	BinaryTreeInOrder(root->left);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->left);
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int* k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

 	return BinaryTreeLevelKSize(root->left, k - 1)+
	BinaryTreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root == x)
		return root;

	BTNode* q1 = BinaryTreeFind(root->left, x);
	if (q1)
		return q1;
	BTNode* q2 = BinaryTreeFind(root->right, x);
	if (q2)
		return q2;

	return NULL;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		pi++;
		return NULL;
	}

	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail!");
		return NULL;
	}

	node->data = a[(*pi)++];
	node->left = BinaryTreeCreate(a, pi);
	node->right = BinaryTreeCreate(a, pi);

	return node;
}


//计算二叉树的深度
int BinaryTreeheight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int LeftHeight = BinaryTreeheight(root->left) + 1;
	int RightHeight = BinaryTreeheight(root->right) + 1;

	return LeftHeight > RightHeight ? LeftHeight : RightHeight;
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	int size = BinaryTreeLeafSize(root);

	int height = BinaryTreeheight(root);

	int num = pow(2, height - 1) / 2;

	if (size >= num)
		return 1;
	else
		return 0;
}
//
//// 层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//
//}