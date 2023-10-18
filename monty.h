#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Error handlers*/
void errorHandler1(int errCode, ...);
void errorHandler2(int errCode, ...);
void errorHandler3(int errCode, ...);
void rotatorR(stack_t **, unsigned int); /*Top*/

/*file operationes*/
void openFile(char *F_name);
int line_parsor(char *buffer, int LN, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*stack ops*/
stack_t *createNode(int n);
void add_Node(stack_t **, unsigned int);
void freeNodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void callFunction(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void worthlessFunc(stack_t **, unsigned int);


/*String operations*/
void asciiPrinter(stack_t **, unsigned int);
void stringPrinter(stack_t **, unsigned int);
void rotatorL(stack_t **, unsigned int);

/*matches ops with nodes*/
void addNodes(stack_t **, unsigned int);
void subNodes(stack_t **, unsigned int);
void divNodes(stack_t **, unsigned int);
void swapNodes(stack_t **, unsigned int);
void modNodes(stack_t **, unsigned int);
void mulNodes(stack_t **, unsigned int);


#endif /*MONTYYYYYYYYYY*/

