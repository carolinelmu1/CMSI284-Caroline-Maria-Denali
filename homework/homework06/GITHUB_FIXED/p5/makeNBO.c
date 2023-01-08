#include <stdio.h>
#include <stdlib.h>

// Clever test to check Big/Little Endian Architecture of a system.
// Good visual for how this works can be found at:
// https://stackoverflow.com/questions/12791864/c-program-to-check-little-vs-big-endian/12792301#12792301

/*
The conversion is done by swapping the bytes in memory for a 32 bit number.
Byte0 is swapped with byte3. Byte1 is swapped with byte2.
The conversion works both ways - from big to little and from little to big.
*/
unsigned long EndianSwap32(unsigned long x)
{
     unsigned long y = 0;
     y += (x & 0x000000FF) << 24;
     y += (x & 0xFF000000) >> 24;
     y += (x & 0x0000FF00) << 8;
     y += (x & 0x00FF0000) >> 8;
     return y;
}


int main (int argc, char *argv[]) {
     int n = 1;
     // little endian if true
     if (*(char *)&n == 1)
     {
          // Do the conversion
          printf("Little Endian Architecture Detected, value (dec): %s converted to NetworkByteOrder (dec): %ld\n",argv[1],EndianSwap32(strtol(argv[1],NULL,10))  );
     }
     else
     {
          // printf("Big Endian Architecture Detected.\n");
          // no conversion is needed.
          printf("Big Endian Architecture Detected, value: %s (dec) is already in NetworkByteOrder (dec).",argv[1] );
 
          printf("%s\n",argv[1]);
     }
}
