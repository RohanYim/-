#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"


int degister()//ע��
{
	int i;
	FILE *fp;
	struct ADMIN a,b;
	char code[13];
	int c1 = 0;
	printf("                 ע��\n");
	printf("                       ����#����\n");
	printf("�û�����");
	scanf("%s", a.name);
	if (strcmp(a.name, "#") == 0)//����#����
		return welcome();
	fp = fopen("admin.txt", "r");
	fread(&b, sizeof(struct ADMIN), 1, fp); //����һ���ṹ���ַ��� ��b

	while (1)
	{
		if (strcmp(a.name, b.name)) /*������������*/
		{
			if (!feof(fp))    /*���δ���ļ�β*/


			{
				fread(&b, sizeof(struct ADMIN), 1, fp);
			}
			else
				break;
		}
		else

		{
			printf("���û����Ѵ���,�����ԣ�\n");
			fclose(fp);
			return degister();
			
			
		}
	}
	/*for (i = 0; i < man_i; i++)
	{
		if (strcmp(man[man_i].name, man[i].name) == 0)
		{
			printf("���û����Ѵ���,�����ԣ�\n");
			return degister();
		}
	}*/
	printf("���֤�ţ�");
	scanf("%s", a.ID);
	printf("���룺");
	scanf("%s", a.code);
	printf("���ٴ��������룺");
	scanf("%s", code);
	while (strcmp(a.code, code) != 0)
	{
		printf("�������벻һ�£�������%d�λ��ᣡ\n",3-c1);
		printf("���ٴ��������룺");
		scanf("%s", code);
		c1++;
		if (c1 >= 3)
		{
			printf("ע��ʧ�ܣ������ԣ�\n");
			return degister();		
		}
	}
	printf("��ϲ�㣬ע��ɹ���\n");
	fclose(fp);
	fp = fopen("admin.txt", "a");
	fwrite(&a, sizeof(struct ADMIN), 2, fp);
	fclose(fp);
	return welcome();
}
