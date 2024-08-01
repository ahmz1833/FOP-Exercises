#include <stdio.h>
#include <stdlib.h>
//#include "grader.h"

int arrayNum(int* a);

#define putItemInArray(array,counter,item)   *(array+(counter)) = item;

/**** Function aggregator : Important and main of program ****/
int* aggregator(int* a, int* b)
{
    int numberA = arrayNum(a), numberB = arrayNum(b);

    int finalLength = numberA + numberB;
    int* result = (int*) malloc(finalLength*sizeof(int));

    int index = 0, counterA = 0, counterB = 0;
    while (index < finalLength)
    {
        if(counterA < numberA) putItemInArray(result, index++, *(a+(counterA++)));
        if(counterB < numberB) putItemInArray(result, index++, *(b+(counterB++)));
    }
    return result;
}

int arrayNum(int* a)
{
    long long prevSum = 0;

    // Related to strange test cases !! (If we were given 0 in index 0 -> Length = 1)
    if(*a == 0) return 1;
    
    for(int i = 0; i < 999; i++)
    {
        // Situation of end of array :
        // If sum of members, from first to current i, equals with member of index i+1
        // Then, the array length is (i+2)   (In another words, next member is last member)
        prevSum += *(a+i);
        if(prevSum == *(a+i+1)) return i+2;
    }
    return 1;
}

/***** Main Function For Testing the program :)  ******/
int main()
{
    int a[100] = {7,0,4,0,7,8,4,5,6,2,10,53};
    int b[100] = {6,7,1,4,0,10,6,2,7,43};

   int * test = aggregator(b,a);
    for(int i = 0; i < 22; i++)
    {
        printf("%d ", test[i]);
    }
    return 0;
}