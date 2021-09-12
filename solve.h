#ifndef SOLVE_H
#define SOLVE_H


void
input_vec2d(int **v, int rows, int cols);

void
print_vec2d(int**v, int rows, int cols);

int
line_match(int **v, int cols, int value, int cur_row, int cur_col);

int
row_match(int **v, int rows, int value, int cur_row, int cur_col);

int
block_match(int **v, int rows, int cols, int value, int cur_row, int cur_col);

void
solve(int **v, int rows, int cols, int prev_row, int prev_col, int *deadlock);

#endif
