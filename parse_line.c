#include "main.h"
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * parse_line- splits line into a list of arguments
 * @line: string of commands entered
 * Return: pointer to the first token
 */
char **parse_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
