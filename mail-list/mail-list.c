#include "mail-list.h"


void InitContact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;//设置通讯录最初只有0个元素
}

void AddContact(struct Contact* ps)
{
	if (ps->size >= MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入名字:>\n");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入年龄:>\n");
		scanf("%d", &(ps->date[ps->size].age));
		printf("请输入性别:>\n");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话:>\n");
		scanf("%s", ps->date[ps->size].tel);
		printf("请输入地址:>\n");
		scanf("%s", ps->date[ps->size].addr);
		
		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t %-4s\t %-5s\t %-12s\t %-20s\n","名字","年龄","性别","电话","地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t %-4d\t %-5s\t %-12s\t %-20s\n", ps->date[i].name, ps->date[i].age, ps->date[i].sex, ps->date[i].tel, ps->date[i].addr);
		}
	}
}