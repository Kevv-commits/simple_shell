#include "main.h"

/**
 * launch_hsh- Launch a program and wait for it to terminate.
 * @args: Null terminated list of arguments
 * Return: 1 to the calling function and should prompt for input again
 */

int launch_hsh(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process*/
		if (execvp(args[0], args) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		/* Error forking */
		perror("hsh");
	} else
	{
		/* Parent process */
		do
		{
			 waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
