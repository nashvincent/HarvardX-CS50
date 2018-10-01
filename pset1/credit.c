#include<cs50.h>
#include<stdio.h>

int main(void)
{
    long num, temp, esum = 0, osum = 0, t1;
    int count = 1, len = 0;
    num = get_long_long("Number: ");
    temp = num;

    // Main loop to parse through each digit of the number
    while (temp != 0)
    {

        t1 = temp % 10;
        // To find the sum of every other number multiplied by 2
        if (count % 2 == 0)
        {
            if (t1 * 2 >= 10)
            {
                esum = esum + (t1 * 2 % 10) + (t1 * 2 / 10);
            }
            else
            {
                esum = esum + (t1 * 2);
            }
        }

        else
        {
            osum = osum + t1;
        }
        count = count + 1;
        temp = temp / 10;
    }

    // Resetting temp value to num for further use
    temp = num;

    // Validity test
    if ((esum + osum) % 10 == 0)
    {
        // Loop to find the first 2 digits
        while (temp > 100)
        {
            temp = temp / 10;
            len = len + 1;
        }
        len = len + 2;

        // To find the creditor
        if ((temp == 34 || temp == 37) && (len == 15))
        {
            printf("AMEX\n");
        }

        else if ((temp == 51 || temp == 52 || temp == 53 || temp == 54 || temp == 55) && (len == 16))
        {
            printf("MASTERCARD\n");
        }

        else if ((temp / 10 == 4) && (len == 13 || len == 16))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}