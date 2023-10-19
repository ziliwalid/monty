#include "monty.h"
#define _POSIX_C_SOURCE 200809L
/**
 * FileInterpreter - reads a file
 * @F_descriptor: file descriptor pointer
 * Return: void NADA
 */

void FileInterpreter(FILE *F_descriptor)
{
	int LN, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (LN = 1; getline(&buffer, &len, F_descriptor) != -1; LN++)
	{
		format = line_parsor(buffer, LN, format);
	}
	free(buffer);
}

/**
 * openFile - opens a file
 * @F_name: the file namepath
 * Return: void
 */

void openFile(char *F_name)
{
	FILE *fd = fopen(F_name, "r");

	if (F_name == NULL || fd == NULL)
		errorHandler1(2, F_name);

	FileInterpreter(fd);
	fclose(fd);
}


/**
 * line_parsor - parses line
 * @buffer: param
 * @LN: line number param
 * @format:  format param
 * Return: int
 */

int line_parsor(char *buffer, int LN, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		errorHandler1(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	operatorHandler(opcode, val, LN, format);
	return (format);
}
