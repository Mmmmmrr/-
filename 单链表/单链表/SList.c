#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);
	}
	else
	{
		
		SListNode* tail = plist->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		SListNode* newtail = BuySListNode(x);
		tail->_next = newtail;
	}
	
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pnode = (SListNode*)malloc(sizeof(SListNode));
	pnode->_data = x;
	pnode->_next = NULL;
	return pnode;
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newhead = BuySListNode(x);
	newhead->_next = plist->_head;
	plist->_head = newhead;

}

void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

void SListPopBack(SList* plist)
{
	assert(plist);
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = plist->_head;
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;

	}
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	
		SListNode* prev = plist->_head;
		while (prev !=NULL)
		{
			if (prev->_data == x)
			{
				return prev;
			}				
			prev = prev->_next;
		}
	return prev;
	
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* next = pos->_next;
	SListNode* newnode = BuySListNode(x);
	pos->_next = newnode;
	newnode->_next = next;
}


void SListEraseAfter(SListNode* pos)
{
	assert(pos&&pos->_next!=NULL);
	pos->_next = pos->_next->_next;
	

}
void SListRemove(SList* plist, SLTDataType x)//втурвти╬
{
	assert(plist);
	SListNode* cur = SListFind(plist, x);
	SListNode* prev = plist->_head;
	while (prev == cur)
	{
		prev->_next = prev->_next->_next;
	}
	prev->_next = cur->_next;
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void SListTest()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 5);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPrint(&list);
	SListPopFront(&list);
	SListPrint(&list);
	SListPushBack(&list, 8);
	SListPrint(&list);
	SListPushBack(&list, 9);
	SListPrint(&list);
	SListPopBack(&list);
	SListPrint(&list);
	SListNode* pos = SListFind(&list, 3);
	SListInsertAfter(pos, 10);
	SListPrint(&list);
	SListEraseAfter(pos);
	SListPrint(&list);
	SListRemove(&list, 3);
	SListPrint(&list);


	SListDestory(&list);

}