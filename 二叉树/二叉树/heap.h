#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, size_t n);
void HeapDeatory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void ADjustDown(HPDataType* a, size_t n, int root);
void Swap(int* a, int* b);
void HeapSort(int* a, int n);
void HeapPrint(Heap* hp);
void HeapTest();
void Topk();