#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#if 0
char *Mystrncpy(char *strDest, const char *strSource, size_t count)
{
	int i = 0;
	char *p = strDest;
	assert(strDest != NULL&& strSource != NULL);
	for (i = 0; i < count; i++)
	{
		*strDest = *strSource;
		strDest++;
		strSource++;
	}
	return p;
}
int main()
{
	char arr1[10] = { 0 };
	char arr2[10] = { 0 };
	int ret = 0;
	printf("ÇëÊäÈë×Ö·û´®1\n");
	scanf("%s", arr1);
	printf("ÇëÊäÈë×Ö·û´®2\n");
	scanf("%s", arr2);
	printf("ÇëÊäÈë¸öÊý\n");
	scanf("%d", &ret);
	Mystrncpy(arr1, arr2, ret);
	printf("%s\n", arr1);
	/*strncpy(arr1, arr2, ret);
	printf("%s\n", arr1);*/
	system("pause");
	return 0;
}
#endif