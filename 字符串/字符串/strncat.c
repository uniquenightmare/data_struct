#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#if 0
char *Mystrncat(char *strDest, const char *strSource, size_t count)
{
	int i = 0;
	int ret = 0;
	char *p = strDest;
	assert(strDest != NULL);
	assert(strSource != NULL);
	while (*strDest != '\0')
	{
		strDest++;
	}
	for (i = 0; i < count; i++)
	{
		*strDest++ = *strSource++;
	}
	*strDest = '\0';
	return p;
	
	
}
int main()
{
	unsigned int num = 0;
	int ret = 0;
	char arr1[10] = { 0 };
	char arr2[10] = { 0 };
	printf("请输入你需要连接的字串长度\n");
	scanf("%u", &num);
	printf("请输入字符串1\n");
	scanf("%s", arr1); 
	printf("请输入字符串2\n");
	scanf("%s", arr2);
	ret = strlen(Mystrncat(arr1, arr2,num));
	printf("%s\n", arr1);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
#endif