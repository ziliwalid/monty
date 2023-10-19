#include "monty.h"

/**
 * mulNodes - muls the top two elements of stack
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void mulNodes(stack_t **stck, unsigned int line_number)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		errorHandler2(8, line_number, "mul");

	(*stck) = (*stck)->next;
	sum = (*stck)->n * (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
