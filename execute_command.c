#include "shell.h"
/**
 * execute_command - Execute a command.
 * @args: Array of strings containing the command and its arguments.
 * @env: Array of strings containing the environment variables.
 *
 * Description:
 * This function forks a new process to execute a command specified in @args.
 * It retrieves the full path of the command using the get_command function.
 * The child process then attempts to execute the command using execve.
 * If successful, the child process is replaced with the specified command.
 * The parent process waits for the child process to complete.
 *
 * Return: No return value.
 */
void execute_command(char **args, char **env)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        char *cmd = get_command(args[0]);

        if (cmd)
        {
            if (execve(cmd, args, env) == -1)
            {
                perror("execve");
                exit(2);
            }
            free(cmd);
        }
        else
        {
            fprintf(stderr, "Command not found\n");
            exit(127);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
            {
                fprintf(stderr, "Command exited with status %d\n", exit_status);
                exit(exit_status);
            }
        }
        else if (WIFSIGNALED(status))
        {
            fprintf(stderr, "Command terminated by signal %d\n", WTERMSIG(status));
            exit(128 + WTERMSIG(status));
        }
    }
}