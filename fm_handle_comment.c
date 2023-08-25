#include "fm_main.h"

/**
 * handle_comments - to know if the command is a comment
 * @lineptr: command to check if it is a comment
 *
 * Return: Nothing
 */

void handle_comments(char *lineptr)
{
	int index = 0;

	while (lineptr[index])
	{
		if (index > 0 && lineptr[index - 1] != ' ' && lineptr[index] == '#')
			break;

		if (lineptr[index] == '#')
		{
			lineptr[index] = '\0';
			break;
		}

		index++;
	}
}
