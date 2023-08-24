#include "fm_main.h"

/**
 * free_av_cmd - to free av_cmd_line
 * @av_cmd_line: the array of strings to free
 *
 * Return: Nothing.
 */
void free_av_cmd(char **av_cmd_line)
{
	int i;

	for (i = 0; av_cmd_line[i] != NULL; i++)
	{
		free(av_cmd_line[i]);
	}
	free(av_cmd_line);
}
