#include "monty.h"

void handle_push (stack_t **stack, unsigned int line_number)
{
	add_dnodeint(stack, line_number);
}

void handle_swap (stack_t **stack, unsigned int line_number)
{
	printf("Handle swap\n");
}

void handle_pall (stack_t **stack, unsigned int line_number)
{
	/* print_stack_t(stack); */
	printf("Handle pall\n");
}


