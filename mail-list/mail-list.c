#include "mail-list.h"


static int FindByName(const struct Contact* ps,const char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


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
		printf("%-10s\t %-4s\t %-5s\t %-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t %-4d\t %-5s\t %-12s\t %-20s\n", ps->date[i].name, ps->date[i].age, ps->date[i].sex, ps->date[i].tel, ps->date[i].addr);
		}
	}
}



void DelContact(struct Contact* ps)
{
	char name[MAX_NAME]={0};
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//1.����Ҫɾ���˵�λ��
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����");
	}
	else
	{
		//2.ɾ������
		//�Ѻ����Ԫ����ǰ����
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}

}


void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME]={0};
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-10s\t %-4s\t %-5s\t %-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s\t %-4d\t %-5s\t %-12s\t %-20s\n", ps->date[ret].name, ps->date[ret].age, ps->date[ret].sex, ps->date[ret].tel, ps->date[ret].addr);
	}

}



void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
	}
	else
	{
		printf("����������:>\n");
		scanf("%s", ps->date[ret].name);
		printf("����������:>\n");
		scanf("%d", &(ps->date[ret].age));
		printf("�������Ա�:>\n");
		scanf("%s", ps->date[ret].sex);
		printf("������绰:>\n");
		scanf("%s", ps->date[ret].tel);
		printf("�������ַ:>\n");
		scanf("%s", ps->date[ret].addr);

		printf("�޸����\n");
	}
}

static int compar_age(const void* p1, const void* p2)
{
	struct Contact* pp1 = (struct Contact*)p1;
	struct Contact* pp2 = (struct Contact*)p2;
	return strcmp(pp1->date[pp1->size-1].name, pp2->date[pp2->size].name);
}

void SortContact(struct Contact* ps)
{
	qsort(ps, ps->size, sizeof(struct Contact), compar_age);
	printf("�������\n");
}