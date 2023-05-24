#include "monty.h"

/**
 * add_dnodeint - add node at beginning
 * @head: pointer to head node address
 * @n: integer
 * Return: address to new element
 */
stack_t *add_dnodeint(stack_t **head, unsigned int n)
{
	stack_t *new;
	/* stack_t *temp_head = *head; */

	new = malloc(sizeof(stack_t)); /* mem allocation */

	if (new == NULL) /* check if malloc failed */
	{
		return (NULL);
	}

	new->n = n;
	new->next = *head; /* Next node is old head */
	new->prev = NULL; /* First node prev node is always NULL */

	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new; /* Move head to new node */

	return (new);
}

/**
 * print_dlistint - prints nodes in doubly linked list
 * @h: doubly linked list
 * Return: number of nodes
 */
size_t print_stack_t(stack_t **h)
{
    stack_t *current = *h;
    size_t elem_count = 0; /* number of elements */

    while (current != NULL) /* print elements */
    {
        printf("%d\n", current->n);
        elem_count++;
        current = current->next;
    }

    return (elem_count);
}
