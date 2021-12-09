#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//��������
#ifdef __GAME_H__
#define __GAME_H__

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
//����״̬
// 1.���Ӯ�� return '*'
// 2.����Ӯ�� return '#'
// 3.ƽ�� return 'Q'
// 4.���� return 'C'
//

char IsWin(char board[ROW][COL], int row, int col);

#endif // !__GAME_H__

