
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
#error: ���Խ����Զ������������.
#line:  ���Զ��ƻ�����ļ����Լ������к�(__FILE__&__LINE__)
#pragma:����ָ������������ϵͳ�ض��ı���������(#pragma message ("str"))���ᱨ�������Ƿ����.
#pragma warning(disable:num):��������.
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
	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	return 0;

}