#include "shell.h"
/**
 * free_tokens - Free memory allocated for an array of strings.
 * @tokens: Array of strings to be freed.
 *
 * Description:
 * This function takes an array of strings (@tokens) and frees the memory
 * allocated for each string and the array itself. It iterates through the
 * array until it encounters a NULL pointer, freeing each string element.
 * Finally, it frees the array itself.
 *
 * Return: No return value.
 */

void free_tokens(char **tokens)
{
    int i;
    int count;


    if (tokens)
    {
        for (i = 0; i < count; i++)
        {
            if (tokens[i])
            {
                free(tokens[i]);
                tokens[i] = NULL;
            }
        }
        free(tokens);
    }
}
