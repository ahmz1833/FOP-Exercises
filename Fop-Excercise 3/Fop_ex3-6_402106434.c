///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//Part 6 "The Incredibles Moneylessness!"//
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    unsigned long long n = 0;   // the price
    unsigned int m = 0,  // m : max number of papermoney
        t = 0;  //  t : number of different types of papermoney

    scanf("%lu", &n);  // Input the price (in first line)
    scanf("%u", &m);   // Input the max number of papermoney (in second line)
    scanf("%u", &t);   // Input the number of types (in third line)

    // We have to input (t) line and save them !!
    unsigned long long bit_Array = 0; // This is trick for not using array :)
    // Input Loop : Iterate (t) times, to get (t) inputs.
    for(int i = 0; i < t; i++)
    {
        unsigned int temp = 0;
        scanf("%d", &temp);

        // In this trick, we consider each input as a bit number, and turn 1 that bit in bit_array!
        bit_Array |= 1ULL << temp;  // 1ULL = 1 as unsigned long long
    }

    unsigned int used_papermoney = 0;
    // Iterate from greatest bit to bit 0 
    for(int i = 63; (i >= 0); i--)
    {
        unsigned long long this_papermoney = 1ULL << i; // calculate the value of this papermoney
        
        if(bit_Array & this_papermoney) // and check , Do we have this papermoney??
        {
            // We pay as much as possible from this papermoney
            // Why? because we started with the greatest papermoney.
            // And bigger bills are multiples of smaller bills.
            int temp = n / this_papermoney;
            used_papermoney += temp;
            n -= (this_papermoney*temp);

            // If we exceed papermoey limits, or we paid the money, Break Loop; 
            if(used_papermoney >= m || n==0) break;
        }
    }

    // if we paid the price, and used papermoney <= max:
    int ok_flag = (n==0) && (used_papermoney <= m);
    printf("%d", ok_flag);  // Print the output.

    return 0;
}