#include "main.h"

/**
 * main - main function of the shell that,
 * loads configuration files if,
 * runs REPL loop, performs shutdown and clean up.
 * @argc:argument count
 * @argv:pointers to argument strings
 * Return: EXIT_SUCCESS
 */

int main(int __attribute__((__unused__)) argc, char __attribute__((__unused__)) **argv)
{
	hsh_loop();

	return (EXIT_SUCCESS);
}
