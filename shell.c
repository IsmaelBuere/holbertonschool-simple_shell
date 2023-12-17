#include "shell.h"
/**
 * main - Entry point for a simple shell program.
 * @ac: Number of arguments.
 * @av: Array of argument strings.
 * @env: Array of environment variable strings.
 *
 * Return: Always 0.
 */
 
int main(int ac, char **av, char **env)
{
    char **args, *buffer = NULL;
    size_t buffer_size = 0;
    int n_chars;
    (void)ac;
    (void)av;

    while (1)
    {
        if (is_terminal(STDIN_FILENO))
            write(1, "&-", 3);

        n_chars = getline(&buffer, &buffer_size, stdin);
        if (n_chars == -1)
            break;
        if (buffer[0] != '\n')
        {
            buffer[strcspn(buffer, "\n")] = '\0';
            args = split_string(buffer, " \t\n");
            if (args && args[0])
            {
                if (strcmp(args[0], "exit") == 0)
                    return (free(buffer), free_tokens(args), 0);
                if (strcmp(args[0], "cd") == 0)
                {
                    if (args[1] == NULL)
                        fprintf(stderr, "cd: missing argument\n");
                    else
                        chdir(args[1]), perror("cd");
                }
                else
                    execute_command(args, env);
                free_tokens(args);
            }
        }
    }
    free(buffer);
    return (0);
}
