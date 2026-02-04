#include <stdio.h>

int classify_and_convert_character(int ch) {
    if (ch >= 65 && ch <= 90) {
        // Uppercase Letter
        printf("Class: Uppercase Letter\n");
        printf("Converted to: '%c'", ch + 32);
    } else if (ch >= 97 && ch <= 122) {
        // Lowercase Letter
        printf("Class: Lowercase Letter\n");
        printf("Converted to: '%c'", ch - 32);
    } else if (ch >= 48 && ch <= 57) {
        // Digit
        printf("Class: Digit\n");
        printf("No conversion done");
    } else if (ch >= 32 && ch <= 126) {
        // Printable Symbol
        printf("Class: Printable Symbol\n");
        printf("No conversion done");
    } else {
        // Non-printable or extended ASCII
        printf("Class: Non-printable or extended ASCII\n");
        printf("No conversion done");
    }
    return 0;
};

int main(void)
{
    int ch;
    int done = 0;

    do
    {
        /* Prompt */
        printf("Enter 1 or more characters then ENTER:\n");
        printf("(NOTE: a character # will exit the program):\n");

        /* Process characters until ENTER or # */
        while ((ch = getchar()) != '\n')
        {
            if (ch == '#')
            {
                done = 1;
                break;
            }

            /* Print character and ASCII */
            printf("\nYou typed: '%c' (ASCII %d)\n", ch, ch);

            /* Classify character */
            classify_and_convert_character(ch);
            printf("\n");
        }
        if (!done)
        {
            printf("\n");
        }

    } while (!done);

    return 0;
}
