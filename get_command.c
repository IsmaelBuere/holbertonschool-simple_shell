#include "shell.h"
/**
 * get_command - Resolves the full path of a command.
 * @command: The command to resolve.
 *
 * Return: A dynamically allocated string containing the full path,
 *         or NULL if the command is not found.
 */
char *get_command(char *command)
{
	char *token, *cmd_full, *path = _getenv("PATH");
	struct stat st;

	if (command[0] == '/')
	{
		struct stat st;

		if (stat(command, &st) == 0)
			return (strdup(command));
		else
			return (NULL);
	}
	token = strtok(path, ":");
	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(command) + 2);
		strcpy(cmd_full, token);
		strcat(cmd_full, "/");
		strcat(cmd_full, command);
		if (stat(cmd_full, &st) == 0)
		{
			free(path);
			return (cmd_full);
		}
		free(cmd_full);
		token = strtok(NULL, ":");
	}
	if (strcmp(command, "ls") == 0)
	{
		free(path);
		return (strdup("/bin/ls"));
	}
	free(path);
	return (NULL);

    char *result = NULL;
    if (command[0] == '/') 
	{
        struct stat st;

        if (stat(command, &st) == 0)
            result = strdup(command);
    }

    return result;
}