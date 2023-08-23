#include "fm_main.h"

/**
 * _strchr - a function that locates a character in a string.
 * @str: the pointer to the string to be checked.
 * @c: the character to be located.
 *
 * Return: the first occurrence of c or NULL if not found.
 */
char *_strchr(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}
