#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
void BubbleSort(int *a, int n)
{
	int i = 0;
	int j = 0;
	for (i = n; i >= 1; i--)
	{
		int falg = 0;
		for (j = 0; j < i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				falg = 1;
			}
		}
		if(falg == 1)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr,len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}
#endif