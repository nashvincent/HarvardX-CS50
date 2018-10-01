#include<cs50.h>
#include<stdio.h>

int main()
{
    int height, i, j, k, stat = 0;
    height = get_int("Height: ");
    // Loop that continuously prompts the user for the right input (between 0 and 23)
    while (stat == 0)
    {
        if (height >= 0 && height <= 23)
        {
            stat = 1;
        }

        else
        {
            height = get_int("Height: ");
        }
    }

    // Pyramid printer
    for (i = 0; i < height; i++)
    {
        // Loop for printing spaces
        for (j = i; j < height - 1; j++)
        {
            printf(" ");
        }
        // Loop for printing the left pyramid
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("  ");
        // Loop for printing the right pyramid
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}