#include "monty.h"
/**
 * printTop - prints the top node of the stack
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void printTop(stack_t **stck, unsigned int line_number)
{
	if (stck == NULL || *stck == NULL)
		errorHandler2(6, line_number);
	printf("%d\n", (*stck)->n);
}
