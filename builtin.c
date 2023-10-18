#include "shell.h"

/**
 * builtin - execute built in functions.
 * @v: tokenized array of input
 * @a: command line argument.
 * @st: shell status
 * @i: shell iteration
 * @ptr: getline buffer.
 * Return: returns 0 if it execute any builtin functions -1 if not.
 */

int builtin(char **v, char **a, char *ptr, int *st, size_t i)
{

	if (strcmp(v[0], "exit") == 0)
	{
		__exit(v, a, ptr, st, i);
		return (0);
	}
	if (strcmp(v[0], "env") == 0)
	{
		prnt_env();
		*st = 0;
		return (0);
	}
	if (strcmp(v[0], "setenv") == 0)
	{
		if (v[1] && v[2])
		{
			setenv(v[1], v[2], 1);
			*st = 0;
		}
		return (0);
	}
	if (strcmp(v[0], "unsetenv") == 0)
	{
		if (v[1])
		{
			unsetenv(v[1]);
			*st = 0;
		}
		return (0);
	}
	return (-1);
}

/**
 * prnt_env - print the enviroment variable
 * Return: void.
 */

void prnt_env(void)
{
	int i = 0;

	while (environ[i])
	{

		print_str(environ[i]);
		_putchar('\n');
		i++;
	}
}
