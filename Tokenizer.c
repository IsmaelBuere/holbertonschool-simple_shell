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
    char **temp, **tokens = NULL;
    char *token;
    size_t capacity = 1024;
    size_t size = 0;
	size_t i;

    tokens = (char **)malloc(sizeof(char *) * capacity);
    if (!tokens)
    {
        return (NULL);
    }

    token = strtok(buffer, del);
    while (token)
    {
        tokens[size] = (char *)malloc(strlen(token) + 1);
        if (!tokens[size])
        {
            for (i = 0; i < size; ++i)
            {
                free(tokens[i]);
            }
            free(tokens);
            return (NULL);
        }

        strcpy(tokens[size], token);
        size++;

        if (size == capacity)
        {
            capacity *= 2;
            temp = (char **)realloc(tokens, sizeof(char *) * capacity);
            if (!temp)
            {
                for (i = 0; i < size; ++i)
                {
                    free(tokens[i]);
                }
                free(tokens);
                return (NULL);
            }
            tokens = temp;
        }

        token = strtok(NULL, del);
    }

    tokens[size] = NULL;

    return (tokens);
}