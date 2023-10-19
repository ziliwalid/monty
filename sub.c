#include "monty.h"

/**
 * subNodes - subtracts the top two elements of the stack
 * @stack: stack parameter
 * @line_number: line number parameter
 * Return: void
 */
void subNodes(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *current, *previous;
	
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		errorHandler2(8, line_number, "sub");
		return;
	}
	
	current = *stack;
	previous = current->prev;
	current = current->next;
	sum = current->n - previous->n;
	current->n = sum;
	free(previous);
	current->prev = NULL;
}
