#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//函数声明
#ifdef __GAME_H__
#define __GAME_H__

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
//四种状态
// 1.玩家赢了 return '*'
// 2.电脑赢了 return '#'
// 3.平局 return 'Q'
// 4.继续 return 'C'
//

char IsWin(char board[ROW][COL], int row, int col);

#endif // !__GAME_H__

