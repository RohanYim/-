#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
void Create_File()
{
	FILE *fp;
	if ((fp = fopen("admin.txt", "rb")) == NULL)                 /*������ļ�������*/
	{
		if ((fp = fopen("admin.txt", "wb+")) == NULL)
		{
			printf("�޷������ļ�!");

		}
	}
}