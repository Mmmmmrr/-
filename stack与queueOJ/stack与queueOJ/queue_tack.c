#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef int QDataType;
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
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (pq->_tail == NULL)
	{
		pq->_tail = pq->_head = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* newhead = pq->_head->_next;
	free(pq->_head);
	pq->_head = newhead;
	if (newhead == NULL)
	{
		pq->_tail = NULL;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_head->_data;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->_head;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == NULL ? 0 : 1;
}

typedef struct {
	Queue _q1;
	Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&obj->_q1) != 0)
	{
		QueuePush(&obj->_q1, x);
	}
	else
		QueuePush(&obj->_q2, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* empty = &obj->_q1, *nonEmpty = &obj->_q2;
	if (QueueEmpty(&obj->_q1) != 0)
	{
		empty = &obj->_q2;
		nonEmpty = &obj->_q1;
	}
	while (QueueSize(nonEmpty) > 1)
	{
		QueuePush(empty, QueueFront(nonEmpty));
		QueuePop(nonEmpty);
	}
	int front = QueueFront(nonEmpty);
	QueuePop(nonEmpty);
	return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	Queue* empty = &obj->_q1, *nonEmpty = &obj->_q2;
	if (QueueEmpty(&obj->_q1) != 0)
	{
		empty = &obj->_q2;
		nonEmpty = &obj->_q1;
	}
	while (QueueSize(nonEmpty) > 1)
	{
		QueuePush(empty, QueueFront(nonEmpty));
		QueuePop(nonEmpty);
	}
	int front = QueueFront(nonEmpty);
	QueuePush(empty, front);
	QueuePop(nonEmpty);
	return front;
}

/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->_q1) + QueueEmpty(&obj->_q2) == 0 ? 0 : 1;
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->_q1);
	QueueDestory(&obj->_q2);
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/