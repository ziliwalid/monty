#include "monty.h"

/**
 * addNodes - adds the top two elements of the stack
 * @stck: stack parameter
 * @line_number: line number parameter
 * Return: void
 */
void addNodes(stack_t **stck, unsigned int line_number)
{
	int sum;
	stack_t *current, *previous;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
	{
		errorHandler2(8, line_number, "add");
		return;
	}
	current = *stck;
	previous = current->prev;
	current = current->next;
	/****************/
	sum = current->n + previous->n;
	current->n = sum;
	free(previous);
	current->prev = NULL;
}

