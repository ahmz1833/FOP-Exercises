///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//     Part 8(1) "Martyred Heroes!"      //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    unsigned int n = 0;
    scanf("%d", &n);  // Input Number of Points

    unsigned int h[n]; // Declare an array for height of the points
    unsigned int max = 0; // For determine max height
    // Input the height of the points
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
        max = (h[i] > max) ? h[i] : max;  // If the input, greater than olders, max = it;
    }

    // Draw the chart
    for(int y = max; y >= 0; y--)
    {
        printf("%d ", y); // Print the y axis label !!

        // Scaning the X axis :) !
        for(int x = 0; x < n; x++)
        {
            if(h[x] == y) // If the Point is in our function h(x)
            {
                if(x == 0 || x == n-1) // If it's the first or last point
                {
                    printf("+ "); // It's Extermum
                }
                else if((h[x] > h[x-1]) && (h[x] > h[x+1])) // If it's greater than next and previous point
                {
                    printf("+ "); // It's Extermum (Maximum)
                }
                else if((h[x] < h[x-1]) && (h[x] < h[x+1])) // If it's less than next and previous point
                {
                    printf("+ "); // It's Extermum (Minimum)
                }
                else 
                    printf("* "); // It's a normal point in the function
            }
            else
                printf("  "); // The point is not in our function :)
        }
        printf("\n");
    }
    
    return 0;
}