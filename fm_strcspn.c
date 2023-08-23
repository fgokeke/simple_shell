#include "fm_main.h"

/**
 * _strcspn -  calculates the length of the initial segment of a
 * string that consists of characters not found in a specified set.
 * @str: the input string in which you want to find the initial segment.
 * @set: the set of characters to be searched for in str.
 *
 * Return: number of characters in the initial segment of the
 * string that do not match any of the characters in the given set.
 */
size_t _strcspn(const char *str, const char *set)
{
	size_t count = 0;
	const char *p;

	while (*str)
	{
		p = set;
	while (*p)
	{
		if (*str == *p)
		{
			return (count);
		}
		p++;
	}
	str++;
	count++;
	}
	return (count);
}
