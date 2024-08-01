///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//  Part 4 "Bob is about to be fired!"   //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    unsigned int base = 0, m = 0; // 2 ≤ base ≤ 10    ,     1 ≤ m ≤ base

    // n is temporarily our input! so it has to be big enough to handle 10⁵ in binary form (≈20 digit)
    unsigned long int n = 0; // 2⁶⁴ - 1 ≈ (10³)⁶ ≈ (10)¹⁸  (it seems to be enough :))

    // Scan the first input (base)
    scanf("%u ", &base);

    // Scaning the number n in char[] fromat
    // Input loop: we receive input, until we get CR or LF or NULL or Space
    // At the same time, we covert it to the number
    for(int i = 0;; i++)
    {
        char digit = 0;
        scanf("%c", &digit); // Scan one character
        
        // If we got CR'\r' or LF'\n' or NULL'\0' oe Space
        if(digit=='\r' || digit=='\n' || digit=='\0' || digit==' ')
        {
            break; // break the input loop
        }

        n *= 10;
        n += (unsigned long int) (digit - '0');
    }

    // Scan the number m
    scanf("%u", &m);
    
    unsigned int a[m]; //Declare an array for save input (m) digits 
    for(int i = 0; i < m; i++) scanf("%d", &a[i]); // Input (m) digits

    // Convert n to base10
    unsigned int actual_n = 0;
    for(int p = 1; n>0; n/=10, p*=base) actual_n += p*(n%10);

    //Loop : From 1 to actual_n  : checking mods
    for(unsigned int i = 1; i <= actual_n; i++)
    {
        if(actual_n % i == 0)  // i is a divisor of actual_n
        {
            unsigned long int divisor_in_base = 0; // This is our printing number (divisor_in_base)
            int all_digits_ok = 1;  // Declare Flag, we assume all digits are ok!
            // Convert the i (divisor) to base , Same time, Checking the Digits
            for(unsigned long int ii = i, p = 1; ii > 0; ii/=base, p*=10)
            {
                int digit = ii%base; // current digit in converted base
                divisor_in_base += digit*p; // related to make the converted base number

                // Linear Searching the digit 
                int is_found = 0;  // Declare flag, We assume it doesn't found.
                for(int j = 0; j < m; j++) // Iterate our series (a[0] to a[m-1])
                    if(a[j]==digit) 
                    {
                        // Found!! set flag, and break the linear search loop.
                        is_found = 1;
                        break;
                    }
                
                if(!is_found) // If current digit not found, It's enough to skip the divisor !
                {
                    all_digits_ok = 0; // Disable the flag of the divisor
                    break; // It is not worth continuing on digits of this divisor!
                }
            }
            // If the Divisor was ok, print it ! :)
            if(all_digits_ok) printf("%lu\n", divisor_in_base);
        }
    }
    return 0;
}