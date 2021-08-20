#include "main.h"

/**
 * hsh_loop-Display a prompt and wait for the user to type a command,
 * repeats each time a command has been executed.
 * @void: no parameters taken.
 * Returns: void.
 */

void hsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("@hsh> ");
		line = read_line();
		args = parse_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}
