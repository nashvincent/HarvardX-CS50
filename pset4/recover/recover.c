#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[1])
{
    int jflag = 0;
    int count = 0;
    unsigned char buffer[512];
    char pic[8];

    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Enter valid number of arguments\n");
        return 1;
    }

    FILE *fptr = fopen(argv[1],"r");
    if (fptr == NULL)
    {
        fclose(fptr);
        fprintf(stderr, "Unable to open file\n");
        return 2;
    }

    FILE *imgptr = NULL;

    while (fread(buffer, 512, 1, fptr) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jflag == 0)
            {
                jflag = 1;
                sprintf(pic, "%03i.jpg", count);
                imgptr = fopen(pic, "w");
                fwrite(buffer, 512, 1, imgptr);
            }

            else
            {
                fclose(imgptr);
                count++;
                sprintf(pic, "%03i.jpg", count);
                imgptr = fopen(pic, "w");
                fwrite(buffer, 512, 1, imgptr);
            }
        }

        else
        {
            if (jflag == 1)
            {
                fwrite(buffer, 512, 1, imgptr);
            }
        }
    }

    return 0;
}