#include "fm_main.h"

void print_prompt(int shell_mode);
char *read_input(ssize_t nchar_read);
/*void final_exec(char **av, char *lineptr, int err_count);*/
/**
 * main - shell main function.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: errno
 */
int main(int ac __attribute__((unused)), char **av)
{
	int shell_mode = isatty(0);
	char *lineptr = NULL, cmmd, **avs = NULL, *complete_cmd = NULL;
	ssize_t nchar_read = 0;
	int err_count = 0, builtin_status = 0;

	errno = 0;
	for (;;)
	{
		err_count++;
		print_prompt(shell_mode);
		lineptr = read_input(nchar_read);
		handle_comments(lineptr);
		avs = tokenize_str(lineptr);
		if (avs[0] == NULL)
		{
			free(avs);
			free(lineptr);
			continue;
		}
		if (access(avs[0], X_OK) == -1)
		{
			builtin_status = fm_builtins_handler(avs, lineptr);
			if (builtin_status == 1)
			{
				free(avs);
				free(lineptr);
				continue;
			}
			complete_cmd = fm_complete_path(pathenv(), avs[0]);
			if (complete_cmd == NULL)
			{
				cmmd = (err_count + '0');
				err_msg(av[0], cmmd, avs[0]);
				free(avs);
				free(lineptr);
				errno = 127;
				continue;
			}
			full_exec(avs, av, complete_cmd);
			free(complete_cmd);
			continue;
		}
		exec(avs, av);
		free(lineptr);
	}
	return (errno);
}

/**
 * print_prompt - Handles the printing of input
 * @shell_mode: shell_mode variable
 *
 * Return: Nothing.
*/
void print_prompt(int shell_mode)
{
	if (shell_mode == 1)
	write(STDOUT_FILENO, "fm_shell$ ", 10);
}

/**
 * read_input - Handles the reading of input.
 * @nchar_read: number of char read.
 *
 * Return:lineptr.
 */
char *read_input(ssize_t nchar_read)
{
	char *lineptr = NULL;
	size_t nread = 0;

	nchar_read = getline(&lineptr, &nread, stdin);
	if (nchar_read == -1)
	{
		free(lineptr);
		exit(errno);
	}
	return (lineptr);
}
