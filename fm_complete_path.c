#include "fm_main.h"

/**
 * get_path_token - to obtain path token.
 * @paths: directories in path environment.
 *
 * Return: path_tokens.
 */
char **get_path_token(char *paths)
{
	char **path_tokens = NULL, *token = NULL;
	char *temp = NULL;
	int index = 0;

	temp = _strtok(paths, "=");
	temp = _strtok(NULL, "=");
	path_tokens = malloc(sizeof(char *) * 30);
	if (path_tokens == NULL)
	{
		free(paths);
		return (NULL);
	}
	token = _strtok(temp, ":");
	while (token != NULL)
	{
		path_tokens[index] = token;
		token = _strtok(NULL, ":");
		index++;
	}
	path_tokens[index] = NULL;

	return (path_tokens);
}
/**
 * fm_complete_path - a path for the command.
 * @paths: directories in path environment
 * @cmd: the command.
 *
 * Return: complete path or NULL
 */
char *fm_complete_path(char *paths, char *cmd)
{
	char **path_tokens = NULL, *fullpath = NULL;
	int index = 0;
	size_t len = 0;

	if (paths == NULL)
		return (NULL);
	path_tokens = get_path_token(paths);
	index = 0;
	while (path_tokens[index] != NULL)
	{
		len = _strlen(path_tokens[index]) + _strlen(cmd) + 2;
		fullpath = malloc(len);
		_strcpy(fullpath, path_tokens[index]);
		_strcat(fullpath, "/");
		_strcat(fullpath, cmd);
		if (access(fullpath, X_OK) == 0)
		{
			free(path_tokens);
			free(paths);
			return (fullpath);
		}
		free(fullpath);
		fullpath = NULL;
		index++;
	}
	free(path_tokens);
	free(paths);
	return (NULL);
}
