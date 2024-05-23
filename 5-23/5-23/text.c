#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// KY11 二叉树遍历

//typedef char BTDataType;
//
//typedef struct BTNode {
//    BTDataType data;
//    struct BTNode* left;
//    struct BTNode* right;
//} BTNode;
//
//BTNode* BinaryTreeCreate(BTDataType* a, int* pi) {
//    if (a[*pi] == '#') {
//        (*pi)++;
//        return NULL;
//    }
//    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//
//    node->data = a[(*pi)++];
//    node->left = BinaryTreeCreate(a, pi);
//    node->right = BinaryTreeCreate(a, pi);
//
//    return node;
//}
//
//// 二叉树中序遍历
//void BinaryTreeInOrder(BTNode* root) {
//    if (root == NULL)
//        return;
//
//    BinaryTreeInOrder(root->left);
//    printf("%c ", root->data);
//    BinaryTreeInOrder(root->right);
//}
//
//int main() {
//    BTDataType a[100];
//    int i = 0;
//    scanf("%s", a);
//    BTNode* root = BinaryTreeCreate(a, &i);
//    BinaryTreeInOrder(root);
//    return 0;
//}


// 572. 另一棵树的子树


//Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};


//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//        return false;
//
//    if (root->val == subRoot->val &&
//        isSameTree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot) ||
//        isSubtree(root->right, subRoot);
//}

// 101. 对称二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //
 //bool isSame_Tree(struct TreeNode* q, struct TreeNode* p)
 //{
 //    if (q == NULL && p == NULL)
 //        return true;
 //
 //    if (q == NULL || p == NULL)
 //        return false;
 //
 //    if (q->val != p->val)
 //        return false;
 //
 //    return isSame_Tree(q->left, p->right) && isSame_Tree(q->right, p->left);
 //
 //}
 //
 //bool isSymmetric(struct TreeNode* root) {
 //
 //    if (root == NULL)
 //        return true;
 //    return isSame_Tree(root->left, root->right);
 //}

 // 100. 相同的树

 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     struct TreeNode *left;
  *     struct TreeNode *right;
  * };
  */
  //bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
  //    if (p == NULL && q == NULL)
  //        return true;
  //
  //    if (p == NULL || q == NULL)
  //        return false;
  //
  //    if (p->val != q->val)
  //        return false;
  //
  //    return isSameTree(p->left, q->left) &&
  //        isSameTree(p->right, q->right);
  //}

  // 144. 二叉树的前序遍历

  /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     struct TreeNode *left;
   *     struct TreeNode *right;
   * };
   */
   /**
	* Note: The returned array must be malloced, assume caller calls free().
	*/
	//int prevcompust(struct TreeNode* root)
	//{
	//    return root == NULL ? 0 : prevcompust(root->left) + prevcompust(root->right) + 1;
	//}
	//
	//void prevOrder(struct TreeNode* root, int* a, int* pi)
	//{
	//    if (root == NULL)
	//        return;
	//
	//    a[(*pi)++] = root->val;
	//    prevOrder(root->left, a, pi);
	//    prevOrder(root->right, a, pi);
	//
	//}
	//
	//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	//    *returnSize = prevcompust(root);
	//
	//    int* a = (int*)malloc(sizeof(int) * (*returnSize));
	//
	//    int i = 0;
	//    prevOrder(root, a, &i);
	//    return a;
	//}

