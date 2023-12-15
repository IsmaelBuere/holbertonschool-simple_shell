#include "shell.h"

/**
 * is_terminal - Checks if a file descriptor refers to a terminal.
 * @fd: File descriptor to check.
 *
 * Return: 1 if the file descriptor refers to a terminal, 0 otherwise.
 */
int is_terminal(int fd)
{
	struct stat st;

	if (fstat(fd, &st) == -1)
	{
		perror("fstat");
		exit(1);
	}
	return (S_ISCHR(st.st_mode));
}
