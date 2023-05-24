#include "monty.h"

/**
 * handle_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number where the add operation is performed.
 *
 * Return: Nothing.
 */
void handle_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	next->n += top->n;

	*stack = next;
	(*stack)->prev = NULL;
	free(top);
}

/**
 * handle_nop - Does nothing.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number where the nop operation is performed.
 *
 * Return: Nothing.
 */
void handle_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * handle_pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number where the pop operation is performed.
 *
 * Return: Nothing.
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * handle_pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number where the pint operation is performed.
 *
 * Return: Nothing.
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

