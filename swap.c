#include "monty.h"
/**
 * swapNodes - swaps the top two elements of stack
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void swapNodes(stack_t **stck, unsigned int line_number)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		errorHandler2(8, line_number, "swap");
	tmp = (*stck)->next;
	(*stck)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stck;
	tmp->next = *stck;
	(*stck)->prev = tmp;
	tmp->prev = NULL;
	*stck = tmp;
}
