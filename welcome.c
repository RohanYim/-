#include<stdio.h>
#include<time.h>
#include<string.h>
int welcome()//欢迎
{
	int a;
	printf("************************************************\n\n");
	printf("         欢迎来到606国际花园酒庄管理系统\n\n");
	printf("************************************************\n");
	printf("                  1.登录\n");
	printf("                  2.注册\n");
	printf("                  3.退出\n");
	printf("请选择：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:login(); break;//登录函数
	case 2:degister();break;//注册函数
	case 3:return 0;
	default:return 0;
	}
	return 1;

}
