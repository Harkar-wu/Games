#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};


//通讯录类型
struct Contact
{
	struct PeoInfo date[MAX];//存放1000个信息
	int size;//记录当前已经有的元素个数
};


enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};





void InitContact(struct Contact* ps);//初始化通讯录	

void AddContact(struct Contact* ps);//增加一个信息

void ShowContact(const struct Contact* ps);//显示通讯录信息

void DelContact(struct Contact* ps);//删除指定的联系人

void SearchContact(const struct Contact* ps);//查找指定人的信息

void ModifyContact(struct Contact* ps);//修改指定联系人

void SortContact(struct Contact* ps);//对通讯录进行排序

