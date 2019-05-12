#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
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
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity*2;
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
	assert(ps&& ps->_top >0);
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
void TestStack()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	while (StackEmpty(&st) != 0)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

}
int main()
{
	TestStack();
	system("pause");
	return 0;

}
