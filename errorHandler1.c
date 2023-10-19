#include "monty.h"
/**
 * errorHandler - prints error codes accordling to their code (1,2,3,4....)
 * @errCode: error codes
 * Return: Void NADA :)
 */
void errorHandler1(int errCode, ...)
{
	va_list arg;
	char *operator;
	int argNum;

	va_start(arg, errCode);
	switch (errCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			argNum = va_arg(arg, int);
			operator = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", argNum, operator);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
