#include<stdio.h>
#include<time.h>
#include<string.h>
int welcome()//��ӭ
{
	int a;
	printf("************************************************\n\n");
	printf("         ��ӭ����606���ʻ�԰��ׯ����ϵͳ\n\n");
	printf("************************************************\n");
	printf("                  1.��¼\n");
	printf("                  2.ע��\n");
	printf("                  3.�˳�\n");
	printf("��ѡ��");
	scanf("%d", &a);
	switch (a)
	{
	case 1:login(); break;//��¼����
	case 2:degister();break;//ע�ắ��
	case 3:return 0;
	default:return 0;
	}
	return 1;

}
