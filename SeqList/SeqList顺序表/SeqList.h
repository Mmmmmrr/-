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
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//��pos�������һ��x
void SeqListErase(SeqList* ps, size_t pos);//ɾ����
void SeqListFind(SeqList* ps, SLDataType x);//����x
size_t SeqListSize(SeqList* ps);
void SeqListRemove(SeqList* psl, SLDataType x);
int SeqListEmpty(SeqList* ps);//�ƿ�
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);//�޸�
void SeqListTest();
void SeqListTest2();
void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x);//ɾ�����е�x






