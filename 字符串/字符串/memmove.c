#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
void * Mymemmove(void * dest, const void * src, size_t count)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *p = (char *)(dest);
	char *q = (char *)src;
	void * ret = dest;
	if (p <= q || p >= ( q + count)) {
		while (count--) {
			*p = *q;
			p++;
			q++;
		}
	}
	else {
		
	
		while (count--) {
			*(p+count) = *(q+count);
		}
	}
	return ret;
}

int main()
{
	int arr1[10] = { 0 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };
	Mymemmove(arr2+2, arr2, 16);
	return 0;
}
#endif