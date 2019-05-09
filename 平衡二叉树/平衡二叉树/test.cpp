//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
//// Definition for a binary tree node.
////平衡二叉树
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
//
//int TreeHeight(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int leftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}
//
//bool isBalanced(struct TreeNode* root){
//
//	if (root == NULL)
//		return 0;
//	int leftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//	return abs(leftHeight - rightHeight)<2
//		&& isBalanced(root->left)
//		&& isBalanced(root->right);
//}
////O(N)算法
///**
//* Definition for a binary tree node.
//* struct TreeNode {
//*     int val;
//*     struct TreeNode *left;
//*     struct TreeNode *right;
//* };
//*/
//typedef struct RET
//{
//	bool isbalanced;
//	int height;
//}Ret;
//Ret _isBalanced(struct TreeNode* root)
//{
//	Ret ret;
//	ret.height = 0;
//	ret.isbalanced = true;
//
//	if (root == NULL)
//		return ret;
//	Ret lret;
//	lret = _isBalanced(root->left);
//	if (lret.isbalanced == false)
//	{
//		return lret;
//	}
//	Ret rret;
//	rret = _isBalanced(root->right);
//	if (rret.isbalanced == false)
//	{
//		return rret;
//	}
//	ret.isbalanced = abs(lret.height - rret.height) < 2;
//	ret.height = lret.height > rret.height ? lret.height + 1 : rret.height + 1;
//	return ret;
//}
//
//bool isBalanced(struct TreeNode* root){
//	Ret ret = _isBalanced(root);
//	return ret.isbalanced;
//}
//二叉树遍历
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct BTreeNode
{
	struct BTreeNode* _left;
	struct BTreeNode* _right;
	char _ch;
}BTreeNode;

BTreeNode* CreatTree(char* array, int* pindex)
{
	if (array[*pindex] == '#')
	{
		++(*pindex);
		return NULL;
	}
	BTreeNode* root = (BTreeNode*)malloc(sizeof(BTreeNode));
	root->_ch = array[*pindex];
	++(*pindex);
	root->_left = CreatTree(array, pindex);
	root->_right = CreatTree(array, pindex);
	return root;
}

void Inorder(BTreeNode* root)
{
	if (root == NULL)
		return;
	Inorder(root->_left);
	printf("%c ", root->_ch);
	Inorder(root->_right);
}
void DestoryTree(BTreeNode* root)
{
	if (root == NULL)
		return;
	DestoryTree(root->_left);
	DestoryTree(root->_right);
	free(root);
	root = NULL;
}
int TreeSize(BTreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
int TreeLeafSize(BTreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
int TreeKLevel(BTreeNode* root , int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevel(root->_left, k - 1) + TreeKLevel(root->_right, k - 1);

}

int main()
{
	int index = 0;
	char array[100] = "abc##de#g##f###";
	//scanf("%s", array);
	//构建树
	BTreeNode* tree = CreatTree(array, &index);
	Inorder(tree);
	printf("\n");
	printf("%d\n", TreeSize(tree));
	printf("%d\n", TreeLeafSize(tree));
	printf("%d\n", TreeKLevel(tree,2));
	system("pause");
	return 0;
}

