#include "monty.h"
/**
 * stringPrinter - prints string.
 * @stack: stack param
 * @ln: line number param
 * Return: void
 */
void stringPrinter(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * asciiPrinter - Prints the Ascii value.
 * @stck: stack param
 * @ln: line number param
 * Return: void
 */
void asciiPrinter(stack_t **stck, unsigned int ln)
{
	int ascii;

	if (stck == NULL || *stck == NULL)
		errorHandler3(11, ln);

	ascii = (*stck)->n;
	if (ascii < 0 || ascii > 127)
		errorHandler3(10, ln);
	printf("%c\n", ascii);
}
