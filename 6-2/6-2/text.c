#define _CRT_SECURE_NO_WANINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//
//// ·­×ª¶þ²æÊ÷
// struct TreeNode {
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
// };
// 
//
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if (root == NULL)
//        return NULL;
//
//    struct TreeNode* left = invertTree(root->left);
//    struct TreeNode* right = invertTree(root->right);
//
//    root->left = right;
//    root->right = left;
//    return root;
//
//}

#include <stdlib.h>  

int main() {
    int num = -10;
    int abs_num = abs(num);
    printf("The absolute value of %d is %d\n", num, abs_num);
    return 0;
}