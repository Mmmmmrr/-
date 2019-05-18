#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
//密集的集中在某个范围中   9900-10000
//方法：1.统计每个元素的个数、将元素进行回收
void CountSort(int* array, int size)
{
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i]>maxValue)
			maxValue = array[i];
		if (array[i] < minValue)
			minValue = array[i];
	}
	int range = maxValue - minValue + 1;
	int* pCount = (int*)malloc(sizeof(int)*range);
	assert(pCount);
	memset(pCount, 0, sizeof(int)*range);
	//统计元素个数
	for (int i = 0; i < size; ++i)
	{
		pCount[array[i] - minValue]++;
	}
	
	//对数据进行回收
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		int count = pCount[i];
		while (count--)
		{
			array[index++] = i + minValue;
		}
	}
	free(pCount);
}
void SortPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int array[] = { 9999, 9991, 9998, 9995, 9905, 9910, 9940, 9905, 9998, 9925, 9945 };
	int size = sizeof(array) / sizeof(array[0]);
	CountSort(array, size);
	SortPrint(array, size);
	system("pause");
	return 0;
}
//两数之和
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int* a = (int*)malloc(sizeof(int)* 2);
	for (int i = 0; i < numsSize - 1; ++i)
	{
		for (int j = i + 1; j <numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				a[0] = i;
				a[1] = j;
				break;
			}

		}
	}
	*returnSize = 2;
	return a;
}
//最小栈
typedef struct {
	Stack _st;
	Stack _min;

} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* st = (MinStack*)malloc(sizeof(MinStack));
	StackInit(&st->_st);
	StackInit(&st->_min);
	return st;

}

void minStackPush(MinStack* obj, int x) {
	StackPush(&obj->_st, x);
	if (StackEmpty(&obj->_min) == 0 || x<StackTop(&obj->_min))
	{
		StackPush(&obj->_min, x);
	}
	else
	{
		StackPush(&obj->_st, x);
	}

}

void minStackPop(MinStack* obj) {
	if (StackEmpty(&obj->_st) != 0 && StackEmpty(&obj->_min) != 0)
	{
		StackPop(&obj->_st);
		StackPop(&obj->_min);
	}
}

int minStackTop(MinStack* obj) {
	return StackTop(&obj->_st);

}

int minStackGetMin(MinStack* obj) {
	return StackTop(&obj->_min);
}

void minStackFree(MinStack* obj) {
	StackDestory(&obj->_st);
	StackDestory(&obj->_min);
	free(obj);
}
