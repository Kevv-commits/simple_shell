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

/*
  Function Declarations for builtin shell commands:
*/
int hsh_num_builtins();
int cd_hsh(char **args);
int help_hsh(char **args);
int exit_hsh(char **args);

#endif /*MAIN_H*/
