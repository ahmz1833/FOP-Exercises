///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//        Part 8 "Prison Break!"         //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

// uint and ullong for abbreviation :)
#define uint    unsigned int
#define ullong  unsigned long long

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

uint N = 0;

/******* Prototype of RECURSIVE FUCTION checkMaxSoldiers() ********/
int checkMaxSoldiers(int[], int[], int[], uint, uint);

int main()
{
    scanf("%u", &N); // Scan the number N  (our cells are N*N)

    int FB[N*N], EB[N*N];  // Number of Firebenders and Earthbenders Table
    int mem[N*N]; // Declare an array for memoize function checkMaxSoldiers()

    // Input EB and FB Number Tables
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            {
                scanf("%u%u", &FB[i*N + j], &EB[i*N + j]);
                mem[i*N + j] = -2;
            }
    
    // Call the recursive function 'checkMaxSoldiers()' in the taget point !
    int result = checkMaxSoldiers(mem, FB, EB, N-1, N-1);
    if(result != -1) printf("YES\n%d\n", result); // if it's possible -> Print YES + max soldiers
    else printf("NO\n");  // if it's impossible -> Print NO

    return 0;
}

/******************* RECURSIVE FUCTION checkMaxSoldiers() *********************/
/* It goes Through the cells recursively return max soldiers in target Point. */
/*                     If it is impossible, Returns -1                        */
int checkMaxSoldiers(int mem[], int FB[], int EB[], uint row, uint col)
{
    uint index = row*N + col;

    // ‌Base of the recursive function : if we are checking the start point !
    if(index == 0) return FB[0]; // Return the default firebenders in start point

    // Checking routes to our cell (the left cell / the top cell)
    // Determine How many soldiers (max) reach to current cell
    // If they win? or lose?
    int res1 = -1, res2 = -1;
    if(col > 0) // If we don't reach the left wall
    {
        // Check if we need to check max soldiers in the left cell (recursively)
        if(mem[index-1] == -2) mem[index-1] = checkMaxSoldiers(mem, FB, EB, row, col-1);

        // Check if the firebenders win? -> res = total soldiers //// lose? -> res = -1
        res1 = (mem[index-1] >= EB[index]) ? (mem[index-1] + FB[index]) : -1;
    }
    if(row > 0) // If we don't reach the top wall
    {
        // Check if we need to check max soldiers in the top cell (recursively)
        if(mem[index-N] == -2) mem[index-N] = checkMaxSoldiers(mem, FB, EB, row-1, col);

        // Check if the firebenders win? -> res = total soldiers //// lose? -> res = -1
        res2 = (mem[index-N] >= EB[index]) ? (mem[index-N] + FB[index]): -1;
    }

    // return the max of res1 , res2
    return  (res1 > res2) ? res1 : res2;
}