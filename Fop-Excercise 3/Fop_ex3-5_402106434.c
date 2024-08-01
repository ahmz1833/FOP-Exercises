///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//        Part 5 "Dash' Ponezes!"        //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    unsigned int number = 0, prime_count = 0;
    scanf("%d", &number);   // Input the number :)

    // Iterate from 2 to N , checking divisiblity (count prime divisors)
    for(int i = 2, temp = number; i <= temp; i++)
        if(temp % i == 0) // if divisable
        {
            // because of below line, we count only the prime divisors :)
            while(temp % i == 0) temp /= i; // Actually, we remove the multiples of the divisor from the number
            prime_count++;
        }
    
    unsigned int prime_exp[prime_count];  // Declare an array to save the power of each prime divisor.
    for(int i = 2, prime_index = 0, temp = number; i <= temp; i++)
        if(temp % i == 0)
        {
            // At this stage, we count many times we remove the prime divisor (i) from the temp number.
            // That is its power (i^count)
            for(prime_exp[prime_index] = 0; temp % i == 0; prime_exp[prime_index]++, temp /= i);

            prime_index++;
        }
    
    // Here, We checking the palindrome !
    // First, we Declare a flag and assume it's 1 :)   (Unless proven otherwise :))
    int palindrome_flag = 1;

    // prime_count is even -> Iterate from 0 to (prime_count/2 - 1)
    // prime_count is odd -> Iterate from 0 to ((prime_count-1)/2 - 1)
    for(int i = 0; (prime_count%2 == 0) ? (i < prime_count/2) : (i < (prime_count-1)/2); i++)
    {
        //if is not palindrome -> flag = 0
        if(prime_exp[i] != prime_exp[prime_count-1-i])
            palindrome_flag = 0;
    }

    // Print Outputs
    printf("%d\n", prime_count);
    if(palindrome_flag) printf("YES");
    else printf("NO");

    return 0;
}