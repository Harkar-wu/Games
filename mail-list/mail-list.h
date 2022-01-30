#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>


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


#ifdef __MAIL-LIST_H__
#define __MAIL-LIST_H__

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
#endif // DEBUG

