#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
int Mystrcmp(const char *string1, const char *string2)
{
	int sum2 = 0;
	int sum1 = 0;
	assert(string1 != NULL);
	assert(string2 != NULL);
	while (*string1 == *string2)
	{
		if ((*string1 == '\0') )
		{
			return 0;
		}
		string1++;
		string2++;
	}
	if (*string1 > *string2)
	{
		return 1;
	}

	{
		return -1;
	}
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
	ret = Mystrcmp(arr1, arr2);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
#endif