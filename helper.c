#include "monty.h"

/**
 * check_integer - Checks if the given string is a valid integer.
 * @line_number: The line number where the integer is being checked.
 * @args: The string to be checked.
 *
 * Return: Nothing.
 */
int check_integer(unsigned int line_number, char *args)
{
	if (args == NULL || *args == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* // Skip the optional sign character */
	if (*args == '-' || *args == '+')
		args++;

	/* // Check if the remaining characters are digits */
	while (*args != '\0')
	{
		if (!isdigit(*args))
		{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		}
		args++;
	}
	return (1);
}
