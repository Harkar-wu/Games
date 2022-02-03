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
		printf("%-10s\t %-4s\t %-5s\t %-12s\t %-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t %-4d\t %-5s\t %-12s\t %-20s\n", ps->date[i].name, ps->date[i].age, ps->date[i].sex, ps->date[i].tel, ps->date[i].addr);
		}
	}
}



void DelContact(struct Contact* ps)
{
	char name[MAX_NAME]={0};
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//1.查找要删除人的位置
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("要删除的人不存在");
	}
	else
	{
		//2.删除数据
		//把后面的元素向前覆盖
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}

}


void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME]={0};
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-10s\t %-4s\t %-5s\t %-12s\t %-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-10s\t %-4d\t %-5s\t %-12s\t %-20s\n", ps->date[ret].name, ps->date[ret].age, ps->date[ret].sex, ps->date[ret].tel, ps->date[ret].addr);
	}

}



void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("要修改的联系人不存在\n");
	}
	else
	{
		printf("请输入名字:>\n");
		scanf("%s", ps->date[ret].name);
		printf("请输入年龄:>\n");
		scanf("%d", &(ps->date[ret].age));
		printf("请输入性别:>\n");
		scanf("%s", ps->date[ret].sex);
		printf("请输入电话:>\n");
		scanf("%s", ps->date[ret].tel);
		printf("请输入地址:>\n");
		scanf("%s", ps->date[ret].addr);

		printf("修改完成\n");
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
	printf("排序完成\n");
}