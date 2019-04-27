#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* st, int n);
void StackDestory(Stack* st);

void StackPush(Stack* st, STDataType x);
void StackPop(Stack* st);

STDataType StackTop(Stack* st);

int StackSize(Stack* st);
int StackEmpty(Stack* st);

void StackPrint(Stack* st);
void StackTest();
