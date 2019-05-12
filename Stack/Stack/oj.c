#define _CRT_SECURE_NO_WARNINGS 1
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
#include "stack.h"
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

 
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	struct TreeNode* cur = root;
	Stack st;
	StackInit(&st);
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			printf("%d ", cur->val);
			StackPush(&st, cur);
			cur = cur->left;

		}
		struct TreeNode* top = StackTop(&st);
		StackPop(&st);
		cur = top->right;
	}
	int size = TreeSize(root);

	int* prearray = (int*)malloc(sizeof(int)*size);
	int i = 0;
	cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			printf("%d ", cur->val);
			prearray[i++] = cur->val;
			StackPush(&st, cur);
			cur = cur->left;

		}
		struct TreeNode* top = StackTop(&st);
		StackPop(&st);
		cur = top->right;
	}

	return prearray;

}
