#include "monty.h"

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

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @F_descriptor: file descriptor pointer
 * Return: void NADA
 */

void read_file(FILE *F_descriptor)
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

	find_func(opcode, val, LN, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_Node},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", worthlessFunc},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", asciiPrinter},
		{"pstr", stringPrinter},
		{"rotl", rotatorL},
		{"rotr", rotatorR},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callFunction(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errorHandler1(3, ln, opcode);
}


/**
 * callFunction - calls a func
 * @func: func pram
 * @op: string param
 * @val: val param
 * @ln: line num param
 * @format: Format param
 * Return: Void
 */
void callFunction(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errorHandler1(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errorHandler1(5, ln);
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

