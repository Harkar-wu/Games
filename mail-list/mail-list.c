#include "mail-list.h"


void InitContact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

void AddContact(struct Contact* ps)
{
	if (ps->size >= MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("����������:>\n");
		scanf("%s", ps->date[ps->size].name);
		printf("����������:>\n");
		scanf("%d", &(ps->date[ps->size].age));
		printf("�������Ա�:>\n");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰:>\n");
		scanf("%s", ps->date[ps->size].tel);
		printf("�������ַ:>\n");
		scanf("%s", ps->date[ps->size].addr);
		
		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t %-4s\t %-5s\t %-12s\t %-20s\n","����","����","�Ա�","�绰","��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t %-4d\t %-5s\t %-12s\t %-20s\n", ps->date[i].name, ps->date[i].age, ps->date[i].sex, ps->date[i].tel, ps->date[i].addr);
		}
	}
}