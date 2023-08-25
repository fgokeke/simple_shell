#include "fm_main.h"

/**
 * exec - execution of inputed command
 * @avs: user arguments.
 * @av: argument vector.
 *
 * Return: execution status.
 */
int exec(char **avs, char **av)
{
	pid_t pid_num;
	int stat;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(av[0]);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(avs[0], avs, environ);
		perror(av[0]);
		exit(127);
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);

		errno = stat;

		free(avs);
		/*return (stat);*/
	}
	return (stat);
}
