#include "monty.h"
/**
 * addNodes - adds the top two elements of stack
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void addNodes(stack_t **stck, unsigned int line_number)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		errorHandler2(8, line_number, "add");

	(*stck) = (*stck)->next;
	sum = (*stck)->n + (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
