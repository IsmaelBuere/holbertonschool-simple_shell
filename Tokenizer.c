#include "shell.h"
/**
 * split_string - Splits a string into an array of tokens.
 * @buffer: The string to be split.
 * @del: The delimiter used to split the string.
 *
 * Return: An array of tokens, or NULL on failure.
 */
char **split_string(const char *str, const char *delimiters)
{
    char **tokens = NULL;
    char *token = strtok(strdup(str), delimiters);
    size_t count = 0;

    while (token) {
        tokens = realloc(tokens, (count + 1) * sizeof(char *));
        if (!tokens) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        tokens[count] = strdup(token);
        if (!tokens[count]) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        count++;
        token = strtok(NULL, delimiters);
    }

    tokens = realloc(tokens, (count + 1) * sizeof(char *));
    if (!tokens) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }

    tokens[count] = NULL;

    return tokens;
}