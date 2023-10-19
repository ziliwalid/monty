#include "monty.h"
/**
 * operatorHandler - find the appropriate function for the opcode
 * @operatorC: opcode param, changed the name to not cause confusion
 * @value: value param
 * @format:  format param
 * @ln: line number
 * Return: void
 */
void operatorHandler(char *operatorC, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_Node},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
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

	if (operatorC[0] == '#')
	{
		return;
	}
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(operatorC, func_list[i].opcode) == 0)
		{
			callFunction(func_list[i].f, operatorC, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errorHandler1(3, ln, operatorC);
}

/**
 * callFunction - calls a func
 * @function: func pram
 * @oper: string param
 * @val: val param
 * @ln: line num param
 * @format: Format param
 * Return: Void
 */
void callFunction(op_func function, char *oper, char *val, int ln, int format)
{
	stack_t *node;
	int i, f; /*f for flag*/

	f = 1;
	if (strcmp(oper, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			f = -1;
		}
		if (val == NULL)
			errorHandler1(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errorHandler1(5, ln);
		}
		node = createNode(atoi(val) * f);
		if (format == 0)
			function(&node, ln);
		if (format == 1)
			addToQ(&node, ln);
	}
	else
		function(&head, ln);
}
