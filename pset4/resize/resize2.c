// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    float f = atof(argv[1]);

    if (f < 0.0 || f > 100.0)
    {
        fprintf(stderr, "Improper scale.\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, outbf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, outbi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    outbi = bi;
    outbf = bf;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Determining the new dimensions of the image
    outbi.biWidth = bi.biWidth * f;
    outbi.biHeight = bi.biHeight * f;

    // Determining the padding of the outfile
    int outPadding = (4 - (outbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    outbi.biSizeImage = ((sizeof(RGBTRIPLE) * outbi.biWidth) + outPadding) * abs(outbi.biHeight);
    outbf.bfSize = outbi.biSizeImage + outbf.bfOffBits;


    // write outfile's BITMAPFILEHEADER
    fwrite(&outbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&outbi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int inPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // TODO 

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
