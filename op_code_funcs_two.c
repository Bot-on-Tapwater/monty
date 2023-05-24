#include "monty.h"

void handle_push (stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	/* Get the integer argument from the instruction */

	/* Create a new stack node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* Push the new node onto the stack */
	if (*stack != NULL)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
}

void handle_swap (stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	top->prev = next;
	top->next = next->next;

	next->prev = NULL;
	next->next = top;

	if (top->next != NULL)
		top->next->prev = top;

	*stack = next;
}

void handle_pall (stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


