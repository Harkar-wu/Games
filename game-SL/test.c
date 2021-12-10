#include "game.h"


void menu()
{
	printf("******************************\n");
	printf("****   1.play    0.exit   ****\n");
	printf("******************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//���úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//�Ų�����׵���Ϣ


	InitBoard(mine, ROWS, COLS, ' ');//��ʼ����Ϸ��
	InitBoard(show, ROWS, COLS, '*');//��ʼ����Ϸ��
	DisplayBoard(show, ROW, COL);//��ӡ��Ϸ��
	
	
	SetMine(mine, ROW, COL);//���õ���
	FindMine(mine, show, ROW, COL);//ɨ��

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��1/0��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}