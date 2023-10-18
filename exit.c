#include "shell.h"

/**
 * __exit - exit the shell.
 * @v: tokenized inputed string.
 * @av: command line argument Array
 * @st: pointer to exit status.
 * @i: shell iteration
 * Return: nothing
 */
int __exit(char **v, char **av, int *st, size_t i)
{
	int s = 0;

	if (v[1] != NULL)
	{
		s = atoi(v[1]);
		if (s <= 0)
		{
			dprintf(2, "%s: %lu: exit: Illegal number: %s\n", av[0], i, v[1]);
			*st = 2;
			return (-1);
		}
		if (s > 255)
			while (s > 255)
				s -= 256;
		*st = s;
	}
	free_av(v);
	exit(*st);
	return (0);
}
