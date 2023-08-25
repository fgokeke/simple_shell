#include "fm_main.h"

/**
 * _strcat -  a function that concatenates two strings.
 * @dest: the destination string.
 * @src: the source string.
 *
 * Return: the destination string.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int a = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[a] != '\0')
	{
		dest[i] = src[a];
		i++;
		a++;
	}
	dest[i] = '\0';

	return (dest);
}
