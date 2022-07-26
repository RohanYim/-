#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"

int enter()
{
	int x;
	printf("            请选择您需要的服务\n\n");
	printf("              1.创建酒店信息\n");
	printf("              2.查看酒店及房间信息\n");
	printf("              3.查看旅客信息\n");
	printf("              4.旅客入住\n");
	printf("              5.旅客换房\n");
	printf("              6.旅客退房\n");
	printf("              7.退出登录\n\n");
	printf("请选择：");
	scanf("%d", &x);
	if (x == 1)
	{
		return hotel();
	}
	return 4;
}

