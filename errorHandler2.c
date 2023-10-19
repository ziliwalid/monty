#include "monty.h"
/**
 * errorHandler2 - handles other errors
 * @errCode: error codes
 * Return: VOID NADA
 */
void errorHandler2(int errCode, ...)
{
	va_list arg;
	char *operator;
	int argNum;

	va_start(arg, errCode);
	switch (errCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			argNum = va_arg(arg, unsigned int);
			operator = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", argNum, operator);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
