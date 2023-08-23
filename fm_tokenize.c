#include "fm_main.h"

/**
 * fm_tokenize - to count number of tokens.
 * @lineptr: the command to be tokenized.
 * @delimtr: the delimiter.
 *
 * Return: the number of tokens.
 */
int fm_tokenize(char *lineptr, const char *delimtr)
{
	char *fm_token;
	int count_token = 0;

	fm_token = _strtok(lineptr, delimtr);
	while (fm_token != NULL)
	{
		count_token++;
		fm_token = _strtok(NULL, delimtr);
	}
	count_token++;

	return (count_token);
}
