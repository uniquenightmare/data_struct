#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
void *Mymemcpy(void *dest, const void *src, size_t num)
{
	char *p = (char *)(dest);
	char *q = (char *)src;
	void *ret = dest;
	while (num--)
	{
		*p = *q;
		p++;
		q++;
	}
	return ret;
}
int main()
{
	char arr1[] = { 0 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };
	Mymemcpy(arr2 + 2, arr2, 16);
	system("pause");
	return 0;
}
#endif