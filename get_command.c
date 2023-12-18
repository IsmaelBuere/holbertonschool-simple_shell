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
    char *cmd_full, *path = _getenv("PATH");
    struct stat st;
	 char *token = strtok(path, ":");

    if (command[0] == '/')
    {
        if (stat(command, &st) == 0)
            return strdup(command);
        else
            return NULL;
    }

    if (stat(command, &st) == 0)
    {
        free(path);
        return strdup(command);
    }

    while (token)
    {
        cmd_full = malloc(strlen(token) + strlen(command) + 2);
        if (!cmd_full)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(cmd_full, token);
        strcat(cmd_full, "/");
        strcat(cmd_full, command);

        if (stat(cmd_full, &st) == 0)
        {
            free(path);
            return cmd_full;
        }

        free(cmd_full);
        token = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}
