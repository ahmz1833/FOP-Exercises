///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 5               //
//         Part 2 "sulli-one!"           //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "grader.h"

// A function for specify number of members in an array (Specific Formula)
int determineNumber(int* array)
{
    long long sum = 0;

    // Related to strange test cases !! (If we were given 0 in index 0 -> Length = 1)
    if(*array == 0) return 1;
    
    for(int i = 0; i < 999; i++)
    {
        // Situation of end of array :
        // If sum of members, from first to current i, equals with member of index i+1
        // Then, the array length is (i+2)   (In another words, next member is last member)
        sum += *(array+i);
        if(sum == *(array+i+1)) return i+2;
    }
    return 1;
}

/**** Function aggregator : Important and main of program ****/
int* aggregator(int* a, int* b)
{
    int numberA = determineNumber(a),
        numberB = determineNumber(b);

    int finalLength = numberA + numberB;

    // Allocate Memory for store final array
    int* result = (int*) malloc(finalLength*sizeof(int));

    int i = 0;

    // Iterating over where both arrays A and B have members. (One among picking)
    for(i = 0; (i < numberA) && (i < numberB); i++)
    {
        *(result+(2*i)) = *(a+i);
        *(result+(2*i+1)) = *(b+i);
    }

    // Iterating over the rest of members of longer array
    for(int j = 2*i; (i < numberA) || (i < numberB); j++)
    {
        if(numberA>numberB) *(result+j) = *(a+(i++));
        else *(result+j) = *(b+(i++));
    }
    
    return result;
}

/***** Main Function For Testing the program :)  ******/
// int main()
// {
//     int a[100] = {7,0,4,0,7,8,4,5,6,2,10,53};
//     int b[100] = {6,7,1,4,0,10,6,2,7,43};

//    int * test = aggregator(b,a);
//     for(int i = 0; i < 22; i++)
//     {
//         printf("%d ", test[i]);
//     }
//     return 0;
// }