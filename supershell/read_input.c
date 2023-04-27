#include <unistd.h>
#include <stdlib.h>
#include "read_input.h"
#define BUFFER_SIZE 1024

/**
 * read_input - this reads input from the user
 *
 * Return: The length of the input line
 */


char *read_input(void)

{
ssize_t buffer_size = BUFFER_SIZE;
char *buffer = malloc(buffer_size * sizeof(char));
ssize_t read_bytes;

if (!buffer)
{
	exit(EXIT_FAILURE);
}

read_bytes = read(STDIN_FILENO, buffer, buffer_size);

if (read_bytes == -1)
{
	free(buffer);
exit(EXIT_FAILURE);
}

buffer[read_bytes] = '\0';
	return (buffer);
}
