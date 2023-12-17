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
    char *result = NULL;

    if (command[0] == '/')
    {
        if (stat(command, &st) == 0)
            result = strdup(command);
    }
    else
    {
        token = strtok(path, ":");
        while (token && result == NULL)
        {
            cmd_full = malloc(strlen(token) + strlen(command) + 2);
            if (cmd_full == NULL)
            {
                perror("malloc");
                exit(1);
            }
            strcpy(cmd_full, token);
            strcat(cmd_full, "/");
            strcat(cmd_full, command);
            if (stat(cmd_full, &st) == 0)
            {
                result = strdup(cmd_full);
                if (result == NULL)
                {
                    perror("strdup");
                    exit(1);
                }
            }
            free(cmd_full);
            token = strtok(NULL, ":");
        }
    }

    free(path);
    return result;
}
