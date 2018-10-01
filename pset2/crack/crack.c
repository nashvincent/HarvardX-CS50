#define _XOPEN_SOURCE
#include <unistd.h>
#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(int argc, char *argv[2])
{
    if (argc != 2)
    {
        printf("ERROR\n");
        return 1;
    }

    // Finding salt
    char salt[3];
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';

    // Initializing password
    char password[6] = "\0\0\0\0\0\0";

    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = 53;

    // Brute forcing
    // Assuming password format to be -> abcde
    for (int e = 0; e < len; e++)
    {
        for (int d = 0; d < len; d++)
        {
            for (int c = 0; c < len; c++)
            {
                for (int b = 0; b < len; b++)
                {
                    for (int a = 1; a < len; a++)
                    {
                        password[0] = letters[a];
                        password[1] = letters[b];
                        password[2] = letters[c];
                        password[3] = letters[d];
                        password[4] = letters[e];

                        if (strcmp(crypt(password, salt), argv[1]) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // If password not found
    printf("FAIL\n");
    return 1;
}