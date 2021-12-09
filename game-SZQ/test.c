#define _CRT_SECURE_NO_WARNINGS

#include "game.h"    //�����Լ���ͷ�ļ�

void menu()
{
	printf("************************************\n");
	printf("*****     1.play    0.exit     *****\n");
	printf("************************************\n");
}

void game()
{
	char ret = 0;
	//����һ����ά�����������Һ͵����߳���������Ϣ
	char board[ROW][COL] = {0};//ROW---�У�COL---��
	InitBoard(board,ROW,COL);//ʹ������ȫ����ո񣬳�ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)
	{
		
		PlayerMove(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);//�ж�����Ƿ�ʤ��
		if (ret != 'C')
		{
			break;
		}
		
		ComputerMove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);////�жϵ����Ƿ�ʤ��
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��1/0��:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);//0Ϊ�٣�һ�з�0��Ϊ��
	return 0;
}