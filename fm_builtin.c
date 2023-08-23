#include "fm_main.h"
#define MAX_INPUT_LENGTH 100

/**
 * fm_builtin - Handles builtin commands
 * @input: Input argument
 *
 * Return: Nothing
 */
void fm_builtin(char *input)
{
	char **env = environ;

	input[_strcspn(input, "\n")] = '\0';
	if (_strcmp(input, "exit") == 0)
	{
		write(STDOUT_FILENO, "Exiting.....\n", 13);
		exit(0);
	}
	else if (_strcmp(input, "env") == 0)
	{
		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 2);
			env++;
		}
	}
}
