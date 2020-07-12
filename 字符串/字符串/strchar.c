#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
char *Mystrchr(const char *string, int c)
{
	char *p = string;
	assert(string != NULL);
	while (*p != '\0')
	{
		if (*p == c)
		{
			return p;
		}
		p++;
	}
	return NULL;
}
int main()
{
	int ch = 'd';
	char arr[] = "arsssdada";
	char *result = 0;
	result = Mystrchr(arr, ch);
	printf("%s", result);
	system("pause");
	return 0;
}
#endif