#include "shell.h"

/**
 * build_env_list - build linked list of enviroment variable.
 * @environ: environment variables.
 * @head: head pointer.
 * Return: returns pointer to the head.
 */

type_path *build_env_list(char **environ, type_path *head)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		add_nodep_end(&head,  environ[i]);
		i++;
	}
	return (head);
}


/**
 * _getenv - get environ variable value
 * @envi: environment variables
 * @en_var: environment variable to get
 * Return: the value if exist or NULL otherwise.
 */

char *_getenv(char **envi, char *en_var)
{
	unsigned int i = 0;
	char *token, *val;

	while (envi[i])
	{
		val = envi[i];

		token = strtok(val, "=");
		if (strcmp(token, en_var) == 0)

			return (strtok(NULL, "="));
		i++;


	}
	return (NULL);
}

/**
 * cmd_loc - get command path
 * @token: command.
 * Return: returns command path.
 */

char *cmd_loc(char *token)
{
	char *path, *cmd_path, *val;
	int cmd_len, dir_len;
	struct stat st;


	if (stat(token, &st) == 0)
		return (token);
	cmd_len = strlen(token);
	val = strdup(getenv("PATH"));
	path = strtok(val, ":");
	while (path)
	{
		dir_len = strlen(path);
		cmd_path = malloc(sizeof(char *) * (dir_len + cmd_len + 2));
		if (cmd_path == NULL)
			return (NULL);

		strcpy(cmd_path, path);
		strcat(cmd_path, "/");
		strcat(cmd_path, token);
		strcat(cmd_path, "\0");

		if (stat(cmd_path, &st) == 0)
		{
			free(val);
			return (cmd_path);
		}
		else
		{
			free(cmd_path);
			path = strtok(NULL, ":");
		}
	}
	free(val);
	return (NULL);
}

/**
  * add_node_end - add a node to the end of a list
  * @head: takes head of the list
  * @str: string data
  * Return: returns pointer to the the head of the node.
  */
type_path *add_nodep_end(type_path **head, char *str)
{
	type_path *new, *temp;

	new = malloc(sizeof(type_path));
	if (new == NULL)
		return (NULL);

	new->dir = strdup(str);
	new->next = NULL;

	temp = *head;

	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new;
	}

	return (*head);
}


/**
 * free_av - free the argument vector
 * @av: vector array.
 * Return: void
 */

void free_av(char **av)
{
	int i = 0;

	if (av != NULL)
	{
		while (av[i] != NULL)
		{
			free(av[i]);

			i++;
		}
		free(av);

	}

}
