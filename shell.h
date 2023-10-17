#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFSIZE 1024
/* Functions declaration */
extern char **environ;
void prnt_env(void);
void _isdigit(char **avv, char **av);
void exit_display(char **a, char **b);
FILE *stream(char **av);
void free_av(char **av);
char *__strtok(char *s, char *dlm);
char *_strtok(char *s, char *dlm);
void file_error(char *av0, char *av1);
char *dlm_trail(char *str, char *dlm);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_strdup(char *str);
int print_str(char *str);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *getcmd_loc(char **environ, char *en_var, char **cmd);
char *_getenv(char **env, char *en_var);
char **input_arr(char *ptr, char **av);
int execmd(char *loc, char **avv, char **av, int *s);
char **prompt(char **av);
char *_strncpy(char *dest, char *src, int n);
void display_error(char **av, char **avv, int *s, size_t i);

/* Environment  Structure linked list */

/**
 * struct path_list - environment variables list
 * @dir: environment variable name.
 * @next: pointer to the next environment variable name.
 *
 * Description: linked list of a process environment variables.
 */

typedef struct path_list
{
	char *dir;
	struct path_list *next;
} type_path;

type_path *build_path_list(type_path *head, char *val);
type_path *add_nodep(type_path **head, char *str);
char *cmd_loc(char *av);
type_path *add_nodep_end(type_path **head, char *str);
void free_path(type_path *head);
type_path *path_list(type_path *head, char **env);
type_path *build_env_list(char **environ, type_path *head);
void print_env(type_path *h);
void chck(char **p, char **av, int *_st, size_t i);
int builtin(char **v, char **a, int *s, size_t i);
int _input(FILE *fp, char **av, int *_status, size_t i);
int __exit(char **v, char **av, int *st, size_t i);

#endif
