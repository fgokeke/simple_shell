#include "fm_main.h"

/**
 * pathenv - to get path env variable.
 *
 * Return: the path variable.
 */
char *pathenv(void)
{
	int index;
	char *path_dup = NULL;

	for (index = 0; environ[index] != NULL; index++)
	{
		if (_strncmp(environ[index], "PATH", 4) == 0)
			path_dup = _strdup(environ[index]);
	}
	return (path_dup);
}
