#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

BTNode* BinaryTreeCreat(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreat(a, pi);
		(*pi)++;
		root->_right = BinaryTreeCreat(a, pi);
		return root;
	}
}


//void BinaryTreeDestory(BTNode* root)
//{
//	if (root->_data != 0)
//	{
//		free(root->_data);
//		root->_data = NULL;
//		root->_left = NULL;
//		root->_right = NULL;
//	}
//}


int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
}


int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL&&root->_right == NULL)
		{
			return 1;
		}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}


int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1
		);
}

BTNode* BinaryFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret = BinaryFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	return ret = BinaryFind(root->_right, x);
}

void _BinaryTreePrevOrder(BTNode* root, int* a, int* pi)
{
	if (root == NULL)
		return;
	printf("%d ", root->_data);
	(*pi)++;
	_BinaryTreePrevOrder(root->_left, a, pi);
	_BinaryTreePrevOrder(root->_right, a, pi);
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	int treesize = BinaryTreeSize(root);
	int* a = (int*)malloc(sizeof(int)*treesize);
	int i = 0;
	 _BinaryTreePrevOrder(root,a,&i);
}

void _BinaryTreeInOrder(BTNode* root,int* a, int* pi)
{
	if (root == NULL)
		return;
	_BinaryTreeInOrder(root->_left, a, pi);
	printf("%d ", root->_data);
	_BinaryTreeInOrder(root->_right, a, pi);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	int treesize = BinaryTreeSize(root);
	int* a = (int*)malloc(sizeof(int)*treesize);
	int i = 0;
	_BinaryTreeInOrder(root, a, &i);

}


void _BinaryTreePostOrder(BTNode* root, int* a, int* pi)
{
	if (root == NULL)
		return;
	_BinaryTreePostOrder(root->_left, a, pi);
	_BinaryTreePostOrder(root->_right, a, pi);
	printf("%d ", root->_data);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	int treesize = BinaryTreeSize(root);
	int* a = (int*)malloc(sizeof(int)*treesize);
	int i = 0;
	_BinaryTreePostOrder(root, a, &i);
}


void BinaryTreeLevelOrder(BTNode* root)
{

}


void BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonr(BTNode* root);
void BinaryTreeInOrderNonr(BTDataType* root);
void BinaryTreePostOrderNonr(BTNode* root);
void BinaryTreePrint(BTNode* root);

void BinaryTreeTest()
{
	char a[] = "ABCD#E##F##";
	int i = 0;
	BTNode* tree = BinaryTreeCreat(a, &i);
	printf("%d\n",BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));

}