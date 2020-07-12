#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
int Mystrncmp(const char *string1, const char *string2, size_t count)
{
	int i = 0;
	assert(string1 != NULL);
	assert(string2 != NULL);
	for (i = 0; i < count; i++)
	{
		if ((*string1 == *string2) && (i = count-1))
		{
			return 0;
		}
		else
		{
			break;
		}
		string1++;
		string2++;
	}
	if (*string1 > *string2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	
}
int main()
{
	char arr1[10] = { 0 };
	char arr2[10] = { 0 };
	int num = 0;
	int ret = 0;
	printf("ÇëÊäÈë×Ö·û´®1\n");
	scanf("%s",arr1);
	printf("ÇëÊäÈë×Ö·û´®2\n");
	scanf("%s",arr2);
	printf("ÇëÊäÈë¸´ÖÆ¸öÊı\n");
	scanf("%d", &num);
	ret = Mystrncmp(arr1, arr2, num);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
#endif