#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#if 0
void Merge_Sort(int *arr, int *num,int start,int mid,int end)
{
	int left_start = start;
	int left_end = mid;
	int right_start = mid + 1;
	int right_end = end;
	int index = start;
	while (left_start <= left_end&&right_start <= right_end)
	{
		if (arr[left_start] > arr[right_start])
		{
			num[index++] = arr[right_start++];
		}
		else
		{
			num[index++] = arr[left_start++];
		}
	}
	while (left_start <= left_end)
	{
		num[index++] = arr[left_start++];
	}
	while (right_start <= right_end)
	{
		num[index++] = arr[right_start++];
	}
	for (index = start; index <= end; index++)
	{
		arr[index] = num[index];
	}

}
void MergeSort(int *arr, int *num, int start, int end)
{
	if (start < end)
	{
		int mid = (end - start) / 2 + start;
		MergeSort(arr, num, start, mid);
		MergeSort(arr, num, mid+1, end);
		Merge_Sort(arr, num, start, mid, end);
	}
}

int main()
{
	int arr[] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int *num = (int *)malloc(sizeof(int)*len);
	MergeSort(arr,num,0,len-1);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}
#endif