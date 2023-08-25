#include "fm_main.h"

/**
 * fm_builtins_handler - to handle builtins.
 * @avs: the array of strings.
 * @lineptr: the command from input.
 *
 * Return: 0 or 1;
 */
int fm_builtins_handler(char **avs, char *lineptr)
{
	int execute_status = 0, index = 0;

	if (_strcmp(avs[0], "exit") == 0)
	{
		free(avs);
		free(lineptr);
		exit(errno);
	}
	else if (_strcmp(avs[0], "env") == 0)
	{
		while (environ[index] != NULL)
		{
			write(1, environ[index], _strlen(environ[index]));
			write(1, "\n", 1);

			index++;
		}
		free(avs);
		execute_status = 1;
	}
	return (execute_status);
}
