#include "monty.h"

/**
 * printAll - fsafsd
 * @stack: fasfs
 * @ln: afsdg
 * Return: fsfd
 */

void printAll(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	(void)ln;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * printTop - fsdfdg
 * @stack: asffas
 * @ln: asfsfs
 * Return: fassd
 */

void printTop(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		throwErrorV2(6, ln);
	printf("%d\n", (*stack)->n);
}


/**
 * nop - fasdas
 * @stack: fasfsa
 * @ln: fsdfsfas
 * Return: fsdfsdf
 */

void nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}


/**
 * swapStack - fasfsf
 * @stack: fsfsdg
 * @ln: sgsdgsd
 * Return: fsdgfds
 */

void swapStack(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || !(*stack) || !(*stack)->next)
		throwErrorV2(8, ln, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}


/**
 * addStack - dasfsafa
 * @stack: fafasfas
 * @ln: fafsfsdg
 * Return: fasfasfa
 */

void addStack(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || !(*stack) || !(*stack)->next)
		throwErrorV2(8, ln, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
