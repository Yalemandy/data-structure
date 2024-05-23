#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);

	BTNode* tmp = *root;
	free(tmp);
}

// �ڵ�Ĵ���
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

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%d ",root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%d ",root->data);
	BinaryTreeInOrder(root->left);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->left);
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int* k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

 	return BinaryTreeLevelKSize(root->left, k - 1)+
	BinaryTreeLevelKSize(root->right, k - 1);
}

// ����������ֵΪx�Ľڵ�
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

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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


//��������������
int BinaryTreeheight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int LeftHeight = BinaryTreeheight(root->left) + 1;
	int RightHeight = BinaryTreeheight(root->right) + 1;

	return LeftHeight > RightHeight ? LeftHeight : RightHeight;
}

// �ж϶������Ƿ�����ȫ������
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
//// �������
//void BinaryTreeLevelOrder(BTNode* root)
//{
//
//}