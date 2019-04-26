#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;

};
//ɾ�������е��ڸ���ֵ val �����нڵ�
struct ListNode* removeElement(struct ListNode* head,int val)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	struct ListNode* next;
	while (cur)
	{
		if (cur->val == val)
		{
			next = cur->next;
			free(cur);
			cur = next;
			if (prev == NULL)
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}
		}
		prev = cur;
		cur = cur->next;
	}
	return head;
}

//��תһ��������
struct ListNode* ReserveList(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	struct ListNode* next;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

//����һ������ͷ��� head �ķǿյ���������������м��м���
struct ListNode* MidListNode(struct ListNode* head)
{
	struct ListNode* cur = head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	int mid = count / 2;
	cur = head;
	while (mid--)
	{
		cur = cur->next;
	}
	return cur;
}

//����һ����������������е�����k�����
struct ListNode* Findknode(struct ListNode* head, int k)
{
	struct ListNode* cur = head;
	int count = 0;
	if (k = 0)
		return NULL;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	count -= k;
	cur = head;
	if (k > count)
	{
		return NULL;
	}
	while (count--)
	{
		cur = cur->next;
	}
	return cur;
}

//��������������ϲ�Ϊһ���µ��������������µ�����
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head;
	struct ListNode* cur;
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	if (l1->val < l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}
	cur = head;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			cur = cur->next;
			l2 = l2->next;
		}
	}
	if (l1)
	{
		cur->next = l1;
	}
	if (l2)
	{
		cur->next = l2;
	}
	return head;
}
