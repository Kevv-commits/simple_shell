#include "main.h"

/**
 * launch_hsh- takes the list of arguments created,
 * forks the process, and saves the return value.
 *
 * @args: string pointers to args.
 * Return: 1 to the calling function that we should prompt for input again
 */

int launch_hsh(char **args)
{
	pid_t pid, wpid;
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
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
