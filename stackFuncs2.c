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

/**
 * worthlessFunc - does absolutely nothing
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void worthlessFunc(stack_t **stck, unsigned int line_number)
{
	(void)stck;
	(void)line_number;
}



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

