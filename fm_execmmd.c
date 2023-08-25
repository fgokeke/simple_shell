#include "fm_main.h"

/**
 * exe_cmmd - to execute commands from argument vector
 * @av: argument vector.
 *
 * Return: Nothing.
 */
int exe_cmmd(char **av)
{
	char *cmmd;

	if (!av || !av[0]) 
		return (1);

	cmmd = locate_cmmd(av[0]);
	if (!cmmd)
		return (1);

	if (execve(cmmd, av, environ) == -1)
	{
		perror("Error");
		return (1);
	}
	return (0);
}
