#include "shell.h"

/**
 * add_nodep - add node to the head.
 * @head: pointer to the head.
 * @str: directory
 * Return: head.
 */

type_path *add_nodep(type_path **head, char *str)
{
	type_path *new;

	new = malloc(sizeof(type_path));

	if (new == NULL)
		return (NULL);


	new->dir = strdup(str);
	new->next = *head;
	*head = new;

	return (*head);
}
/**
 * build_path_list - build a linked-lsit of path variable.
 * @head: head of the list.
 * @val: value of path variable.
 * Return: returns list head.
 */

type_path *build_path_list(type_path *head, char *val)
{
	char *token;

	token = strtok(val, ":");

	while (token)
	{

		add_nodep(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}

/**
 * free_path - free path list.
 * @head: head of the path.
 * Return: void.
 */

void free_path(type_path *head)
{
	type_path *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->dir);
		free(tmp);
	}
}

/**
 * input_arr - break the inputed string into array of words.
 * @ptr: pointer to inputed string.
 * @av: pointer to  the array that stored the token string.
 * Return: pointer to the array
 */

char **input_arr(char *ptr, char **av)
{
	char *token;
	int i = 0;

	token  = strtok(ptr, " \t\n");
	if (token != NULL)
	{
		av = malloc(sizeof(char *) * BUFSIZE);
		while (token)
		{
			av[i] = strdup(token);
			i++;

			token = strtok(NULL, " \t\n");
		}
		av[i] = NULL;
	}
	return (av);
}

/**
 * execmd - execute the command
 * @avv: Array of tokenized inputed string.
 * @av: commandline argument.
 * @loc: command path.
 * @st: shell status.
 * Return: zeron on success or -1 on failure.
 */

int execmd(char *loc, char **avv, char **av, int *st)
{
	int s;
	pid_t child_id;

	(void)av;
	child_id = fork();
	if (child_id == -1)
		return (-1);
	if (child_id == 0)
	{
		execve(loc, avv, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&s);
		*st = WEXITSTATUS(s);
	}
	return (0);
}
