#include "monty.h"
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
