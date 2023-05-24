#include "monty.h"

int check_integer(unsigned int line_number, char *args)
{
	int i;
	int result;

	for (i = 0; args[i] != '\0'; i++)
	{
		if (!isdigit(args[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	result = atoi(args);
	/* printf("Output: %d\n", result); */
	return (0);
}