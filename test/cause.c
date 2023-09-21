#include "shell.h"
#include <sys/wait.h>
#define MAX_SIZE 8
int cause(char **argv, char **env)
{

	char *swahome = NULL;
	int z, m, status = 0;
	size_t n = 0;
	ssize_t char_nm;
	char *args[MAX_SIZE];
	pid_t child_process;

	/*prints the prompt and get the command of the use*/
	while (1)
	{
		printf("#cisfun$ ");

		char_nm = getline(&swahome, &n, stdin);
		if (char_nm == -1)
		{
			free(swahome);
			exit(EXIT_FAILURE);
		}
		z = 0;
		while (swahome[z])
		{
			if (swahome[z] == '\n')
				swahome[z] = 0;
			z++;
		}
		/* command that the user give and store subsequent token to next index*/
		m = 0;
		args[0] = strtok(swahome, " ");
		while (args[m] != NULL)
		{
			m++;
			args[m] = strtok(NULL, " ");
		}
		child_process = fork();
		if (child_process == -1)
		{
			free(swahome);
			exit(EXIT_FAILURE);
		}
		/* Wait for the child process to execute*/
		if (child_process == 0)
		{
			if (execve(args[0], args, env) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
		{
			wait(&status);
		}

	}
}

