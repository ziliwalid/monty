#include "monty.h"
/**
 * main - Entry point
 * @argc: arguments
 * @argv: list of argument
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeNodes();
	return (0);
}
