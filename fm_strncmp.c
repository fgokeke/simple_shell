#include "fm_main.h"

/**
 * _strncmp - to compare two strings up
 * to a specified number of characters.
 * @s1: the first string.
 * @s2: the second string.
 * @n: the limit of the comparison.
 *
 * Return: Always 0.
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t index;

	for (index = 0; index < n; index++)
	{
		if (s1[index] != s2[index])
			return ((int)(unsigned char)s1[index] - (int)(unsigned char)s2[index]);

		if (s1[index] == '\0' || s2[index] == '\0')
			break;
	}
	return (0);
}
