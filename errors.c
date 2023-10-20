#include "monty.h"


/**
 * throwError - fasfs
 * @code: fasfsa
 * Return: fsfds
 */

void throwError(int code, ...)
{
	va_list args;
	char *op;
	int ln;

	va_start(args, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(args, char *));
			break;
		case 3:
			ln = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	freeStack();
	exit(EXIT_FAILURE);
}

/**
 * throwErrorV2 - dasfsafas
 * @code: fasfasf
 * Return: gdsgsgsd
 */

void throwErrorV2(int code, ...)
{
	va_list args;
	char *op;
	int ln;

	va_start(args, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(args, int));
			break;
		case 8:
			ln = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	freeStack();
	exit(EXIT_FAILURE);
}


/**
 * throwStrError - gasfads
 * @code: fsfsfs
 * Return: fsfsd
 */

void throwStrError(int code, ...)
{
	va_list args;
	int ln;

	va_start(args, code);
	ln = va_arg(args, int);
	switch (code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
			break;
		default:
			break;
	}
	freeStack();
	exit(EXIT_FAILURE);
}
