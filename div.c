#include "monty.h"
/**
 * divNodes - divs the top two elements of stack
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void divNodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errorHandler2(8, line_number, "div");

	if ((*stack)->n == 0)
		errorHandler2(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
