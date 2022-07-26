#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"

int login()//登陆
{
	int i,c=0;
	FILE *fp;
	struct ADMIN b;
	char name[10], code[13];
	printf("\n       请输入用户名和密码！\n");
	printf("                       输入#返回\n");
	printf("用户名：");
	scanf("%s", name);
	if (strcmp(name, "#") == 0)//输入#返回
		return welcome();
	
	fp = fopen("admin.txt", "r");
	fread(&b, sizeof(struct ADMIN), 1, fp); //读入一个结构体字符块 到b
	while (1)
	{
		if (strcmp(name, b.name)) /*如果两串不相等*/
		{
			if (!feof(fp))    /*如果未到文件尾*/
			{
				fread(&b, sizeof(struct ADMIN), 1, fp);
			}
			else
			{
				printf("该用户名不存在,请重试！\n");
				fclose(fp);
				return login();
			}
		}
		else
			break;

	}
	/*for (i = 0; i < 10; i++)
	{
		if (strcmp(name, man[i].name) == 0)
		{
			c++;
			break;
		}
	}
	if (c == 0) 
	{
		printf("此用户不存在！");
		return login();
	}*/
	printf("密码：");
	scanf("%s", code);
	int c1 = 0;
	while (strcmp(code, b.code) != 0)
	{
		printf("请输入正确的密码！您还有%d次机会！\n", 3 - c1);
		printf("密码：");
		scanf("%s", code);
		
		if (c1 >= 3)
		{
			printf("请重新输入用户名！");
			return login();
		}
		c1++;
	}
	fclose(fp);
	printf("恭喜您，登录成功！\n");

	return enter();
}
