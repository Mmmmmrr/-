#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;

}BTNode;

BTNode* BinaryTreeCreat(BTDataType* a, int* pi);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryFind(BTNode* root, BTDataType x);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);
void BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonr(BTNode* root);
void BinaryTreeInOrderNonr(BTDataType* root);
void BinaryTreePostOrderNonr(BTNode* root);
void BinaryTreePrint(BTNode* root);

void BinaryTreeTest();