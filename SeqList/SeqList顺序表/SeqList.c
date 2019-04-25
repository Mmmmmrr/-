#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList* ps, size_t capacity)
{
	assert(ps);
	ps->_array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	ps->_size = 0;
	ps->_capacity = capacity;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_size = ps->_capacity = 0;
	}
}
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_array = realloc(ps->_array, ps->_capacity*sizeof(SLDataType));
		assert(ps->_array);
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps && ps->_size > 0);
	ps->_array[ps->_size - 1] = 0;
	ps->_size--;
}

void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->_size - 1;
	while (end >= 0)
	{
		ps->_array[end + 1] = ps->_array[end];
		--end;
	}
	ps->_array[0] = x;
	ps->_size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int begin = 0;
	while (begin < ps->_size-1)
	{
		ps->_array[begin] = ps->_array[begin+1];
		begin++;
	}
	ps->_size--;
}


void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && pos<=ps->_size);
	CheckCapacity(ps);
	int end = ps->_size - 1;
	while (end >=(int)pos)
	{
			ps->_array[end + 1] = ps->_array[end];
			--end;
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps &&pos<ps->_size);
	size_t begin = pos;
	while (begin<ps->_size-1 )
	{
		ps->_array[begin] = ps->_array[begin + 1];
		++begin;
	}
	--ps->_size;
}

void SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
			return i;
	}
	return -1;
}

size_t SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->_size;

}
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->_size > 0 ? 1 : 0;
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps&&pos<ps->_size);
	ps->_array[pos] = x;

}

void SeqListRemove(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListFind(ps, x);
	SeqListErase(ps, x);

}

void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);
	size_t end = ps->_size;
	while (end > 0)
	{
		for (size_t i = 1; i < ps->_size; i++)
		{
			if (ps->_array[i - 1]>ps->_array[i])
			{
				SLDataType tmp = ps->_array[i - 1];
				ps->_array[i - 1] = ps->_array[i];
				ps->_array[i] = tmp;
			}
		}
		end--;
	}
	
}

int SeqListBinaryFind(SeqList* ps, SLDataType x)
{
	assert(ps);
    int begin = 0;
	int end = ps->_size;
	while(begin<end)
	{
		int mid = (begin + end) / 2;
		if (ps->_array[mid] = x)
			return mid;
		else if (ps->_array[mid] > x)
		{
			end= mid ;
		}
		else
			begin = mid + 1;
	}
	return -1;
}

void SeqListRemoveAll(SeqList* ps, SLDataType x)
{
	assert(ps);
	int begin = 0;
	int end = ps->_size-1;
	while (begin <= end)
	{
		if (ps->_array[begin] == x)
		{
			if (ps->_array[end] != x)
			{
				SLDataType tmp = ps->_array[end];
				ps->_array[end] = ps->_array[begin];
				ps->_array[begin] = tmp;
				begin++;
				end--;
			}
			else
			{
				end--;
			}
		}
		else
		{
			begin++;
		}
			
		}
	ps->_size = end+1;
	}

void SeqListPrintf(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqListTest()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1); 
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4); 
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrintf(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrintf(&s);
	SeqListPushFront(&s, 0);
	SeqListPrintf(&s);
	SeqListPopFront(&s);
	SeqListPrintf(&s);
	SeqListErase(&s, 2);
	SeqListPrintf(&s);


	SeqListDestory(&s);

}
void SeqListTest2()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 8);
	SeqListPrintf(&s);
	//SeqListRemove(&s, 2);
	//SeqListPrintf(&s);
	//SeqListBubbleSort(&s);
	//SeqListPrintf(&s);
	//SeqListBinaryFind(&s, 5);
	//printf("%d\n", SeqListBinaryFind(&s, 5));
	SeqListRemoveAll(&s, 2);
	SeqListPrintf(&s);

	SeqListDestory(&s);
}