#include "shell.h"

/**
 * read_cmd - Function to read and execute inputs
 * @argv: double pointer to tokenified input
 * @cmd: exact command line input
 * @line_size: length of cmd
 *
 */

void read_cmd(char **argv, char *cmd, ssize_t line_size)
{
int a;
int j;
char *ptr;
char special_char[7] = {34, 39, 96, 92, 42, 38, 35};

if (!cmd)
	exit(EXIT_FAILURE);

ptr = malloc(sizeof(char) * line_size);

if (!ptr)
	exit(EXIT_FAILURE);

for (a = 0; a < line_size; a++)
{
	for (j = 0; j < 7; j++)
	{
		if (cmd[a] == special_char[j])
		{
			write(2, ":( Do not use special characters\n", 33);
			free(cmd);
			prompt();
			return;
		}
	}
	ptr[a] = cmd[a];
}
ptr[a] = '\0';

if (fork() != 0)
{
	wait(NULL);
	free(cmd);
	prompt();
}
else
{
	if (execve(argv[0], argv, NULL) == -1)
		write(2, ":( File does not exist\n", 23);
}
}
