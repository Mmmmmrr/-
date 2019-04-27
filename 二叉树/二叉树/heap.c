#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

void ADjustDown(HPDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找左右孩子小的
		if (child + 1<n &&
			a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, size_t n)
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, sizeof(HPDataType)*n);
	for (int i = (hp->_size - 2) / 2; i >= 0; --i)    //hp->_size-1-1/2
	{
		ADjustDown(hp->_array, hp->_size, i);
	}

}




void HeapDeatory(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = hp->_capacity = 0;
}

void ADjustUp(HPDataType* a, size_t n, size_t child)
{
	assert(a);
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity*sizeof(HPDataType));
		assert(hp->_array);
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	//调堆
	ADjustUp(hp->_array, hp->_size, hp->_size - 1);
}


void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	ADjustDown(hp->_array, hp->_size, 0);
}


HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}



int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}


void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		ADjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		ADjustDown(a, end, 0);
		end--;
	}
}

void Topk()
{
	const size_t N = 100000;
	const size_t k = 10;
	size_t * a = (size_t*)malloc(sizeof(size_t)*N);
	for (size_t i = 0; i < N; i++)
	{
		a[i] = rand()%100000;
	}
	a[6] = 100001;
	a[7] = 100003;
	a[9] = 100004;
	a[22] = 100008;
	a[88] = 100007;
	a[79] = 100006;
	a[46] = 100005;
	a[99] = 100004;
	a[55] = 100002;
	a[100] = 100009;


	Heap hp;
	HeapInit(&hp, a, k);
	for (size_t i = k; i < N; i++)
	{
		if (HeapTop(&hp) < a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);

}


void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void HeapTest()
{
	int a[10] = { 2, 7, 8, 0, 0, 7, 5, 3, 7, 9 };
	/*Heap hp;
	HeapInit(&hp, a, sizeof(a)/sizeof(int));
	HeapPrint(&hp);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
    HeapPop(&hp);
	HeapPrint(&hp);*/
	Topk();


	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//HeapPrint(&hp);


	//HeapDeatory(&hp);
}