// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[0] == '1')
    {
        switch (fraction[2])
        {
            case '8':
                return 1;
                break;

            case '4':
                return 2;
                break;

            case '2':
                return 4;
                break;

            case '1':
                return 8;
                break;

            default:
                return 0;
                break;
        }
    }

    else if (fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }

    else
    {
        return 0;
    }

    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char n = note[0];
    char octave = note[strlen(note) - 1];
    double freq = 0.0;
    octave -= 48;
    if (n == 'A')
    {
        freq = 440.0;
    }

    else if (n == 'B')
    {
        freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
    }

    else if (n == 'C')
    {
        freq = 440.0 / (pow(2.0, (9.0 / 12.0)));        // [x] DOUBT
    }

    else if (n == 'D')
    {
        freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
    }

    else if (n == 'E')
    {
        freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
    }

    else if (n == 'F')
    {
        freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
    }

    else if (n == 'G')
    {
        freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
    }

    // Considering octave
    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq = freq * 2.0;
        }
    }

    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq = freq / 2.0;
        }
    }

    if (note[1] == '#')
    {
        freq = freq * (pow(2.0, (1.0 / 12.0)));
    }

    else if (note[1] == 'b')
    {
        freq = freq / (pow(2.0, (1.0 / 12.0)));
    }

    long j= round(freq);
    return j;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s, "", 1))
    {
        return false;
    }

    else
    {
        return true;
    }
}
