#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"

int login()//��½
{
	int i,c=0;
	FILE *fp;
	struct ADMIN b;
	char name[10], code[13];
	printf("\n       �������û��������룡\n");
	printf("                       ����#����\n");
	printf("�û�����");
	scanf("%s", name);
	if (strcmp(name, "#") == 0)//����#����
		return welcome();
	
	fp = fopen("admin.txt", "r");
	fread(&b, sizeof(struct ADMIN), 1, fp); //����һ���ṹ���ַ��� ��b
	while (1)
	{
		if (strcmp(name, b.name)) /*������������*/
		{
			if (!feof(fp))    /*���δ���ļ�β*/
			{
				fread(&b, sizeof(struct ADMIN), 1, fp);
			}
			else
			{
				printf("���û���������,�����ԣ�\n");
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
		printf("���û������ڣ�");
		return login();
	}*/
	printf("���룺");
	scanf("%s", code);
	int c1 = 0;
	while (strcmp(code, b.code) != 0)
	{
		printf("��������ȷ�����룡������%d�λ��ᣡ\n", 3 - c1);
		printf("���룺");
		scanf("%s", code);
		
		if (c1 >= 3)
		{
			printf("�����������û�����");
			return login();
		}
		c1++;
	}
	fclose(fp);
	printf("��ϲ������¼�ɹ���\n");

	return enter();
}
