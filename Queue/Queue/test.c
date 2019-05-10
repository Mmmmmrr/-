#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

BTNode* CreatTree(char* array, int* pindex)
{
	if (array[*pindex] == '#')
	{
		++(*pindex);
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_ch = array[*pindex];
	++(*pindex);
	root->_left = CreatTree(array, pindex);
	root->_right = CreatTree(array, pindex);
	return root;
}

void Inorder(BTNode* root)
{
	if (root == NULL)
		return;
	Inorder(root->_left);
	printf("%c ", root->_ch);
	Inorder(root->_right);
}
void DestoryTree(BTNode* root)
{
	if (root == NULL)
		return;
	DestoryTree(root->_left);
	DestoryTree(root->_right);
	free(root);
	root = NULL;
}
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
int TreeKLevel(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevel(root->_left, k - 1) + TreeKLevel(root->_right, k - 1);

}
BTNode* BinTreeFind(BTNode* root, BTDatatype x)
{
	if (root == NULL)
	{
		return NULL;
	}
	BTNode* ret = BinTreeFind(root->_left, x);
	return ret;
	ret = BinTreeFind(root->_right, x);
	return ret;
	return NULL;
}

void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 0)
	{

		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_ch);
		if (front->_left != NULL)
			QueuePush(&q, front->_left);
		if (front->_right != NULL)
			QueuePush(&q, front->_right);
	}
	printf("\n");
}
//判断二叉树是不是完全二叉树
int BinTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	//插入节点
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		else
		{
			QueuePush(&q, root->_left);
			QueuePush(&q, root->_right);
		}
	}
	//判断之后是否有节点
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestory(&q);
			return 0;
		}
	}
	return 1;
}


int main()
{
	int index = 0;
	char array[100] = "abc##de#g##f###";
	//scanf("%s", array);
	//构建树
	BTNode* tree = CreatTree(array, &index);
	Inorder(tree);
	printf("\n");
	printf("%d\n", TreeSize(tree));
	printf("%d\n", TreeLeafSize(tree));
	printf("%d\n", TreeKLevel(tree, 2));
	TreeLevelOrder(tree);
	printf("%d\n", BinTreeComplete(tree));
	system("pause");
	return 0;
}
