#include "fm_main.h"

/**
 * copy_fm_path - Copies PATH from getenv
 * @fm_path: path variable
 *
 * Return: copy of path
 */
char *copy_fm_path(char *fm_path)
{
	char *fm_path_cpy;

	fm_path = fm_getenv("PATH");
	fm_path_cpy = _strdup(fm_path);
	mem_alloc_error(fm_path_cpy);

	return (fm_path_cpy);
}

/**
 * construct_path_file - Builds the path
 * @fm_path_token: stors the tokenizes paths
 * @cmmd: stores command
 *
 * Return: path to the file
 */
char *construct_path_file(char *fm_path_token, char *cmmd)
{
	int path_length, cmmd_len;
	char *path_file;

	path_length = _strlen(fm_path_token);
	cmmd_len = _strlen(cmmd);
	path_file = (char *)malloc(path_length + cmmd_len + 2);
	mem_alloc_error(path_file);
	_strncpy(path_file, fm_path_token, path_length);
	path_file[path_length] = '/';
	_strncpy(path_file + path_length + 1, cmmd, cmmd_len);
	path_file[path_length + cmmd_len + 1] = '\0';

	return (path_file);
}

/**
 * locate_cmmd - Get the location of the command
 * @cmmd: stores command
 *
 * Return: the path of the command.
 */
char *locate_cmmd(char *cmmd)
{
	char *fm_path = fm_getenv("PATH"), *fm_path_token;
	char *fm_path_cpy = copy_fm_path(fm_path), *path_file;
	struct stat fm_buffer;

	if (!fm_path_cpy)
	return (NULL);

	fm_path_token = _strtok(fm_path_cpy, ":");
	while (fm_path_token != NULL)
	{
		path_file = construct_path_file(fm_path_token, cmmd);
		if (!path_file)
		{
			free(fm_path_cpy);
			return (NULL);
		}
		if (stat(path_file, &fm_buffer) == 0)
		{
			free(fm_path_cpy);
			return (path_file);
		}
		else
		{
			free(path_file);
			fm_path_token = _strtok(NULL, ":");
		}
	}
	free(fm_path_cpy);
	if (stat(cmmd, &fm_buffer) == 0)
		return (cmmd);

	return (NULL);
}
