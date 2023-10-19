#include "monty.h"
stack_t *head = NULL;
/**
 * add_Node - adds node to a specific stacl
 * @n_Node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode
 * Return: void nada.
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
 * addToQ - adds a node to a specific queue
 * @new_node: node pointer param
 * @ln: line number param
 * Return: void
 */
void addToQ(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *new_node;
	(*new_node)->prev = temp;
}

/**
 * freeNodes - frees the nodes XD
 * Return: void
 */
void freeNodes(void)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * createNode - creates a node
 * @n: num param
 * Return: pointer if success
 */
stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errorHandler1(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
