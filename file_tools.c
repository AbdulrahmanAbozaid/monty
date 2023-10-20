#include "monty.h"

/**
 * openFile - gdsgfds
 * @fn: fasfsd
 * Return: fsafs
 */

void openFile(char *fn)
{
	FILE *fd = fopen(fn, "r");

	if (!fn || !fd)
		throwError(2, fn);

	readFile(fd);
	fclose(fd);
}

/**
 * readFile - fsfsd
 * @fd: fsfsdf
 *
 * Return: fsdfsd
 */

void readFile(FILE *fd)
{
	int ln, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (ln = 1; getline(&buffer, &len, fd) != -1; ln++)
	{
		format = manLine(buffer, ln, format);
	}

	free(buffer);
}


/**
 * manLine - fsfsd
 * @buf: fafs
 * @ln: fafesfe
 * @format: ffsdf
 * Return: fsgfs
 */

int manLine(char *buf, int ln, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (!buf)
		throwError(4);

	opcode = strtok(buf, delim);
	if (!opcode)
		return (format);

	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	mapFunc(opcode, val, ln, format);
	return (format);
}


/**
 * mapFunc - gsdgd
 * @opcode: fsafs
 * @val: fafsdfsd
 * @ln: fasfs
 * @format: fsfsdgs
 * Return: fafs
 */

void mapFunc(char *opcode, char *val, int ln, int format)
{
	int i, flag;

	instruction_t maps[] = {
		{"push", pushStack},
		{"pall", printAll},
		{"pint", printTop},
		{"pop", pop},
		{"nop", nop},
		{"swap", swapStack},
		{"add", addStack},
		{"sub", subStack},
		{"div", divStack},
		{"mul", mulStack},
		{"mod", modStack},
		{"pchar", printChar},
		{"pstr", printStr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL},
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; maps[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, maps[i].opcode) == 0)
		{
			execMap(maps[i].f, opcode, val, ln, format);
			flag = 0;
		}
	}

	if (flag == 1)
		throwError(3, ln, opcode);
}


/**
 * execMap - fsfsd
 * @opfunc: ffsef
 * @opcode: fafs
 * @val: fasfs
 * @ln: fafs
 * @format: fasgsd
 *
 * Return: fafsa
 */

void execMap(def opfunc, char *opcode, char *val, int ln, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;

	if (strcmp(opcode, "push") == 0)
	{
		if (val && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}

		if (val == NULL)
			throwError(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				throwError(5, ln);
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
			opfunc(&node, ln);
		if (format == 1)
			pushQueue(&node, ln);
	}
	else
		opfunc(&h, ln);
}
