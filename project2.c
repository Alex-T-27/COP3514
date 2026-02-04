#include <stdio.h>

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
            if (ch >= 65 && ch <= 90)
            {
                printf("Class: Uppercase Letter\n");
                printf("Converted to: '%c'\n", ch + 32);
            }
            else if (ch >= 97 && ch <= 122)
            {
                printf("Class: Lowercase Letter\n");
                printf("Converted to: '%c'\n", ch - 32);
            }
            else if (ch >= 48 && ch <= 57)
            {
                printf("Class: Digit\n");
                printf("No conversion done\n");
            }
            else if (ch >= 32 && ch <= 126)
            {
                printf("Class: Printable Symbol\n");
                printf("No conversion done\n");
            }
            else
            {
                printf("Class: Non-printable Character\n");
                printf("No conversion done\n");
            }
        }

    } while (!done);

    return 0;
}
