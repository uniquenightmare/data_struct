#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
char *Mystrcat(char *strDestination, const char *strSource)
{
    char *p = strDestination;
	assert(strDestination != NULL);
	assert(strSource != NULL);
	while (*strDestination != '\0')
	{
		strDestination++;
	}
	while (*strSource != '\0')
	{
		*strDestination = *strSource;
		strDestination++;
		strSource++;
	}
	return p;
}
int main()
{
	char arr1[10] = { 0 };
	char arr2[10] = { 0 };
	printf("�������ַ���1��\n");
	scanf("%s", arr1);
	printf("�������ַ���2��\n");
	scanf("%s", arr2);
	Mystrcat(arr1, arr2);
	printf("%s\n", arr1);
	system("pause");
	return 0;
}
#endif