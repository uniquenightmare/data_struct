#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
char *Mystrstr(const char *string, const char *strCharSet)
{
	char *p = string;
	assert(string != NULL);
	assert(strCharSet != NULL);
	while (*string != '\0')
	{
		if (*strCharSet == *string)
		{
			strCharSet++;
			string++;
			if ((*strCharSet == '\0'))
			{
				return p;
			}
			
		}
		else
		{
			p++;
			string++;
		}
	}
	return NULL;
}
int main()
{
	char arr1[10] = { 0 };
	char arr2[10] = { 0 };
	char *ret = 0;
	printf("ÇëÊäÈë×Ö·û´®1\n");
	scanf("%s", arr1);
	printf("ÇëÊäÈë×Ö·û´®2\n");
	scanf("%s", arr2);
	ret = Mystrstr(arr1, arr2);
	printf("%s", ret);
	system("pause");
	return 0;
}
#endif
