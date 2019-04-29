#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);
void ListPrint(List* plist);
void ListTest1();
