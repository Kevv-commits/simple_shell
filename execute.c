#include "main.h"

/**
 * execute- check if the command equals each builtin,
 * if it does then run the command.
 *
 * @args: string pointers to args.
 * Return: If a command doesn’t match a builtin,
 * calls lsh_launch() to launch the process.
 */

int execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		/* An empty command was entered.*/
		return (1);
	}

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}

	return (launch_hsh(args));
}
