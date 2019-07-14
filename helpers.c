// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
        if (atoi(&fraction[2]) == 8){
            return atoi(&fraction[0]);
        }
        int result = 8 / (atoi(&fraction[0]) * atoi(&fraction[2]));
        return result;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double result;
    double octave;
    double semitone;
    int octavePos = 1;

    if (note[1] == '#' || note[1] == 'b'){
        octavePos = 2;
    }

        switch(note[octavePos])
        {
            case '0':
                octave = 48.00;
                break;
            case '1':
                octave = 36.00;
                break;
            case '2':
                octave = 24.00;
                break;
            case '3':
                octave = 12.00;
                break;
            case '4':
                octave = 0.00;
                break;
            case '5':
                octave = 12.00;
                break;
            case '6':
                octave = 24.00;
                break;
            case '7':
                octave = 36.00;
                break;
            case '8':
                octave = 48.00;
                break;
        }

        switch(note[0])
        {
            case 'A':
                semitone = 0.00;
                break;
            case 'B':
                semitone = 2.00;
                break;
            case 'C':
                semitone = 9.00;
                break;
            case 'D':
                semitone = 7.00;
                break;
            case 'E':
                semitone = 5.00;
                break;
            case 'F':
                semitone = 4.00;
                break;
            case 'G':
                semitone = 2.00;
                break;
        }

        if ((atoi(&note[octavePos]) <= 4 && note[0] > 'B') || (atoi(&note[octavePos]) >= 4 && note[0] == 'B')){
            octave += semitone;
        }

        if ((atoi(&note[octavePos]) < 4 && note[0] == 'B') || (atoi(&note[octavePos]) > 4 && note[0] > 'B')){
            octave -= semitone;
        }

        if (octavePos == 2){
            int cOctave = atoi(&note[2]);
            switch(note[1]){
                case '#':
                    if ((cOctave == 4 && note[0] <= 'B') || (cOctave > 4)){
                        octave += 1;
                    }else if (cOctave  <= 4){
                        octave -= 1;
                    }
                    break;
                case 'b':
                    if ((note[2] == 4 && note[0] <= 'B') || (cOctave > 4)){
                        octave -= 1;
                    } else if ((note[0] > 'B' || note[0] == 'A') && cOctave  <= 4){
                        octave += 1;
                    }
                    break;
            }
        }

    if (atoi(&note[octavePos]) < 4 || (atoi(&note[octavePos]) == 4 && note[0] > 'B'))
    {
        result = 440 / pow(2, (octave / 12));
    }else{
        result = (pow(2, (octave / 12)) * 440);
    }
    return result;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) < 1)
    {
        return 1;
    }else
    {
        return 0;
    }
}
