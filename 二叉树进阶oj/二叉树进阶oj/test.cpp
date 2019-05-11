#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//二叉树最近公共祖先

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

//不在返回0，在返回1
int Find(struct TreeNode* tree, struct TreeNode* node)
{
	if (tree == NULL)
		return 0;
	if (tree == node)
		return 1;
	if (Find(tree->left, node) == 1)
		return 1;
	else if (Find(tree->right, node) == 1)
		return 1;
	return 0;

}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return NULL;
	//其中一个是祖先
	if (root == p || root == q)
		return root;
	int pInleft = Find(root->left, p);
	int qInleft = Find(root->left, p);
	if (pInleft == 1 && qInleft == 1)
	{
		return lowestCommonAncestor(root->left, p, q);
	}
	else if (pInleft == 0 && qInleft == 0)
		return lowestCommonAncestor(root->right, p, q);
	else
		return root;
}

//
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
struct TreeNode(int x)
:val(x)
, left(NULL)
, right(NULL)
{}
};
class Solution {
public:
	TreeNode* prev = NULL;
	void _Convert(TreeNode* cur)
	{
		if (cur == NULL)
			return;
		_Convert(cur->left);
		cur->left = prev;
		if (prev)
			prev->right = cur;
		prev = cur;
		_Convert(cur->right);
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		prev = NULL;
		_Convert(pRootOfTree);
		TreeNode* head = pRootOfTree;
		while (head && head->left)
		{
			head = head->left;
		}
		return head;
	}
};
//从前序与中序遍历序列构造二叉树
//Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
    struct TreeNode *right;
};

//前序确认根，中序确认左子树与右子树
struct TreeNode* _buildTree(int* preorder, int* ppreindex, int* inorder, int left, int right){
	if (left > right)
		return NULL;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (left == right)
	{
		(*ppreindex)++;
		root->val = inorder[left];
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	//根
	//左子树
	//右子树
	root->val = preorder[*ppreindex];
	int rootindex = left;
	while (rootindex <= right)
	{
		if (inorder[rootindex] == root->val)
			break;
		else
			++rootindex;
	}
	//[left,rootindex-1]
	//[rootindex+1,right]
	++(*ppreindex);
	root->left = _buildTree(preorder, ppreindex, inorder, left, rootindex - 1);
	root->right = _buildTree(preorder, ppreindex, inorder, rootindex + 1, right);
	return root;



}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	int index = 0;
	return _buildTree(preorder, &index, inorder, 0, inorderSize - 1);
}

