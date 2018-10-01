#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, char *argv[2])
{
    int count = 0;

    // Validity test
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
            {
                count++;
            }
        }

        if (count != strlen(argv[1]))
        {
            printf("ERROR");
            return 1;
            exit(1);
        }

        string k = argv[1];
        string p = get_string("plaintext:");

        printf("ciphertext: ");

        // Main loop for encrypting
        for (int i = 0, j = 0, n = strlen(p); i < n; i++)
        {
            int key = tolower(k[j % strlen(k)]) - 'a';

            // Encryption for uppercase letters
            if (isupper(p[i]))
            {
                printf("%c", 'A' + (p[i] - 'A' + key) % 26);
                j++;
            }

            // Encryption for lowercase letters
            else if (islower(p[i]))
            {
                printf("%c", 'a' + (p[i] - 'a' + key) % 26);
                j++;
            }

            // Printing other characters
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");

        return 0;
    }

    // Invalid commandline input
    else
    {
        printf("ERROR");
        return 1;
    }
}