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
			strcpy(a.r[i][j].situation, "����");
		}
	}//�����½��ùݵķ��䶼����
	struct room x;
	int num;
	int count;
	printf("      �����Ƶ���Ϣ\n");
	printf("������Ƶ����ƣ�");
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
			printf("�þƵ��Ѵ��ڣ������ԣ�\n");
			fclose(fp);
			return hotel();
		}
	}
	printf("�þƵ��ṩ36�䷿��\n");
	int z = 36;
	fclose(fp);
	static int i = 0;
	static int j = 0;
	while (z)
	{
		memset(b.r, 0, sizeof(b.r));
		printf("�����뷿�����ͣ�\n");
		scanf("%s", b.r[0][0].type);
		printf("����������ͷ��������\n");
		scanf("%d", &num);
		while (num > z)
		{
			printf("��������������������������ͷ��������\n");
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
	printf("��ϲ����%s�ѳɹ�ע�ᣡ\n", a.name);
	fp = fopen("hotel.txt", "a");
	fwrite(&a, sizeof(struct hotel), 1, fp);
	fclose(fp);
	return enter();
}