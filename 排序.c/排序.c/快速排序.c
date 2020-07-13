#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
int getMid(int *arr, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (arr[mid] > arr[left])
	{
		if (arr[mid] < arr[right]) return mid;
		else
		{
			if (arr[left] > arr[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
	}
	else
	{
		if (arr[left] < arr[right])
		{
			return left;
		}
		else
		{
			if (arr[mid] > arr[right])
			{
				return mid;
			}
			else
			{
				return right;
			}
		}
	}
}
void swap(int *p, int *q)
{
	int tmp = 0;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
int QuitSort1(int *arr, int left, int right)
{
	int mid = getMid(arr, left, right);
	swap(&arr[left], &arr[mid]);
	int tmp = arr[left];
	while (left < right)
	{
		while (left < right&&arr[right] >= tmp)
		{
			right--;
		}
		arr[left] = arr[right];
		while (left < right &&arr[left] <= tmp)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = tmp;
	return left;
}
void QuitSort(int *arr, int left, int right)
{
	if (left >= right) return;
	int index = QuitSort1(arr, left, right);
	QuitSort(arr, left, index-1);
	QuitSort(arr, index + 1, right);
}
int largestPerimeter(int* A, int ASize){
	QuitSort(A, 0, ASize - 1);
	int i = 0;
	int ret = 0;
	for (i = ASize - 3; i >= 0; --i)
	{
		
		if (A[i] + A[i + 1] > A[i + 2])
		{
			ret = A[i] + A[i + 1] + A[i + 2];
			return ret;
		}
	}
	return 0;
}
int main()
{
	int arr[] = { 2, 1, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = largestPerimeter(arr, len);
	
	printf("%d ", ret);
	

	system("pause");
	return 0;
}
#endif
