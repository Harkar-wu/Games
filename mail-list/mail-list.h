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


//ͨѶ¼����
struct Contact
{
	struct PeoInfo date[MAX];//���1000����Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
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





void InitContact(struct Contact* ps);//��ʼ��ͨѶ¼	

void AddContact(struct Contact* ps);//����һ����Ϣ

void ShowContact(const struct Contact* ps);//��ʾͨѶ¼��Ϣ

void DelContact(struct Contact* ps);//ɾ��ָ������ϵ��

void SearchContact(const struct Contact* ps);//����ָ���˵���Ϣ

void ModifyContact(struct Contact* ps);//�޸�ָ����ϵ��

void SortContact(struct Contact* ps);//��ͨѶ¼��������

