#include "fm_main.h"

/**
 * mem_alloc_error - to handle dynamic
 * memory allocation error.
 * @s: the string to handle error for.
 *
 * Return: -1 for error, 0 for success.
 */
void mem_alloc_error(char *s)
{
	if (s == NULL)
	{
		perror("memory allocation failed");
		exit(EXIT_FAILURE);
	}
}
