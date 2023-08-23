#include "fm_main.h"

/**
 * exe_cmmd - to execute commands from argument vector
 * @av: argument vector.
 *
 * Return: Nothing.
 */
void exe_cmmd(char **av)
{
	char *cmmd;

	if (av)
	{
		cmmd = locate_cmmd(av[0]);
		if (execve(cmmd, av, NULL) == -1)
		{
			perror("Error");
		}
	}

}
