#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
int _max(int *a, int size)
{
	int max = 0;
	int index;
	for (int i = 0; i < size; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int *a, int size)
{
	int * p = a;
	int i = 0;
	int len = size;
	int tmp;
	while (p != a + size)
	{
		int index = _max(p, len);
		tmp = p[index];
		p[index] = p[0];
		p[0] = tmp;
		p++;
		len--;
	}
}
int main()
{
	int arr[] = {1,10,8,9,3,2,4,5,7,6,10};
	int len = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}
#endif