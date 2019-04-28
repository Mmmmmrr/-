#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"


void InsertSort(int* a, int n)
{
	for (int i = 0; i<n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
	
}



void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//
//
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//在左右孩子选择大的
//		if (child + 1 < n &&a[child + 1] > a[child])
//		{
//			child++;
//		}
//		if (a[parent] < a[child])
//		{
//			int tmp = a[parent];
//			a[parent] = a[child];
//			a[child] = tmp;
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//
//void HeapSort(int* a, int n)
//{
//	//建大堆
//	for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	//选数
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}
//
//
//void SelectSort(int* a, int n)
//{
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int min = begin;
//		int max = end;
//		for (int i = begin; i <= end; i++)
//		{
//
//			if (a[i]<a[min])
//			{
//				min = i;
//			}
//			if (a[i]>a[max])
//			{
//				max = i;
//			}
//		}
//		Swap(&a[begin], &a[min]);
//		if (max == begin)
//		{
//			max = min;
//		}
//		Swap(&a[end], &a[max]);
//		++begin;
//		--end;
//	}
//}
//
//
//void BubbleSort(int* a, int n)
//{
//	int end = n ;
//	while (end > 0)
//	{  
//		int exchange = 0;
//		for (int i = 0; i < end-1; i++)
//		{
//			if (a[i] > a[i + 1])
//			{
//				Swap(&a[i], &a[i + 1]);
//				exchange = 1;
//			}
//		}
//		end--;
//	}
//}
int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
			--end;
		while (begin < end && a[begin] <= a[key])
			++begin;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
	return begin;
}


void QuickSort(int*a, int left, int right)
{
	
	if (left >= right)
		return;
	/*if (right - left > 10)
	{*/
		int div = PartSort1(a, left, right);
		QuickSort(a, left, div-1);
		QuickSort(a, div + 1, right);
	/*}
	 else
	{InsertSort(a + left, right -left + 1);
	}*/

}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[end] < a[mid])
			return mid;
		else if (a[end] > a[begin])
			return begin;
		else
			return end;
	}
}

int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = a[begin];
	while (begin < end)
	{
		while (begin<end && a[end] > key)
		{
			--end;
			a[begin] = a[end];
		}
		while (begin < end && a[begin] < key)
		{
			++begin;
			a[end] = a[begin];
		}
	}
	a[begin] = key;
	return begin;
}

void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left > 10)
	{
		int div = PartSort2(a, left, right);
		QuickSort2(a, left, div - 1);
		QuickSort2(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int cur = begin + 1;
	int prev = begin;
	int key = a[begin];
	while (cur <= end)
	{
		if (a[cur] < key)
		{
			Swap(&a[prev++], &a[cur]);
			cur++;
		}
	}
	Swap(&a[prev], &key);
	return prev;
}

void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left > 10)
	{
		int div = PartSort3(a, left, right);
		QuickSort3(a, left, div - 1);
		QuickSort3(a, div + 1, right);
	}
}
//
//void QuickSortNonr(int* a, int left, int right)
//{
//
//
//}
//
////归并排序
//
//void _MergeSort(int* a, int begin, int end, int* tmp)
//{
//	if (begin >= end)
//		return;
//	int mid = begin + ((end - begin) >> 1);
//	_MergeSort(a, begin,mid , tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int index = begin;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//			tmp[index++] = a[begin1++];
//		else
//		{
//			tmp[index++] = a[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[index++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[index++] = a[begin2++];
//	}
//	index = begin;
//	while (begin <= end)
//	{
//		a[begin++] = tmp[index++];
//	}
//}
//
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)*n);
//	_MergeSort(a, 0, n - 1, tmp);
//	free(tmp);
//}
//
////计数排序
//void CountSort(int* a, int n)
//{
//	int max = a[0];
//	int min = a[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i]>max)
//			max = a[i];
//		if (a[i] < min)
//			min = a[i];
//	}
//	int range = max - min + 1;
//	int* count = (int*)malloc(sizeof(int)*n);
//	memset(count, 0, sizeof(int)*range);
//	for (int i = 0; i < n; i++)
//	{
//		count[a[i]-min]++;
//	}
//	int j = 0;
//	for (int i = 0; i < range; i++)
//	{
//		while (count[i]--)
//		{
//			a[j++] = i + min;
//		}
//	}
//}
//
//

void SortPrint(int* a, int n)
{
	for (int i = 0;  i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void SortTest()
{
	int a[] = { 1, 8, 9, 7, 4, 5, 2, 3, 6, 0};
	//InsertSort(a, sizeof(a) / sizeof(int));
	//SortPrint(a, sizeof(a) / sizeof(int));
	/*ShellSort(a, sizeof(a) / sizeof(int));
	SortPrint(a, sizeof(a) / sizeof(int));*/
	//HeapSort(a, sizeof(a) / sizeof(int));
	//SortPrint(a, sizeof(a) / sizeof(int));
	//SelectSort(a, sizeof(a) / sizeof(int));
	//SortPrint(a, sizeof(a) / sizeof(int));
	////BubbleSort(a, sizeof(a) / sizeof(int));
	////SortPrint(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, (sizeof(a) / sizeof(int))-1);
	SortPrint(a, sizeof(a) / sizeof(int));

	/*QuickSort2(a, 0, (sizeof(a) / sizeof(int)) - 1);
	SortPrint(a, sizeof(a) / sizeof(int));

	QuickSort3(a, 0, (sizeof(a) / sizeof(int)) - 1);
	SortPrint(a, sizeof(a) / sizeof(int));*/
	
	////MergeSort(a, sizeof(a) / sizeof(int));
	////SortPrint(a, sizeof(a) / sizeof(int));
	//CountSort(a, sizeof(a) / sizeof(int));
	//SortPrint(a, sizeof(a) / sizeof(int));




}