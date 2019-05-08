#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//��������������
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };



int maxDepth(struct TreeNode* root){
	if (root == NULL)
		return 0;
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return left>right ? left + 1 : right + 1;

}

//�Գƶ�����
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


bool isSubTreeSymmetric(struct TreeNode* leftTree, struct TreeNode* rightTree)
{
	if (leftTree == NULL && rightTree == NULL)
	{
		return true;
	}
	else if (leftTree != NULL && rightTree != NULL)
	{
		return leftTree->val == rightTree->val
			&&isSubTreeSymmetric(leftTree->left, rightTree->right)
			&& isSubTreeSymmetric(leftTree->right, rightTree->left);

	}
	else
		return false;
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;

	return isSubTreeSymmetric(root->left, root->right);

}

//���ƴ����ָ�������
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node* cur = head;
		//�����ڵ�
		while (cur)
		{
			Node* next = cur->next;
			Node* newnode = (Node*)malloc(sizeof(Node));
			cur->next = newnode;
			newnode->next = next;
			cur = next;
		}
		//rendom����
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			if (cur->random)
			{
				Node* random = cur->random;
				copy->random = random->next;
			}
			else
			{
				copy->random = NULL;
			}
			Node* next = copy->next;
			cur = next;
		}
		//�������,�ٽ�������
		Node* tail, *copyhead;
		tail = copyhead = (Node*)malloc(sizeof(Node));
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;
			tail->next = copy;
			tail = copy;
			cur->next = next;
			cur = next;

		}
		Node* newnode = copyhead->next;
		free(copyhead);
		return newnode;
	}
};


