#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType* _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
void SListPrint(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListTest();

void SListDestory(SList* plist);