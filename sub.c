#include "monty.h"
/**
 * subNodes - subs the top two elements of stack
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void subNodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		errorHandler2(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
