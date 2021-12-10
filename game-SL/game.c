#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	printf("  ");
	for (j = 1; j <= col; j++)
	{
		printf("  %d ",j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			
			printf(" %c ",board[i][j]);
			if (j <= col - 1)
				printf("|");
			else
				printf("\n");
		}
		if (i <= row - 1)
		{
			printf("   ");
			for (j = 1; j <= col; j++)
			{
				printf("---");
				if (j <= col - 1)
					printf("-");
				else
					printf("\n");
			}
		}
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int i = 0;
	for(i=0;i<count;i++)
	{
		int a = rand() % row + 1;
		int b = rand() % col + 1;
		if (board[a][b] == ' ')
		{
			board[a][b] = 'X';
		}
		else
			i--;
	}
}

int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = x-1; i <= x+1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == 'X')
			{
				count++;
			}
		}
	}
	return count;
}

int Find(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int row,int col)
{
	int i = 0;
	int j = 0;
	int win=0;
	int count = 0;
	while (win < row*col - EASY_COUNT)
	{
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if (mine[x][y] == 'X')
			{
				DisplayBoard(mine, row, col);
				return -1;
			}
			else
			{
				//计算坐标周围有几个雷
				count = get_mine_count(mine, x, y);
				if (count != 0)
				{
					show[x][y] = '0' + count;
					win++;
					DisplayBoard(show, row, col);
					break;
				}
				else
				{
					for (i = x - 1; i <= x + 1; i++)
					{
						
						for (j = y - 1; j <= y + 1; j++)
						{
							
							if (show[i][j] =='*')
							{
								int c= get_mine_count(mine, i, j);
								if (c == 0)
								{
									show[i][j] = mine[i][j];
									win++;
								}
								else
								{
									show[i][j] = '0' + c;
									win++;
								}
								//Find(mine,show,i,j,row,col);
							}
						}
					}

					DisplayBoard(show, row, col);
					break;
				}

			}

		}
		
	}
	return win;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	int i = 0;
	int j = 0;
	int count = 0;
	int win = 0;
	int sum = 0;
	while (1)
	{
		printf("请输入坐标\n");
		scanf("%d %d", &i, &j);
		if ((i >= 1 && i <= row && j >= 1 && j <= col)&&(show[i][j]=='*'))
		{
			win=Find(mine, show, i, j, row, col);
			sum += win;
			if (sum == row * col - EASY_COUNT)
			{
				printf("恭喜你排雷成功\n");
				break;
			}
			if (win == -1)
			{
				printf("很遗憾！你被炸死了\n");
				break;
			}
		}
		else
		{
			printf("输入坐标错误，请重新输入！\n");

		}
		
	}

}