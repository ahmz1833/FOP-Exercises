///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//      Part 1 "Kyoshi's Slander"        //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

/* Define Macros for Readablity of Program :) */
#define isEven(i) (i%2==0)
#define isOdd(i) !IsEven(i)

/* Function : numberOfOneBits(uint_64t) :
    returns the number of bits that are 1, in the 64 bit integer */
int numberOfOneBits(unsigned long long);


int main()
{
    unsigned int N = 0; // Declare N
    scanf("%u", &N); // Input N (Number of numbers!)

    // Process each input after scan
    for(int i = 0; i < N; i++)
    {
        unsigned long long a = 0;
        scanf("%llu", &a); // Scan the input ai
        
        if(isEven(numberOfOneBits(a))) printf("even\n");
        else printf("odd\n");
    }
    return 0;
}

/* Declaration of the function numberOfOneBits(uint_64t)*/
int numberOfOneBits(unsigned long long number)
{
    int counter = 0;
    for(int i = 0; i < 64; i++) // Iterate all 64 bits (0->63)
        if(number & (1ULL << i)) // If that bit is 1
            counter++; // Increament Counter
    return counter;
}