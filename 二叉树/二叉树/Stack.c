#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void StackInit(Stack* st, int n)
{
	assert(st);
	st->_a = (STDataType*)malloc(sizeof(STDataType)*n);
	st->_top = 0;
	st->_capacity = n;
}


void StackDestory(Stack* st)
{
	assert(st);
		free(st->_a);
		st->_a = NULL;
		st->_top = 0;
	    st->_capacity = 0;
}

void StackPush(Stack* st, STDataType x)
{
	assert(st);
	if (st->_top == st->_capacity)
	{
		st->_a = (STDataType*)realloc(st->_a, st->_capacity * 2 * sizeof(STDataType));
		st->_capacity *= 2;
	}
	st->_a[st->_top] = x;
	st->_top++;
}


void StackPop(Stack* st)
{
	assert(st);
	if (st->_top > 0)
	{
		st->_top--;
	}
}

STDataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top-1];
}


int StackSize(Stack* st)
{
	assert(st);
	return st->_top;
}

int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 0 : 1;
}

void StackPrint(Stack* st)
{
	assert(st);
	while (StackEmpty(st) !=0)
	{
		printf("%d ", st->_a[st->_top-1]);
		StackPop(st);
	}
	printf("\n");
}

void StackTest()
{
	Stack st;
	StackInit(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 3);
	StackPush(&st, 2);
	StackPush(&st, 1);
	StackPrint(&st);

	
	StackDestory(&st);

}