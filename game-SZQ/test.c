#define _CRT_SECURE_NO_WARNINGS

#include "game.h"    //引用自己的头文件

void menu()
{
	printf("************************************\n");
	printf("*****     1.play    0.exit     *****\n");
	printf("************************************\n");
}

void game()
{
	char ret = 0;
	//创建一个二维数组来存放玩家和电脑走出的棋盘信息
	char board[ROW][COL] = {0};//ROW---行，COL---列
	InitBoard(board,ROW,COL);//使数组内全部变空格，初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)
	{
		
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);//判断玩家是否胜利
		if (ret != 'C')
		{
			break;
		}
		
		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);////判断电脑是否胜利
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择（1/0）:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);//0为假，一切非0均为真
	return 0;
}