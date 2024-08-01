///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//         Part 7 "Story! ..."           //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

// uint and ullong for abbreviation :)
#define uint    unsigned int
#define ullong  unsigned long long

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

uint n = 0;

/**** Function Story -> Find And print the array of signs we need *****/
int story(int array[], int signs[], uint startIndex, uint length, int target)
{
    // Illegal Input argument
    if(length == 0) return 0;

    // Base of Recursive Function
    if(length == 1)
    {
        // determine the last number sign (if possible)
        if(target == array[startIndex]) signs[startIndex] = '+';
        else if(target == -array[startIndex]) signs[startIndex] = '-';
        else return 0; // if it's impossible -> Not OK!

        /* Print signs in this last stage of an answer !! No need to sort*/
        /* Because we first call recursively with + , then with - ; (in each stage line 42 to 48) */
        for(int i = 0 ; i < n; i++) printf("%c", signs[i]);
        printf("\n");
        return 1; // OK
    }

    // Check : If we put this number as it's positive, we reach to target or not?
    signs[startIndex] = '+';
    int isPlus = story(array, signs, startIndex+1, length-1, target-array[startIndex]);

    // Check : If we put negative of this number, we reach to target or not?
    signs[startIndex] = '-';
    int isMinus = story(array, signs, startIndex+1, length-1, target+array[startIndex]);

    return isPlus || isMinus;
}

int main()
{
    scanf("%u", &n); // Scan the number n (number of numbers!!)

    // Declare an array for input numbers, and another array to set signs recursively
    int numbers[n], signs[n];

    // Input our a[i] numbers :)
    for(int i = 0; i < n; i++) scanf("%d", &numbers[i]);

    // Scan our target :)
    int r = 0;
    scanf("%d", &r);

    // Story :)
    story(numbers, signs, 0, n, r);

    // (We don't need to print anything in the main)
    // (The recursive function 'story()' when reaches the target, print all signs)
    // We don't need to sort result :) , Because of configuration of calling recursive function.

    return 0;
}