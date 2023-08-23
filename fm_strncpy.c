#include "fm_main.h"

/**
 * _strncpy - copies from the source string up to n characters
 * @dest: the destination string
 * @src: the source string
 * @n: the amount of characters to be copied from source string
 *
 * Return: the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a;

	for (a = 0; a < n && src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	for (; a < n; a++)
	{
		dest[a] = '\0';
	}
	return (dest);
}
