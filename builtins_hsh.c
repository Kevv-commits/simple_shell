#include "main.h"

char *builtin_str[] = {"cd","help", "exit"};

int (*builtin_func[]) (char **) = {&lsh_cd, &lsh_help, &lsh_exit};

/**
 *
 */
int hsh_num_builtins()
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 *
 *
 *
 */
int cd_hsh(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	} else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 *
 *
 *
 */
int help_hsh(char **args)
{
	int i;

	printf("Olajomeokes & Kevin Ng'ang'a shell\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 *
 *
 */
int exit_hsh(char **args)
{
	return (0);
}
