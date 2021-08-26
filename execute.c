#include "main.h"

/**
 * execute- run shell builtin, or launch program.
 *
 * @args: Null terminated list of arguments.
 * Return: 1 if the shell should continue running,
 * 0 if it should terminate
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
