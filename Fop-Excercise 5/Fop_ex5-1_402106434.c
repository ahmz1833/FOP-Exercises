///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 5               //
//   Part 1 "Concern of Electricity"     //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

int main()
{
    unsigned int N = 0; // Declare N
    scanf("%u", &N); // Input N (Number of numbers!)

    // Allocate array of numbers in memory
    int* myArray = (int *) malloc(sizeof(int)*N);

    // Scan Inputs and put them in the array
    for(int i = 0; i < N; i++) scanf("%d", myArray+i);

    int flag = 1; // We assume the code is OK

    //Iterate through our bytes, get char input and check Code
    for(int i = 0; i < sizeof(int)*N; i++)
    {
        char tmp;
        scanf("\n%c", &tmp); // Scan the character

        // If related byte is not equal to Ascii number of scanned character:
        if(((char *) myArray)[i] != tmp) {flag = 0; break;}
    }

    if(flag) printf("Yes");
    else printf("No");

    // Release the memory for stablity :)
    free(myArray);

    return 0;
}