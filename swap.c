#include "monty.h"

/**
 * swapNodes - swaps the top two elements of stack
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void swapNodes(stack_t **stck, unsigned int line_number)
{
	/*stack_t *tmp;*/
	stack_t *first;
	stack_t *second;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
	{
		errorHandler2(8, line_number, "swap");
	}
	first = *stck;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stck = second;
}

