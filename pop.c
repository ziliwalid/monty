#include "monty.h"
/**
 * popTop - pops a node XD
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void popTop(stack_t **stck, unsigned int line_number)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL)
	{
		errorHandler2(7, line_number);
		return;
	}
	tmp = *stck;
	*stck = tmp->next;
	if (*stck != NULL)
		(*stck)->prev = NULL;
	free(tmp);
}
