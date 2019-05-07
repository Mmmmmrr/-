#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//前序遍历
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int treeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}
int* _preorderTraversal(struct TreeNode* root, int* preorder, int* pindex)
{
	if (root == NULL)
	{
		return;
	}
	preorder[*pindex] = root->val;
	++(*pindex);
	_preorderTraversal(root->left, preorder, pindex);
	_preorderTraversal(root->right, preorder, pindex);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = treeSize(root);
	int* preorder = (int*)malloc(sizeof(int)*(*returnSize));
	int index = 0;
	_preorderTraversal(root, preorder, &index);
	return preorder;
}
//中序遍历
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
int treeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}
int* _inorderTraversal(struct TreeNode* root, int* inorder, int* pindex)
{
	if (root == NULL)
		return;
	_inorderTraversal(root->left, inorder, pindex);
	inorder[*pindex] = root->val;
	++(*pindex);
	_inorderTraversal(root->right, inorder, pindex);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = treeSize(root);
	int* inorder = (int*)malloc(sizeof(int)*(*returnSize));
	int index = 0;
	_inorderTraversal(root, inorder, &index);
	return inorder;
}
//后序遍历
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
int treeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}
int* _posorderTraversal(struct TreeNode* root, int* posorder, int* pindex)
{
	if (root == NULL)
		return;
	_posorderTraversal(root->left, posorder, pindex);
	_posorderTraversal(root->right, posorder, pindex);
	posorder[*pindex] = root->val;
	++(*pindex);
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = treeSize(root);
	int* posorder = (int*)malloc(sizeof(int)*(*returnSize));
	int index = 0;
	_posorderTraversal(root, posorder, &index);
	return posorder;
}
//相同树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p != NULL && q != NULL)
	{
		return p->val == q->val &&isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
	}
	else
		return false;
}
//另一个子树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSameTree(struct TreeNode*p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
	{
		return true;
	}
	else if (p != NULL && q != NULL)
	{
		return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
	}
	else
		return false;
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL)
		return false;
	if (s->val == t->val)
	{
		if (isSameTree(s, t))
			return true;
	}
	if (isSubtree(s->left, t))
		return true;
	if (isSubtree(s->right, t))
		return true;
	return false;
}
