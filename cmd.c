#include "shell.h"

/**
 * path_List - build the list.
 * @head: pointer to tokenized inputed string
 * @env: environment variable.
 * Return: pointer to the head list.
 */

type_path *path_list(type_path *head, char **env)
{
	char *val;

	(void)env;
	val = getenv("PATH");
	head = build_path_list(head, val);

	return (head);
}

/**
 * _input - recceiced inputed string.
 * @fp: field descriptor.
 * @_st: shell status.
 * @av: commandline argument.
 * @i: shell iteration.
 * Return: pointer to the inputed string.
 */

int _input(FILE *fp, char **av, int *_st, size_t i)
{
	ssize_t n = 0;
	size_t b = 0;
	char **avv = NULL, *ptr = NULL;

	if (isatty(STDIN_FILENO) && fp == stdin)
		print_str("root@shell_alx# ");
	n = getline(&ptr, &b, fp);

	if (n == -1)
	{
		if (isatty(STDIN_FILENO) && fp == stdin)
		{
			printf("here");
			_putchar('\n');
			free(ptr);
		}
		fclose(fp);
		exit(*_st);
	}
	fflush(fp);
	if (ptr && *ptr != '\n')
	{
		avv = input_arr(ptr, avv);
		if (avv != NULL)
			chck(avv, av, _st, i);
	}


	free_av(avv);
	if (ptr)
		free(ptr);
	return (n);
}

/**
 * print_env - print env list.
 * @h: list head pointer.
 * Return: void.
 */

void print_env(type_path *h)
{
	while (h != NULL)
	{
		print_str(h->dir);
		_putchar('\n');
		h = h->next;
	}

}
