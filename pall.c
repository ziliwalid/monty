#include "monty.h"
/**
 * printStack - does some magic adding node to stack and printing it
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void printStack(stack_t **stck, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stck == NULL)
		exit(EXIT_FAILURE);
	tmp = *stck;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
