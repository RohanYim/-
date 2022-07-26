#include"hotel.h"
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"

int hotel()
{
	FILE *fp;
	struct hotel a,b,c;
	memset(a.r, 0, sizeof(a.r));
	
	memset(a.name, 0, sizeof(a.name));
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			strcpy(a.r[i][j].situation, "无人");
		}
	}//所有新建旅馆的房间都无人
	struct room x;
	int num;
	int count;
	printf("      创建酒店信息\n");
	printf("请输入酒店名称：");
	scanf("%s", a.name);
	if (strcmp(a.name, "#") == 0)
	{
		return enter();
	}
	fp = fopen("hotel.txt", "r");
	fread(&c, sizeof(struct hotel), 1, fp);
	while (1)
	{
		if (strcmp(a.name, c.name))
		{
			if (!feof(fp))
			{
				fread(&c, sizeof(struct hotel), 1, fp);
			}
			else 
				break;
		}
		else
		{
			printf("该酒店已存在，请重试！\n");
			fclose(fp);
			return hotel();
		}
	}
	printf("该酒店提供36间房。\n");
	int z = 36;
	fclose(fp);
	static int i = 0;
	static int j = 0;
	while (z)
	{
		memset(b.r, 0, sizeof(b.r));
		printf("请输入房间类型：\n");
		scanf("%s", b.r[0][0].type);
		printf("请输入该类型房间个数：\n");
		scanf("%d", &num);
		while (num > z)
		{
			printf("房间数超出，请重新输入该类型房间个数：\n");
			scanf("%d", &num);
		}
		z = z - num;
		count = 0;
		
		for (; i < 6; )
		{
			for (;j<6; j++)
			{
				strcpy(a.r[i][j].type, b.r[0][0].type);
				count++;
				if (j == 5)
				{
					i++;
					j = 0;
					break;
				}
				if (count == num)
				{
					j++;
					break;
				}
			}
			if (count== num)
			{
				break;
			}
		}
	}
	i = 0;
	j = 0;
	printf("恭喜您，%s已成功注册！\n", a.name);
	fp = fopen("hotel.txt", "a");
	fwrite(&a, sizeof(struct hotel), 1, fp);
	fclose(fp);
	return enter();
}