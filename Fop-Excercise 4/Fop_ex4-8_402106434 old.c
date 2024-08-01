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

/******* Prototype of RECURSIVE FUCTION goThrough() ********/
int goThrough(uint[], uint[], uint, uint, uint);

int main()
{
    scanf("%u", &N); // Scan the number N  (our cells are N*N)

    uint FB[N*N], EB[N*N];  // Number of Firebenders and Earthbenders Table

    // Input EB and FB Number Tables
    for(int i = 0; i < (N*N); i++)
        scanf("%u%u", &FB[i], &EB[i]);
    
    // Call the recursive function 'goThrough()' to reach the target 
    int result = goThrough(FB, EB, 0, 0, FB[0]); // First, get soldiers in (0,0)
    if(result != -1) printf("YES\n%d\n", result); // if it's possible -> Print YES + max soldiers
    else printf("NO\n");  // if it's impossible -> Print NO

    return 0;
}

/*********************** RECURSIVE FUCTION goThrough() ************************/
/* It goes Through the cells recursively return max soldiers in target Point. */
/*                     If it is impossible, Returns -1                        */
int goThrough(uint FB[], uint EB[], uint row, uint col, uint soldiers)
{
    uint index = row*N + col;

    // Check if Firebenders are defeated by the Earthbenders in this cell?
    if(soldiers < EB[index]) return -1;  // Firebenders Dead!

    // If Sokka and his soldiers reach the Target Point (Earthbender's King)
    if((row == N-1) && (col == N-1)) return soldiers+FB[index]; // Returns the number of firebender soldiers

    // If the Firebenders win -> get soldiers in cell (except in start point)
    if(row+col != 0) soldiers += FB[index];

    // Check below & right Cells (recursive)
    int res1 = -1, res2 = -1;
    if(row < N-1) res1 = goThrough(FB, EB, row+1, col, soldiers);
    if(col < N-1) res2 = goThrough(FB, EB, row, col+1, soldiers);

    // Return the max probable soldiers reach the target point (recursive)
    return (res1 > res2) ? res1 : res2;
}
