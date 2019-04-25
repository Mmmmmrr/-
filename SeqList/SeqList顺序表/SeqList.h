#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList;

void SeqListInit(SeqList* ps, size_t capacity);
void SeqListDestory(SeqList* ps);
void CheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//在pos这里插入一个x
void SeqListErase(SeqList* ps, size_t pos);//删除数
void SeqListFind(SeqList* ps, SLDataType x);//查找x
size_t SeqListSize(SeqList* ps);
void SeqListRemove(SeqList* psl, SLDataType x);
int SeqListEmpty(SeqList* ps);//制空
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);//修改
void SeqListTest();
void SeqListTest2();
void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDataType x);
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x);//删除所有的x






