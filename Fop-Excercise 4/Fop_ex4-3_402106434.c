///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//        Part 3 "Native King!"          //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

/* Define Macros :) */
#define forLoop(_x)                 for(int _i = 0; _i < _x; _i++)
#define solve(op,_x1,_x2,_x3,_x4)   _x1 op _x2 op _x3 op _x4  // We must not put paranthesis!!!

int main()
{
    int n;
    scanf("%d", &n);  // Scan the n (number of later inputs)
    int max_score = -1e9;
    forLoop(n) // Iterate n times :)
    {
        char x;
        int x1, x2, x3, x4;
        scanf(" %c%d%d%d%d", &x, &x1, &x2, &x3, &x4);
        int a, b, c, d;

        a = (x1 + x2 + x3 + x4) / 4;
        b = (x1 - x2 + x3 - x4) / 4;
        c = (x1 + x2 - x3 - x4) / 4;
        d = (x1 - x2 - x3 + x4) / 4;
        int s;
        
        if(x=='+')
            s = solve(+, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);
        else if(x=='-')
            s = solve(-, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);
        else if(x=='*')
            s = solve(*, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);
        else
            s = solve(%, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);
            
        if (s > max_score)
            max_score = s;
    }
    printf("%d\n", max_score);
    return 0;
}