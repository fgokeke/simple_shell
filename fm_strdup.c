#include "fm_main.h"

/**
 * _strdup - to duplicate strings.
 * @s: the string to be duplicated.
 *
 * Return: the new string.
 */
char *_strdup(char *s)
{
	size_t len = _strlen(s);
	char *new_string = malloc(sizeof(char) * (len + 1));

	if (new_string == NULL)
	{
		return (NULL);
	}
	_strcpy(new_string, s);
	new_string[len] = '\0';

	return (new_string);
}
