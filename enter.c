#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"admin.h"
#include"hotel.h"

int enter()
{
	int x;
	printf("            ��ѡ������Ҫ�ķ���\n\n");
	printf("              1.�����Ƶ���Ϣ\n");
	printf("              2.�鿴�Ƶ꼰������Ϣ\n");
	printf("              3.�鿴�ÿ���Ϣ\n");
	printf("              4.�ÿ���ס\n");
	printf("              5.�ÿͻ���\n");
	printf("              6.�ÿ��˷�\n");
	printf("              7.�˳���¼\n\n");
	printf("��ѡ��");
	scanf("%d", &x);
	if (x == 1)
	{
		return hotel();
	}
	return 4;
}

