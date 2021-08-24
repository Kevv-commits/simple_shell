#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void hsh_loop(void);
char *read_line(void);
char **parse_line(char *line);
int execute(char **args);
int launch_hsh(char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int hsh_env(char **args, char __attribute__((__unused__)) **start);
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);
void _setenv(sev_t *sev);
void _unsetenv(sev_t *sev);

/*
  Function Declarations for builtin shell commands:
*/
int hsh_num_builtins();
int cd_hsh(char **args);
int help_hsh(char **args);
int exit_hsh(char **args);

#endif /*MAIN_H*/
