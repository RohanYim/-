#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"

void Create_File1()
{
	FILE *fp;
	if ((fp = fopen("hotel.txt", "rb")) == NULL)
	{
		if ((fp = fopen("hotel.txt", "wb+")) == NULL)
		{
			printf("无法建立文件！");
		}
	}
}