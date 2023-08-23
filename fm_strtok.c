#include "fm_main.h"

/**
 * _strtok - Tokenises strings gotten from the stdin
 * @str: String to be tokenized
 * @delim: Delimeter for the tokenization
 *
 * Return: tokenized string
 */
char *_strtok(char *str, const char *delim)
{
	static char *store_ptr;
	char *tok_strt;

	if (str != NULL)
	{
		store_ptr = str;
	}
	if (store_ptr == NULL || *store_ptr == '\0')
	{
		return (NULL);
	}
	while (*store_ptr && _strchr(delim, *store_ptr))
	{
		store_ptr++;
	}
	if (*store_ptr == '\0')
	{
		return (NULL);
	}
	tok_strt = store_ptr;
	while (*store_ptr && !_strchr(delim, *store_ptr))
	{
		store_ptr++;
	}
	if (*store_ptr)
	{
		*store_ptr = '\0';
		store_ptr++;
	}
	return (tok_strt);
}
