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
void HillSort(int *a1, int size)
{
	int gap = size ;
	int *a = a1;
	while (gap > 0)
	{
		gap = gap / 2;
		a = a1;
		while (a + gap != a1 + size)
		{
			
			if (*a > *(a + gap))
			{
				int tmp = *a;
				*a = *(a + gap);
				*(a + gap) = tmp;
			
			}
			a++;
		}
		
	}
}
int main()
{
	int arr[] = { 9,1,2,5,7,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HillSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	InsertSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
#endif