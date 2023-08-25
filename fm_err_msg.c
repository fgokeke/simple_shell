#include "fm_main.h"
void _puts(char *str);
int _putchar(char c);
/**
 * err_msg - prints error message to stderr.
 * @program: the program
 * @count_cmd: count command
 * @cmd: command to consider
 *
 * Return: Nothing
 */
void err_msg(char *program, int count_cmd, char *cmd)
{
	_puts(program);
	_puts(": ");
	_putchar(count_cmd);
	_puts(": ");
	_puts(cmd);
	_puts(": not found\n");
}
/**
 * _puts - prints a given string
 * @str: String to be printed
 *
 * Return: Nothing
 *
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
/**
 * _putchar - Prints a character to standard error
 * @c: Character to be printed
 *
 * Return: An integer
 */

int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
