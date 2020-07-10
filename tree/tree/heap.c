#define  _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
void HeapInit(Heap *hp)
{
	hp->a = 0;
	hp->capacity = 0;
	hp->size = 0;
}
void Swap(HPDataType *p, HPDataType *q)
{
	HPDataType tmp = 0;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
void ShiftDown(HPDataType *a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n &&a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap *hp, HPDataType *a1, int n)
{
	assert(hp&&a1);
	int i = 0;
	hp->a = (HPDataType *)malloc(sizeof(HPDataType)* n);
	for (i = 0; i < n; i++)
	{
		hp->a[i] = a1[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		ShiftDown(hp->a, n, i);
	}
}
void HeapPush(Heap *hp, HPDataType x)
{
	if (hp->capacity == hp->size)
	{
		int newC = hp->capacity == 0 ? 10 : 2 * hp->capacity;
		hp->a = (HPDataType *)realloc(hp->a,sizeof(HPDataType)*newC);
		hp->capacity = newC;
	}
	hp->a[hp->size] = x;
	hp->size++;
	ShiftUp(hp->a, hp->size, hp->size - 1);
}
void ShiftUp(HPDataType *a, int n, int child)
{
	int parent = 0;
	int tmp = 0;
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (a[parent] < a[child])
		{
			tmp = a[parent];
			a[parent] = a[child];
			a[child] = a[parent];
			child = parent;
		}
		else
		{
			return;
		}
	}
}
void HeapPop(Heap *hp)
{
	int tmp = 0;
	if (hp->size == 0)
	{
		return;
	}
	Swap(hp->a[0], hp->a[hp->size - 1]);
	hp->size--;
	ShiftDown(hp->a, hp->size, 0);
}
void HeapDestory(Heap *hp)
{
	if (hp->a)
	{

	}
}
void HeapSort(int *a, int n)
{
	int i = 0;
	int end = n - 1;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(a, n, i);
	}
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		ShiftDown(a, end, 0);
		--end;
	}
	
}
