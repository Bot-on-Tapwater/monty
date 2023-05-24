#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    /* Check if the correct number of arguments is provided */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty byte code file */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read the file line by line and execute the instructions */
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        /* Tokenize the line to get the opcode and its argument (if any) */
        /* Execute the corresponding opcode function */
    }

    /* Clean up */
    free(line);
    fclose(file);
    /* Free the stack */
    /* Return success */
    return 0;
}