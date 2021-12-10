#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#ifdef __GAME_H__
#define __GAME_H__

void DisplayBoard(char board[ROWS][COLS], int row, int col);
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);


#endif // __GAME_H__
