#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

int BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;
	return node;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(0);
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
}

void ListDestory(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPrintf(List* plist)
{
	assert(plist);
	printf("head");
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;
}
void ListPopBack(List* plist)
{
	assert(plist&&plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;
	free(tail);
	tailprev->_next = head;
	head->_prev = tailprev;

}
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* newnode = BuyListNode(x);
	ListNode* next = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;
}
void ListPopFront(List* plist)
{
	assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;
	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;

}
ListNode* ListFind(List* plist,LTDataType x)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}
int LiseSize(List* plist)
{
	assert(plist);
	int size = 0;
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
int ListEmpty(List* plist)
{
	return plist->_head->_next == plist->_head ? 0 : -1;
}
void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* node = ListFind(plist,x);
	if (node)
	{
		ListErase(node);
	}
}

int main()
{
	List list;
	
	ListInit(&list);
	ListPushBack(&list, 3);
	ListPushBack(&list, 2);
	ListPushBack(&list, 1);
	ListPushBack(&list, 4);
	ListPrintf(&list);
	int pos = ListFind(&list, 3);
	ListInsert(pos, 5);
	ListPrintf(&list);
	ListErase(pos);
	ListPrintf(&list);
	ListPopBack(&list);
	ListPrintf(&list);
	ListDestory(&list);
	system("pause");
	return 0;
}