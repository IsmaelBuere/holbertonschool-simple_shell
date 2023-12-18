#include "shell.h"
/**
 * main - Entry point for a simple shell program.
 * @ac: Number of arguments.
 * @av: Array of argument strings.
 * @env: Array of environment variable strings.
 *
 * Return: Always 0.
 */

int main(void)
{
    char *buffer = NULL;
    size_t buffer_size = 0;

    while (1)
    {
        display_prompt();

        if (getline(&buffer, &buffer_size, stdin) == -1)
        {
            printf("\n");
            break;
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) > 0)
        {
            char **args = split_string(buffer, " \t\n");
            if (args && args[0])
            {
                if (strcmp(args[0], "exit") == 0)
                {
                    free(buffer);
                    free_tokens(args);
                    return 0;
                }
                if (strcmp(args[0], "cd") == 0)
                {
                    if (args[1] == NULL)
                        fprintf(stderr, "cd: missing argument\n");
                    else
                        chdir(args[1]), perror("cd");
                }
                else
                    execute_command(args);
                free_tokens(args);
            }
        }
    }

    free(buffer);
    printf("Exiting shell.\n");
    return 0;
}
void display_prompt() 
{
    printf("$ ");
    fflush(stdout);
}