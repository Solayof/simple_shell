#include "shell.h"

/**
 * print_str - print string without newline.
 * @str: string to print
 * Return: returns thee numbers of string printed.
 */

int print_str(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _putchar - print a character.
 * @c: character to print.
 * Return: returns 1 on successful and -1 on error.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
