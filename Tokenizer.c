#include "shell.h"
/**
 * split_string - Splits a string into an array of tokens.
 * @buffer: The string to be split.
 * @del: The delimiter used to split the string.
 *
 * Return: An array of tokens, or NULL on failure.
 */
char **split_string(char *buffer, char *del)
{
    char **tokens = NULL;
    char *token;
    int j, i = 0;

    token = strtok(buffer, del);
    while (token)
    {
        char **new_tokens = realloc(tokens, sizeof(char *) * (i + 2));
        if (!new_tokens)
        {
            for (j = 0; j < i; j++)
            {
                free(tokens[j]);
            }
            free(tokens);
            return (NULL);
        }
        tokens = new_tokens;

        tokens[i] = strdup(token);
        if (!tokens[i])
        {
            for (j = 0; j < i; j++)
            {
                free(tokens[j]);
            }
            free(tokens);
            return (NULL);
        }

        token = strtok(NULL, del);
        i++;
    }

    char **final_tokens = realloc(tokens, sizeof(char *) * (i + 1));
    if (!final_tokens)
    {
        for (j = 0; j < i; j++)
        {
            free(tokens[j]);
        }
        free(tokens);
        return (NULL);
    }
    tokens = final_tokens;
    tokens[i] = NULL;

    return (tokens);
}
