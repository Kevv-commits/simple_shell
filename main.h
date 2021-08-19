#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void hsh_loop(void);
char *hsh_read_line(void);
char **hsh_parse(char *line);
int hsh_launch(char **args);

#endif /*MAIN_H*/
