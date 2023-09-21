#include "shell.h"

/**
 * main - return the command the user inputs
 * @bv: The argument count
 * @argv: This is the argument vector
 * @env: Environment variable
 * Return: in success return 0
 */

int main(int bv, char **argv, char **env)
{
	if (bv == 1)
		cause(argv, env);
	return (0);
}
