#include "shell.h"
/**
* execute - execute a commands from the user
* @data: a pointer to the program's data
* Return: -1.
*/
int execute(data_of_program *data)
{
int retval = 0, status;
pid_t pidd;

retval = builtins_list(data);
if (retval != -1)/* if program was found in built ins */
return (retval);

retval = find_program(data);
if (retval)
{/* if program not found */
return (retval);
}
else
{/* if program was found */
pidd = fork(); /* create a child process */
if (pidd == -1)
{ /* if the fork call failed */
perror(data->command_name);
exit(EXIT_FAILURE);
}
if (pidd == 0)
{/* I am the child process, I execute the program*/
retval = execve(data->tokens[0], data->tokens, data->env);
if (retval == -1) /* if error when execve*/
perror(data->command_name), exit(EXIT_FAILURE);
}
else
{/* I am the father, I wait and check the exit status of the child */
wait(&status);
if (WIFEXITED(status))
errno = WEXITSTATUS(status);
else if (WIFSIGNALED(status))
errno = 128 + WTERMSIG(status);
}
}
return (0);
}
