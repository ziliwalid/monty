#include "monty.h"
/**
 * asciiPrinter - prints ascii value
 * @stck: stack param
 * @ln: line number param
 * Return: void
 */
void asciiPrinter(stack_t **stck, unsigned int ln)
{
	int ascii;

	if (stck == NULL || *stck == NULL)
		errorHandler3(11, ln);

	ascii = (*stck)->n;
	if (ascii < 0 || ascii > 127)
		errorHandler3(10, ln);
	printf("%c\n", ascii);
}

/**
 * stringPrinter - prints string.
 * @stck: stack param
 * @ln: line number param
 * Return: void
 */
void stringPrinter(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotatorL - rotates first node the bottom
 * @stck: stack param
 * @ln: line number param
 * Return: void
 */
void rotatorL(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	tmp = *stck;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stck;
	(*stck)->prev = tmp;
	*stck = (*stck)->next;
	(*stck)->prev->next = NULL;
	(*stck)->prev = NULL;
}


/**
 * rotatorR - rotates last node right
 * @stck: stack param
 * @ln: line number param
 * Return: void
 */
void rotatorR(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	tmp = *stck;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stck;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stck)->prev = tmp;
	(*stck) = tmp;
}

