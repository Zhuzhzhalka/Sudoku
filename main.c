#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int
main(void)
{
    enum
    {
        VSIZE = 9
    };
	int deadlock = 0;
	int **v = calloc(VSIZE, sizeof(int *));
    for (int i = 0; i < VSIZE; i++) {
        v[i] = calloc(VSIZE, sizeof(int));
    }
	input_vec2d(v, VSIZE, VSIZE);
	solve(v, VSIZE, VSIZE, 0, 0, &deadlock);
	print_vec2d(v, VSIZE, VSIZE);
	return 0;
}
