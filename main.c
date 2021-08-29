#include <stdio.h>
#include <stdlib.h>

#define VSIZE 9

void input_vec2d(int (*v)[VSIZE])
{
	for (int i = 0; i < VSIZE; i++)
	{
		for (int j = 0; j < VSIZE; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}
}

void print_vec2d(int (*v)[VSIZE])
{
	printf("%c", '\n');
	for (int i = 0; i < VSIZE; i++)
	{
		for (int j = 0; j < VSIZE; j++)
		{
			printf("%d ", v[i][j]);
		}
		printf("%c", '\n');
	}
}

int line_match(int (*v)[VSIZE],  int value, int line, int row)
{
	for (int h = 0; h < VSIZE; h++)
	{
		if (v[line][h] == value && row != h)
			return 1;
	}
	return 0;
}

int row_match(int (*v)[VSIZE], int value, int line, int row)
{
	for (int h = 0; h < VSIZE; h++)
	{
		if (v[h][row] == value && line != h)
			return 1;
	}
	return 0;
}

int block_match(int (*v)[VSIZE], int value, int line, int row)
{
	int block_num = line / 3 * 3 + row / 3;
	for (int i = 0; i < VSIZE; i++)
	{
		for (int j = 0; j < VSIZE; j++)
		{
			int cur_block_num = i / 3 * 3 + j / 3;
			if (cur_block_num == block_num && v[i][j] == value)
				return 1;
		}
	}
	return 0;
}

void solve(int (*v)[VSIZE], int prev_line, int prev_row, int *deadlock)
{
	for (int line = 0; line < VSIZE; line++)
	{
		for (int row = 0; row < VSIZE; row++)
		{
			if (v[line][row] == 0)
			{
				int is_inserted = 0;
				for (int k = 1; k <= VSIZE; k++)
				{
					if (!line_match(v, k, line, row) && !row_match(v, k, line, row) && !block_match(v, k, line, row))
					{
						v[line][row] = k;
						is_inserted = 1;
						*deadlock = 0;
						solve(v, line, row, deadlock);
					}
				}
				if (*deadlock == 1)
	        	{
					v[prev_line][prev_row] = 0;
					return;
				}
				if (!is_inserted)
				{
					*deadlock = 1;
					v[prev_line][prev_row] = 0;
					return;
				}
			} 
		}
	}
	return;
}

int main(void)
{
	int f = 0;
	static int v[VSIZE][VSIZE];
	input_vec2d(v);
	solve(v, 0, 0, &f);
	print_vec2d(v);
	return 0;
}
