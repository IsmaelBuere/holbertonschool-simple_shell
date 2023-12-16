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
    size_t capacity = 1024;  // Tamaño inicial del array
    size_t size = 0;         // Número actual de elementos en el array

    tokens = malloc(sizeof(char *) * capacity);
    if (!tokens)
    {
        return NULL;
    }

    token = strtok(buffer, del);
    while (token)
    {
        tokens[size] = strdup(token);
        if (!tokens[size])
        {
            free_tokens(tokens);
            return NULL;
        }

        size++;

        if (size == capacity)
        {
            capacity *= 2;
            char **temp = realloc(tokens, sizeof(char *) * capacity);
            if (!temp)
            {
                free_tokens(tokens);
                return NULL;
            }
            tokens = temp;
        }

        token = strtok(NULL, del);
    }

    tokens[size] = NULL;

    return tokens;
}