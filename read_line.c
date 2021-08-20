#include "main.h"
#define READ_LINE_BUFSIZE 1024

/**
 * read_line- reads lines of input from stdin
 *
 * @void: no parameters taken.
 * Return: buffer
 */

char *read_line(void)
{
	int bufsize = READ_LINE_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* Read a character*/
		c = getchar();

		/* If we hit EOF, replace it with a null character and return.*/
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		} else if
		{
			buffer[position] = c;
		}
		position++;

		/* If we have exceeded the buffer, reallocate.*/
		if (position >= bufsize)
		{
			bufsize += READ_LINE_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
