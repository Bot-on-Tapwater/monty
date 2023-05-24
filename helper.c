#include "monty.h"

int check_integer(unsigned int line_number, char *args)
{
	if (args == NULL || *args == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*args == '-' || *args == '+')
		args++;

	while (*args != '\0')
	{
		if (!isdigit(*args))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		args++;
	}
	return 1;
} 