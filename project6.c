/*
 * Thien An Tran U8520520
 * This program splits a text file into multiple fragment files,
 * each containing a specified number of lines. Fragment files are
 * named 1.chunk.txt, 2.chunk.txt, and so on.
 */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE_FILENAME 64
#define READ_CHUNK_SIZE 30

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./a.out <input filename> <output file size>\n");
        return 1;
    }

    /* Validate 2nd argument is a positive integer */
    int lines_per_file = 0;
    int i;
    for (i = 0; argv[2][i] != '\0'; i++) {
        if (argv[2][i] < '0' || argv[2][i] > '9') {
            printf("Error: 2nd argument must be a positive integer.\n");
            return 2;
        }
        lines_per_file = lines_per_file * 10 + (argv[2][i] - '0');
    }
    if (i == 0 || lines_per_file <= 0) {
        printf("Error: 2nd argument must be a positive integer.\n");
        return 2;
    }

    /* Open input file */
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error opening input file '%s'\n", argv[1]);
        return 3;
    }

    char buffer[READ_CHUNK_SIZE];
    int file_number = 1;
    int line_count = 0;
    int need_new_file = 1;
    char output_filename[MAX_SIZE_FILENAME];
    FILE *output = NULL;

    while (fgets(buffer, READ_CHUNK_SIZE, input) != NULL) {
        /* Open a new output file if needed */
        if (need_new_file) {
            sprintf(output_filename, "%d.chunk.txt", file_number);
            output = fopen(output_filename, "w");
            if (output == NULL) {
                printf("Error creating output file: %s\n", output_filename);
                fclose(input);
                return 4;
            }
            need_new_file = 0;
        }

        fputs(buffer, output);

        /* Check if we read a complete line (ends with newline) */
        if (buffer[strlen(buffer) - 1] == '\n') {
            line_count++;

            if (line_count == lines_per_file) {
                fclose(output);
                output = NULL;
                file_number++;
                line_count = 0;
                need_new_file = 1;
            }
        }
    }

    if (output != NULL) {
        fclose(output);
    }
    fclose(input);

    return 0;
}
