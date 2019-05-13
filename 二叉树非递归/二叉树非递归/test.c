#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };



/**
* Note: The returned array must be malloced, assume caller calls free().
*/
typedef struct TreeNode* STDataType;
typedef struct Stack
{
	STDataType* _a;
	size_t _top;
	size_t _capacity;
}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = realloc(ps->_a, sizeof(STDataType)*newcapacity);
		assert(ps->_a);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top >0);
	--ps->_top;

}
STDataType StackTop(Stack* ps)
{
	assert(ps&& ps->_top >0);
	return ps->_a[ps->_top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int* inarray = (int*)malloc(sizeof(int)*size);
	int i = 0;
	struct TreeNode* cur = root;
	Stack st;
	StackInit(&st);
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->left;

		}
		struct TreeNode* top = StackTop(&st);
		printf("%d ", top->val);
		inarray[i++] = top->val;
		StackPop(&st);
		cur = top->right;
	}
	return inarray;


}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	struct TreeNode* prev = NULL;
	int* posarray = (int*)malloc(sizeof(int)*size);
	int i = 0;
	struct TreeNode* cur = root;
	Stack st;
	StackInit(&st);
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->left;
		}
		struct TreeNode* top = StackTop(&st);
		if (top->right == NULL || top->right == prev)
		{
			printf("%d ", top->val);
			posarray[i++] = top->val;
			StackPop(&st);
			prev = top;
		}
		else
			cur = top->right;
	}
	return posarray;
}


