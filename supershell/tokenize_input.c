#include <string.h>
#include <stdlib.h>
#include "tokenize_input.h"
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"


/**
 * tokenize_input - Tokenize the input line
 * @line: Pointer to the input line
 *
 * Return: The number of arguments
 */

char **tokenize_input(char *line)

{
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
	exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMITERS);
	while (token != NULL)
	{
	tokens[position] = token;
	position++;

	if (position >= bufsize)
	{
		bufsize += TOKEN_BUFSIZE;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
		exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, TOKEN_DELIMITERS);
}
tokens[position] = NULL;

	return (tokens);
}
