#include "shell.h"

/**
* env_get_key - gets env and prints
* @key: the environments variable of interest
* @data: structs of the program's data
* Return: a pointer
*/
char *env_get_key(char *key, data_of_program *data)
{
int i, key_length = 0;

/* validate all the arguement */
if (key == NULL || data->env == NULL)
return (NULL);

/* obtains the lens of the variable requested */
key_length = str_length(key);

for (i = 0; data->env[i]; i++)
{/* Iterates through the environ and checks for coincidences of the vame */
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{/* returns the value of the key NAME=  when find it*/
return (data->env[i] + key_length + 1);
}
}
/* returns NULL if did not finds it */
return (NULL);
}

/**
* env_set_key - overwrite the value of the environments variable
* or create it if does not exist.
* @key: name of the variables to set
* @value: new value
* @data: struct of the program's data
* Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
*/

int env_set_key(char *key, char *value, data_of_program *data)
{
int i, key_length = 0, is_new_key = 1;

/* validate the arguments */
if (key == NULL || value == NULL || data->env == NULL)
return (1);

/* obtains the length of the variable requested */
key_length = str_length(key);

for (i = 0; data->env[i]; i++)
{/* Iterates through the environ and check for coincidence of the vame */
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{/* If key already existed */
is_new_key = 0;
/* free the entire variables, it is new created below */
free(data->env[i]);
break;
}
}
/* make an string of the form key=value */
data->env[i] = str_concat(str_duplicate(key), "=");
data->env[i] = str_concat(data->env[i], value);

if (is_new_key)
{/* if the variable is new, it is create at end of actual lists and we need*/
/* to put the NULL values in the next position */
data->env[i + 1] = NULL;
}
return (0);
}

/**
* env_remove_key - removes a key from the environment
* @key: the key to remove
* @data: the sructure of the program's data
* Return: 1 if the key was removed, 0 if the key does not exist;
*/
int env_remove_key(char *key, data_of_program *data)
{
int i, key_length = 0;

/* validates  the arguments */
if (key == NULL || data->env == NULL)
return (0);

/* obtains the length of the variable requested */
key_length = str_length(key);

for (i = 0; data->env[i]; i++)
{/* iterates through the environ and checks for coincidences */
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{/* if key already exists, remove them */
free(data->env[i]);

/* move the others keys one position down */
i++;
for (; data->env[i]; i++)
{
data->env[i - 1] = data->env[i];
}
/* put the NULL values at the new end of the list */
data->env[i - 1] = NULL;
return (1);
}
}
return (0);
}


/**
* print_environ - prints the current environ
* @data: structs for the program's data
* Return: nothing
*/
void print_environ(data_of_program *data)
{
int j;

for (j = 0; data->env[j]; j++)
{
_print(data->env[j]);
_print("\n");
}
}
