///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//      Part 7 "Syndrome's Laser!"       //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    unsigned int n = 0;
    scanf("%u", &n);   // Input the order of our table
    
    unsigned int content[n][n]; //Declare a 2D Array n*n for handling the table content

    // Input the table contents (values):
    for(int row = 0; row < n; row++)
        for(int col = 0; col < n; col++)
            scanf("%d", &content[row][col]);
    

    // Calculate different paths
    unsigned int greatest_sum = 0, sum = 0;
    for(int start_point = 0; start_point < n - 1; start_point++)
    {
        sum = 0;
        for (int row = 0, col = start_point, slope = 1;
            row < n;
            col += (slope = slope * (col<(n-1)?1:-1)),  // Mirror slope if we reach the wall (limit = n-1)
            sum += content[row++][col]);
        if(sum > greatest_sum) greatest_sum = sum;

        sum = 0;
        for (int row = 0, col = n-1-start_point, slope = -1;
            row < n;
            col += (slope = slope * (col>0?1:-1)),  // Mirror slope if we reach the wall (limit = 0)
            sum += content[row++][col]);
        if(sum > greatest_sum) greatest_sum = sum;
    }

    printf("%d", greatest_sum); // print the output.
    return 0;
}