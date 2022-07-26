#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
void Create_File()
{
	FILE *fp;
	if ((fp = fopen("admin.txt", "rb")) == NULL)                 /*如果此文件不存在*/
	{
		if ((fp = fopen("admin.txt", "wb+")) == NULL)
		{
			printf("无法建立文件!");

		}
	}
}