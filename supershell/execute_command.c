#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "execute_command.h"

/**
 * execute_command - Execute the command
 * @args: Pointer to the arguments array
 */

void execute_command(char **args)

{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execve(args[0], args, NULL) == -1)
	{
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	do

	{
	waitpid(pid, &status, WUNTRACED);
	}

	while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
