///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//        Part 2 "Ghost's Help!"         //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdarg.h>
#include "grader.h"

/* For Testing and Debug in C format (Line 14 to 20) */
// #include <stdio.h>
// long long MOD(int, ...);
// int main() {
//     long long result = MOD(5 ,12 ,2 ,16 ,18 ,100);
//     printf("Result: %lld\n", result);
//     return 0;
// }

long long MOD(int n, ...)
{
    unsigned long long output = 0; // Declare our 64 bit output number

    // We have to use stdarg functions that allow us to use variable number of arguments :)
    // Declare va_list -> to use stdarg.h standard methods
    va_list list;

    // Set where the variable length part of the argument list ends
    va_start(list, n);

    /* Loop through each argument (One-based a_i) */
    for (int i = 1; i <= n; i++)
    {
        // Fetch our argument from the arguments list
        // with standard functions of va_list (stdarg.h)
        int a = va_arg(list, int);
        
        output <<= 1; // Shift the last binary left !
        output |= (a%i == 0); // Set or Not set the new bit (LSB bit)
    }

    // Clean up va_list
    va_end(list);

    return output;
}
