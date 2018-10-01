# Questions

## What's `stdint.h`?

It is the header file to a C++ library (stdint) that provides typedefs and macros for fixed-width integral types in accordance with the C99 standard.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are used to explicitly define the variables in such a way that it has fixed size other properties.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1. BYTE - 1 byte
2. DWORD - 4 bytes
3. LONG - 4 bytes
4. WORD - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first 2 bytes of the BMP file format are the character "B" then the character "M" which would be 0x42 0x4d in hexadecimal.

## What's the difference between `bfSize` and `biSize`?

bfSize define the size of the bimap file whereas biSize defines the number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBitCount member of the BITMAPINFOHEADER structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

fopen will return NULL if the file does not exist or if it can not find the file

## Why is the third argument to `fread` always `1` in our code?

The third argument corresponds to count, which is the maximum number of items to be read from the file. Since we need only one rgb value at a time, count is set to 1.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

1

## What does `fseek` do?

It moves the 'pointer' to a specifed location in the file

## What is `SEEK_CUR`?

It specifies the current position of the file pointer

## Whodunit?

It was Professor Plum with the candlestick in the library
