#include "shell.h"

/**
 * stream - decide stream of input
 * @av: commandline argument.
 * Return: stream.
 */

FILE *stream(char **av)
{
	FILE *fptr;

	if (av[1] != NULL)
	{
		fptr = fopen(av[1], "r");
		if (fptr == NULL)
			file_error(av[0], av[1]);
		return (fptr);
	}
	return (stdin);

}

/**
 * file_error - display message about error
 * @av0: first commandline argument.
 * @av1: second commandline argument.
 * Return: void
 */

void file_error(char *av0, char *av1)
{
	dprintf(STDERR_FILENO, "%s: 0: cannot open %s: No such file\n", av0, av1);
	exit(127);
}

/**
 * chck - check how to execute command
 * @vv: tokenized iputed string.
 * @av: commandline argument.
 * @st: shell status.
 * @j: shell iteration number
 * Return void.
 */

void chck(char **vv, char **av, int *st, size_t j)
{
	char *loc = NULL;

	if (builtin(vv, av, st, j) == -1)
	{
		loc = cmd_loc(vv[0]);
		if (loc != NULL)
		{
			execmd(loc, vv, av, st);
			if (strcmp(vv[0], loc) != 0)
				free(loc);
		}
		else
		{
			display_error(av, vv, st, j);
		}
	}
}

/**
 * display_error - display error message.
 * @av: commandline arguement.
 * @avv: tokenized inputed string.
 * @st: shell status.
 * @i: shell iteration number
 * Return: void
 */

void display_error(char **av, char **avv, int *st, size_t i)
{
	dprintf(STDERR_FILENO, "%s: %lu: %s: not found\n", av[0], i, avv[0]);
	*st = 127;
}
