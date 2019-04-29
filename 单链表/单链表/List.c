#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_data = x;
	return newnode;
}

void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(1);
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



void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	head->_prev = newnode;
	newnode->_next = head;
}


void ListPopBack(List* plist)
{
	assert(plist &&plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* tail =head->_prev;
	ListNode* tailprev = tail->_prev;
	free(tail);
	head->_prev = tailprev;
	tailprev->_next = head;
}


void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next= head->_next;
	ListNode* newnode = BuyListNode(x);
	newnode->_next = next;
	next->_prev = newnode;
	head->_next = newnode;
	newnode->_prev = head;

}


void ListPopFront(List* plist)
{
	assert(plist &&plist->_head->_next !=plist->_head);
	ListNode* head = plist->_head;
	ListNode* next = head->_next->_next;
	head->_next = next;
	next->_prev = head;
}


ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
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
	ListNode* newnode = BuyListNode(x);
	ListNode* next = pos->_next;
	pos->_next = newnode;
	newnode->_prev = pos;
	newnode->_next = next;
	next->_prev = newnode;
	
}


void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;
	prev->_next = next;
	next->_prev = prev;
}


void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* pos = ListFind(plist, x);
	ListErase(pos);
}


void ListPrint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	printf("<-head");
	while (cur != plist->_head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListTest1()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPushBack(&list, 6);
	ListPushBack(&list, 7);
	ListPrint(&list);
	ListPopBack(&list);
	ListPrint(&list);
	ListPushFront(&list, 9);
	ListPrint(&list);
	ListPopFront(&list);
	ListPrint(&list);
	ListNode* pos = ListFind(&list, 3);
	ListInsert(pos, 11);
	ListPrint(&list);
	ListErase(pos);
	ListPrint(&list);
	ListRemove(&list, 4);
	ListPrint(&list);





	ListDestory(&list);
}