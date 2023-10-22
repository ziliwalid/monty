#include "monty.h"

/**
 * errorHandler3 - handles errors
 * @errCode: error codes
 * Return: Void
 */

void errorHandler3(int errCode, ...)
{
	va_list arg;
	int argNum;

	va_start(arg, errCode);
	argNum = va_arg(arg, int);
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
/* could have put all these in one method but betty isn't cool :(*/
