#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

typedef int BTDatatype;
typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	char _ch;
}BTNode;
typedef BTNode* QDataType;
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
int QueueSize(Queue* pq);
int QueueEmpty(Queue* pq);