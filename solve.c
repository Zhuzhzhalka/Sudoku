#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

void
input_vec2d(int **v, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%d", &v[i][j]);
		}
	}
}

void
print_vec2d(int**v, int rows, int cols)
{
	printf("%c", '\n');
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", v[i][j]);
		}
		printf("%c", '\n');
	}
}

int
line_match(int **v, int cols, int value, int cur_row, int cur_col)
{
	for (int h = 0; h < cols; h++) {
		if (v[cur_row][h] == value && cur_col != h) {
            return 1;
        }
	}
	return 0;
}

int
row_match(int **v, int rows, int value, int cur_row, int cur_col)
{
	for (int h = 0; h < rows; h++) {
		if (v[h][cur_col] == value && cur_row != h) {
            return 1;
        }
	}
	return 0;
}

int
block_match(int **v, int rows, int cols, int value, int cur_row, int cur_col)
{
	int block_num = cur_row / 3 * 3 + cur_col / 3;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int cur_block_num = i / 3 * 3 + j / 3;
			if (cur_block_num == block_num && v[i][j] == value) {
                return 1;
            }
		}
	}
	return 0;
}

void
solve(int **v, int rows, int cols, int prev_row, int prev_col, int *deadlock)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (v[i][j] == 0) {
				int is_inserted = 0;
				for (int k = 1; k <= cols; k++) {
					if (!line_match(v, cols, k, i, j) && !row_match(v, rows, k, i, j) 
                            && !block_match(v, rows, cols, k, i, j)) {
						v[i][j] = k;
						is_inserted = 1;
						*deadlock = 0;
						solve(v, rows, cols, i, j, deadlock);
					}
				}
				if (*deadlock == 1) {
					v[prev_row][prev_col] = 0;
					return;
				}
				if (!is_inserted) {
					*deadlock = 1;
					v[prev_row][prev_col] = 0;
					return;
				}
			} 
		}
	}
	return;
}
