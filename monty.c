#include "monty.h"

int main (int argc, char **argv)
{
	/* FILE IO variables */
	FILE *file;	/* File object */

	/* getline() variables */
	char *line = NULL;	/* For getline() */
	size_t len = 0;		/* For getline() */
	ssize_t read;		/* For getline() */

	/* main() variable */
	unsigned int line_number = 0;

	/* strtok() variables */
	char *token;
	char *args;
	char *delimiter = " \t\n";

	/* opcodes structs variables */
	instruction_t op_codes_funcs[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_add},
		{"nop", handle_nop},
		{NULL, NULL}
	};
	int i = 0;	/* loops through struct */

	/* stack linked list variables */
	stack_t *working_stack = NULL; 


	if (argc != 2) /* Check no. of arguments */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");	/* Open file in read only mode */

	if (file == NULL)	/* Check if file can be opened */
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	
	while ((read = getline(&line, &len, file)) != -1) /* tokenize each line in file */
	{
		line_number++;	/* Increment count */

		token = strtok(line, delimiter);

		/* printf ("\n***Token is :%s***\n", token); */

		while (op_codes_funcs[i].opcode != NULL) /* looping through the opcodes */
		{
			/* printf("\t\t%s\n", op_codes_funcs[i].opcode); */

			if (strcmp(token, op_codes_funcs[i].opcode) == 0)
			{
				// if (strcmp(token, "push") == 0)
				// {

					// printf ("\nMatch found %s(token) = %s(opcode)\n", token, op_codes_funcs[i].opcode);

					// args = strtok(NULL, delimiter);

					// if (args == NULL)
					// {
					// 	fprintf(stderr, "L%u: usage: push integer\n", line_number);
					// 	exit(EXIT_FAILURE);
					// }

					// check_integer(line_number, args);

				// 	op_codes_funcs[i].f(&working_stack, line_number);

				// }
				// else
				// {
					// printf ("\nMatch found %s(token) = %s(opcode)\n", token, op_codes_funcs[i].opcode);

					op_codes_funcs[i].f(&working_stack, line_number);
				// }
			}	
			i++;
		}

		/* check if we found an opcode */
		i = 0;

	}
	free(line);	/* free resources */
	fclose(file);	/* close file */
	return (0);
}

