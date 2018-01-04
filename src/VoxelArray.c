#include "include/Project.h"

Block_t get_matrix_entry(Block_t *matrix, int x, int y, int z, int max_x, int max_y, int max_z)
{
	/*
	if (x >= max_x)
		exit(-1);
	if (y >= max_y)
		exit(-1);
	if (z >= max_z)
		exit(-1);
	*/

	return matrix[ (x) + (max_x * y) + (z * max_x * max_y) ];
}

void set_matrix_entry(Block_t *matrix, int x, int y, int z, Block_t val, int max_x, int max_y, int max_z)
{
	if (x >= max_x)
		exit(-1);
	if (y >= max_y)
		exit(-1);
	if (z >= max_z)
		exit(-1);

	matrix[ (x) + (max_x * y) + (z * max_x * max_y) ] = val;
}

void alloc_matrix_mem(Block_t **matrix, int max_x, int max_y, int max_z)
{
	*matrix = (Block_t *)malloc(max_x * max_y * max_z * sizeof(Block_t));
	if (matrix == NULL)
	{
		printf("[Error] Exiting Unable to Allocate Memory...\n");
		exit(-1);
	}
}
