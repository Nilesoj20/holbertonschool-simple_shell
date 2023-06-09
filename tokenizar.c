#include "main.h"

/**
 * token - splits an array into words separated
 *         b a delimiter character
 * @lineptr: string to be splitted into words
 *
 * Return: an array of strings where each string
 *         is a different word
 */
char **tokenizer(char *lineptr)
{
	char *lineptr_cp = NULL;
	const char *delim = " \t\n";
	char *token;
	int num_tokens = 0, i = 0;
	char **av = NULL;

	lineptr_cp = strdup(lineptr);
	token = strtok(lineptr_cp, delim);
	/* contamos la cantidad de token */
	while (token)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	av = malloc(sizeof(char *) * (num_tokens + 1));
	if (av == NULL)
	{
		free(lineptr_cp);
		perror("Error array av");
		return (NULL);
	}
	/* llenamos nuestro array de token */
	token = strtok(lineptr, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = token;
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	free(lineptr_cp);
	return (av);
}
