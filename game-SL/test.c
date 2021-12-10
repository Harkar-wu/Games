#include "game.h"


void menu()
{
	printf("******************************\n");
	printf("****   1.play    0.exit   ****\n");
	printf("******************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//排查出的雷的信息


	InitBoard(mine, ROWS, COLS, ' ');//初始化游戏盘
	InitBoard(show, ROWS, COLS, '*');//初始化游戏盘
	DisplayBoard(show, ROW, COL);//打印游戏盘
	
	
	SetMine(mine, ROW, COL);//布置地雷
	FindMine(mine, show, ROW, COL);//扫雷

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择（1/0）:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}