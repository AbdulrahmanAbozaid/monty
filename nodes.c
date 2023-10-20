#include "monty.h"

/**
 * freeStack - free nodes
 * Return: fsdf
 */

void freeStack(void)
{
	stack_t *tmp;

	if (h == NULL)
		return;

	while (h)
	{
		tmp = h;
		h = h->next;
		free(tmp);
	}
}


/**
 * createNode - fasfas
 * @n: fasfas
 *
 * Return: asfas
 */

stack_t *createNode(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
		throwError(4);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * pushQueue - fasfasdf
 * @node: fafs
 * @ln: fsaa
 * Return: fasfas
 */

void pushQueue(stack_t **node, unsigned int ln)
{
	stack_t *tmp;

	(void)ln;
	if (!node || !*node)
		exit(EXIT_FAILURE);

	if (!h)
	{
		h = *node;
		return;
	}

	tmp = h;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *node;
	(*node)->prev = tmp;
}

/**
 * pushStack - fasfs
 * @node: afsfs
 * @ln: fdfds
 * Return: fafsf
 */

void pushStack(stack_t **node, __attribute__((unused))unsigned int ln)
{
	(void)ln;

	if (!node || !*node)
		exit(EXIT_FAILURE);

	if (!h)
	{
		h = *node;
		return;
	}

	h->prev = (*node);
	(*node)->next = h;
	h = (*node);
}


/**
 * pop - afsf
 * @tos: fsafa
 * @ln: line number
 * Return: fasfas
 */

void pop(stack_t **tos, unsigned int ln)
{
	stack_t *tmp;

	if (!tos || !*tos)
		throwErrorV2(7, ln);
	tmp = *tos;
	*tos = tmp->next;
	if (*tos)
		(*tos)->prev = NULL;
	free(tmp);
}
