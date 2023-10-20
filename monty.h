#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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

/* global definitions */
extern stack_t *h;
typedef void (*def) (stack_t **, unsigned int);

/* first file */
void pop(stack_t **tos, unsigned int ln);
void pushStack(stack_t **node, unsigned int ln);
void pushQueue(stack_t **node, unsigned int ln);
stack_t *createNode(int n);
void freeStack(void);

void openFile(char *fn);
void readFile(FILE *fd);
int manLine(char *buf, int ln, int format);
void mapFunc(char *opcode, char *val, int ln, int format);
void execMap(def opfunc, char *opcode, char *val, int ln, int format);

void throwError(int code, ...);
void throwErrorV2(int code, ...);
void throwStrError(int code, ...);

void addStack(stack_t **stack, unsigned int ln);
void swapStack(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void printTop(stack_t **stack, unsigned int ln);
void printAll(stack_t **stack, unsigned int ln);

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln);

void modStack(stack_t **stack, unsigned int ln);
void mulStack(stack_t **stack, unsigned int ln);
void divStack(stack_t **stack, unsigned int ln);
void printChar(stack_t **stack, unsigned int ln);
void subStack(stack_t **stack, unsigned int ln);

void printStr(stack_t **stack, __attribute__((unused))unsigned int ln);

#endif /* MONTY_H */
