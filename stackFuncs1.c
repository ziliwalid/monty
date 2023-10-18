#include "monty.h"
/**
 * add_Node - Adds node to stack
 * @n_Node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_Node(stack_t **n_Node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (n_Node == NULL || *n_Node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_Node;
		return;
	}
	tmp = head;
	head = *n_Node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - does some magic adding node to stack and printing it
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void print_stack(stack_t **stck, unsigned int line_number)
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

/**
 * pop_top - pops a node XD
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void pop_top(stack_t **stck, unsigned int line_number)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL)
		errorHandler2(7, line_number);
	tmp = *stck;
	*stck = tmp->next;
	if (*stck != NULL)
		(*stck)->prev = NULL;
	free(tmp);
}

/**
 * print_top - prints top of the node
 * @stck: stack param
 * @line_number: line num param
 * Return: void
 */
void print_top(stack_t **stck, unsigned int line_number)
{
	if (stck == NULL || *stck == NULL)
		errorHandler2(6, line_number);
	printf("%d\n", (*stck)->n);
}

