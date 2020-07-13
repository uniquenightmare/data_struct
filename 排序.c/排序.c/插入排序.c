#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
void InsertSort(int *a, int n)
{
	assert(a);
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}

}
int main()
{
	int arr[] = { 1, 8, 6, 73, 76, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	
	system("pause");
	return 0;
}
#endif