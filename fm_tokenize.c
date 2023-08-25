#include "fm_main.h"

/**
 * tokenize_str - to tokenizes a string.
 * @str: string to be tokenized.
 *
 * Return: array of tokens.
 */

char **tokenize_str(char *str)
{
	char **token_array = NULL, *token = NULL;
	int count_token = 0;
	char *delim = " \n";

	token_array = malloc(sizeof(char *) * 25);
	if (token_array == NULL)
		return (NULL);

	token = _strtok(str, delim);

	while (token != NULL)
	{
		token_array[count_token] = token;
		token = _strtok(NULL, delim);
		count_token++;
	}

	token_array[count_token] = NULL;
	return (token_array);
}
