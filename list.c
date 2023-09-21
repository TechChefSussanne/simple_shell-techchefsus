#include "shell.h"

/**
* builtins_list - lists of commands
* @data: struct for the program's data
* Return: 1
**/
int builtins_list(data_of_program *data)
{
int iterator;
builtins options[] = {
{"exit", builtin_exit},
{"help", builtin_help},
{"cd", builtin_cd},
{"alias", builtin_alias},
{"env", builtin_env},
{"setenv", builtin_set_env},
{"unsetenv", builtin_unset_env},
{NULL, NULL}
};

/*walk through many of the  structure*/
for (iterator = 0; options[iterator].builtin != NULL; iterator++)
{
/*if there is as a match between the given command and a builtin,*/
if (str_compare(options[iterator].builtin, data->command_name, 0))
{
/*execute this function, and returns the return value of the function*/
return (options[iterator].function(data));
}
/*if there are no match return -1 */
}
return (-1);
}
