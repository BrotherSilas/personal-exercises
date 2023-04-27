#include <unistd.h>
#include <stdlib.h>
#include "read_input.h"
#include "tokenize_input.h"
#include "execute_command.h"
#include <string.h>
#define PROMPT "$ "

/**
 * main - Entry point
 * Return: 0 on success
 */

int main(void)

{
	char *line;
	char **args;

	while (1)
	{
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	line = read_input();
	args = tokenize_input(line);
	execute_command(args);

	free(line);
	free(args);
	}

	return (EXIT_SUCCESS);
}
