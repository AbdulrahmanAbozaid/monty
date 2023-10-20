#include "monty.h"
stack_t *h = NULL;


/**
 * main - fafasf
 * @argc: fafs
 * @argv: asgsgsd
 * Return: fafasf
 */

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeStack();
	return (0);
}
