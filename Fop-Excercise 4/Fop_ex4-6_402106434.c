///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//          Part 6 "Final War!"          //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

// uint and ullong for abbreviation :)
#define uint    unsigned int
#define ullong  unsigned long long

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

// Memoized Fibonachi Evaluation Funstion :)
ullong fibonacci(ullong store[], uint index)
{
    if(index <= 1) return 1;  // Base of recursive function

    // Calculate F(i-2) recursively if needed -> and store it 
    store[index-2] = (store[index-2] != 0) ? store[index-2] : fibonacci(store, index-2);

    // Calculate F(i-1) recursively if needed -> and store it
    store[index-1] = (store[index-1] != 0) ? store[index-1] : fibonacci(store, index-1);

    // Calculate F(i) -> and store it
    store[index] = store[index-2] + store[index-1];
    
    // Return F(i)
    return store[index];
}


int main()
{
    uint N = 0;
    scanf("%u", &N); // Input N (number of indexes we must read and calculate them)

    ullong mem[81]; // Use a mem to memoize fibonacci F(0) -> F(80)
    for(int i = 0; i < 81; i++) mem[i]=0; // Initialize mem with 0

    for(int i = 0; i < N; i++)
    {
        uint index = 0;
        scanf("%u", &index); //Read i (index of fibonacci)
        printf("%llu\n", fibonacci(mem, index)); // Calculate and Print F(i) 
    }
    return 0;
}