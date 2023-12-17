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
	char **tokens;
	char *token;
	int i = 0;	
	int j;

	tokens = malloc(sizeof(char *) * 1024);
	if (!tokens)
	{
		return (NULL);
	}
   token = strtok(buffer, del);
    while (token)
    {
        tokens[i] = strdup(token);
        if (!tokens[i])
        {
            free_tokens(tokens, i);
            return NULL;
        }
        token = strtok(NULL, del);
        i++;
    }

    tokens[i] = NULL;
    if (i > 0 && i % 1024 != 0)
    {
        for(j = i; j < 1024; j++)
        {
            tokens[j] = NULL;
        }
    }

    return tokens;
}