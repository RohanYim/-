#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"

void roomcreate_file()
{
	FILE *fp;
	if ((fp = fopen("hot[hoteltype].name.txt", "rb")) == NULL)
	{
		if ((fp = fopen("hot[hoteltype].name.txt", "wb+")) == NULL)
		{
			printf("�޷������ļ���");
		}
	}

}