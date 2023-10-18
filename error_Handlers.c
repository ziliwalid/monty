#include "monty.h"

/**
 * errorHandler - Prints appropiate error messages determined by their error code.
 * @errCode: error codes
 * Return: Void NADA :)
 */
void errorHandler1(int errCode, ...)
{
	va_list ag;
	char *op;
	int argNum;

	va_start(ag, errCode);
	switch (errCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			argNum = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", argNum, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * errorHandler2 - handles other errors
 * @errCode: error codes
 * Return: VOID NADA
 */
void errorHandler2(int errCode, ...)
{
	va_list ag;
	char *op;
	int argNum;

	va_start(ag, errCode);
	switch (errCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			argNum = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", argNum, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * errorHandler3 - handles errors.
 * @errCode: error codes
 * Return: Void
 */
void errorHandler3(int errCode, ...)
{
	va_list ag;
	int argNum;

	va_start(ag, errCode);
	argNum = va_arg(ag, int);
	switch (errCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", argNum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", argNum);
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
/* could have put all these in one method but betty 
isn't cool :(*/
