#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType *a;
	int size;
	int capacity;
}Heap;
void HeapInit(Heap *hp);
void ShiftDown(HPDataType *a, int n, int root);
void HeapPush(Heap *hp, HPDataType x);