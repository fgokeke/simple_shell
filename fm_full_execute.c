#include "fm_main.h"

/**
 * full_exec - fully executes command
 * @avs: user arguments.
 * @av: command line arguments/argument vector.
 * @complete_cmd: Full command
 *
 * Return: execution status.
 */
int full_exec(char **avs, char **av, char *complete_cmd)
{
	pid_t pid_num;
	int stat;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(complete_cmd);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(complete_cmd, avs, environ);
		perror(av[0]);
		exit(127);
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);
		errno = stat;

		free(complete_cmd);
		free(avs);
		/*return (stat);*/
	}
	return (stat);
}
