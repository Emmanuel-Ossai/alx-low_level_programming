#include "main.h"
#include <stdlib.h>

/**
 * free_grid - a C function that frees a 2 dimensional grid
 * previously created by your alloc_grid function.
 * @grid: the address of the two dimensional grid
 * @height: the height of the grid
 *
 * Return: 0
 */


void free_grid(int **grid, int height)
{
	int x;

	for (x = 0; x < height; x++)
		free(grid[x]);
	free(grid);
}
