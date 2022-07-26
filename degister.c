#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"


int degister()//注册
{
	int i;
	FILE *fp;
	struct ADMIN a,b;
	char code[13];
	int c1 = 0;
	printf("                 注册\n");
	printf("                       输入#返回\n");
	printf("用户名：");
	scanf("%s", a.name);
	if (strcmp(a.name, "#") == 0)//输入#返回
		return welcome();
	fp = fopen("admin.txt", "r");
	fread(&b, sizeof(struct ADMIN), 1, fp); //读入一个结构体字符块 到b

	while (1)
	{
		if (strcmp(a.name, b.name)) /*如果两串不相等*/
		{
			if (!feof(fp))    /*如果未到文件尾*/


			{
				fread(&b, sizeof(struct ADMIN), 1, fp);
			}
			else
				break;
		}
		else

		{
			printf("该用户名已存在,请重试！\n");
			fclose(fp);
			return degister();
			
			
		}
	}
	/*for (i = 0; i < man_i; i++)
	{
		if (strcmp(man[man_i].name, man[i].name) == 0)
		{
			printf("该用户名已存在,请重试！\n");
			return degister();
		}
	}*/
	printf("身份证号：");
	scanf("%s", a.ID);
	printf("密码：");
	scanf("%s", a.code);
	printf("请再次输入密码：");
	scanf("%s", code);
	while (strcmp(a.code, code) != 0)
	{
		printf("密码输入不一致！您还有%d次机会！\n",3-c1);
		printf("请再次输入密码：");
		scanf("%s", code);
		c1++;
		if (c1 >= 3)
		{
			printf("注册失败，请重试！\n");
			return degister();		
		}
	}
	printf("恭喜你，注册成功！\n");
	fclose(fp);
	fp = fopen("admin.txt", "a");
	fwrite(&a, sizeof(struct ADMIN), 2, fp);
	fclose(fp);
	return welcome();
}
