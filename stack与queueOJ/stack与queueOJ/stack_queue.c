#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	size_t _top;
	size_t _capacity;
}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = realloc(ps->_a, sizeof(STDataType)*newcapacity);
		assert(ps->_a);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top >0);
	--ps->_top;

}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top >0);
	return ps->_a[ps->_top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&queue->pushST);
	StackInit(&queue->popST);
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popST) == 0)
	{
		while (StackEmpty(&obj->pushST) != 0)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int top = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST) == 0)
	{
		while (StackEmpty(&obj->pushST) != 0)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) + StackEmpty(&obj->popST) == 0 ? 0 : 1;
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/