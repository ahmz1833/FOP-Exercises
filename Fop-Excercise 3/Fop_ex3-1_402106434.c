///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//     Part 1 "Where is my cloth?"       //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);   // Read the number n from user

    for(int i = n; i > 0; i--)   // iterate i (from n to 1)
    {
        for(int j = 0; j < i; j++) printf("1");  // iterate j (from 0 to i-1) to print i*'1'
        printf("0");  // Print 0 between series
    }

    return 0;
}