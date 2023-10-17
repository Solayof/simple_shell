#include "shell.h"

/**
 * main - shell entry point.
 * @ac: argumrnt count.
 * @av: commandline argument.
 * Return: alway return 0.
 */

int main(int __attribute__((unused)) ac, char **av)
{
	int _status = 0;
	FILE *fptr;
	size_t i = 0;

	fptr = stream(av);

	while (1)
	{
		i++;

		_input(fptr, av, &_status, i);

	}

	return (0);
}
