#include "fm_main.h"

/**
 * batch_mode - to handle batch mode.
 * @av: argument vector.
 *
 * Return: Nothing.
 */
void batch_mode(char **av)
{
	char *lineptr, *lineptr_cpy;
	const char *delimtr = " \n";
	size_t nread = 0;
	int count_token = 0;
	ssize_t nchar_read;
	char **av_cmd_line;
	pid_t child_pid;

	while ((nchar_read = getline(&lineptr, &nread, stdin)) != -1)
	{
		fm_builtin(lineptr);
		lineptr_cpy = malloc(nchar_read - 1);
		mem_alloc_error(lineptr_cpy);
		_strncpy(lineptr_cpy, lineptr, nchar_read - 1);
		count_token = fm_tokenize(lineptr, delimtr);
		av_cmd_line = av_cmmd(lineptr_cpy, delimtr, av, count_token);
		child_pid = fork();
		if (child_pid == 0)
		{
			exe_cmmd(av_cmd_line);
			free_av_cmd(av_cmd_line);
			free(lineptr_cpy);
			exit(0);
		}
		else if (child_pid < 0)
		{
			perror("Fork failed");
		}
		else
		{
			wait(NULL);
		}
		free_av_cmd(av_cmd_line);
		free(lineptr_cpy);
	}
	free(lineptr);
	exit(0);
}
/**
 * interactive_mode - to handle interactive mode.
 * @av: argument vector.
 *
 * Return: 0 on success, -1 on failure.
 */
int interactive_mode(char **av)
{
	char *lineptr = NULL, *lineptr_cpy = NULL, *shell_prompt = "fm_shell$ ", **av_cmd_line;
	const char *delimtr = " \n";
	size_t nread = 0, count_token = 0;
	ssize_t nchar_read;
	pid_t child_pid;

	for (;;)
	{
		write(STDOUT_FILENO, shell_prompt, _strlen(shell_prompt));
		nchar_read = getline(&lineptr, &nread, stdin);
		fm_builtin(lineptr);
		if (nchar_read == -1)
		{
			write(STDIN_FILENO, "\n", 2);
			free(lineptr);
			return (-1);
		}
			lineptr_cpy = malloc(sizeof(char) * (nchar_read + 1));
			mem_alloc_error(lineptr_cpy);
			_strcpy(lineptr_cpy, lineptr);
			count_token = fm_tokenize(lineptr, delimtr);
			av_cmd_line = av_cmmd(lineptr_cpy, delimtr, av, count_token);
			child_pid = fork();
			if (child_pid == 0)
			{
				exe_cmmd(av_cmd_line);
				free_av_cmd(av_cmd_line);
				free(lineptr_cpy);
				free(lineptr);
				exit(EXIT_FAILURE);
			}
			else if (child_pid < 0)
				perror("Fork failed");
			else
				wait(NULL);
			free_av_cmd(av_cmd_line);
			free(lineptr_cpy);
	}
	free(lineptr);
	return (0);
}
/**
* main - a simple shell.
* @ac: argument count.
* @av: argument vector.
*
* Return: Always 0.
*/
int main(int ac __attribute__((unused)), char **av)
{
	if (!isatty(fileno(stdin)))
		batch_mode(av);

	else
		interactive_mode(av);

	return (0);
}
