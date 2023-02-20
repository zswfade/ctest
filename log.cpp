
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
#error: 可以进行自定义编译器报错.
#line:  可以定制化你的文件名以及代码行号(__FILE__&__LINE__)
#pragma:用于指定计算机或操作系统特定的编译器功能(#pragma message ("str"))不会报错条件是否存在.
#pragma warning(disable:num):消除警告.
*/
int Recordlog(void)
{
	FILE* pf = fopen("log.txt", "a+");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	fprintf(pf, "%s %d %s %s %s\n", __FILE__, __LINE__, __DATE__, __TIME__, __FUNCTION__);
	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;

}