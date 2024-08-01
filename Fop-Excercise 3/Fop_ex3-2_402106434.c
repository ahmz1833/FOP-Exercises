///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//   Part 2 "Entrance to Adna's Home"    //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);    // input the number N (index of sequence 1≤N≤1000)

    // define the sequence storage array (index 0 is not used)
    unsigned int a[n+2];  // (n+2 because if n==1, a[2] exist)
    a[1] = 1;
    a[2] = 2;

    for(int i = 3; i <= n; i++)  // Iterate from sequence 3 to N
    {
        a[i] = 0;  // Prepare the sequence variable in array

        // a[i] = Sigma{j=⌊i/2⌋, i-1}(a[j])
        for(int j = i/2; j < i; j++)  a[i] = (a[i]+a[j])%10000;
        // Important Point! : We calculate in mod 10000 at every stage!!
        // so it dosn't overflow!!
    }

    printf("%u", a[n]); //Print the value (is in mod 10000 before :))

    return 0;
}